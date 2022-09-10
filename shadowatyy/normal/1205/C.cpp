#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll long long
#define st f
#define nd s
#define pb PB
#define eb emplace_back
#define mp make_pair				
#define siz(c) SIZ(c)
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;
 
#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "

#ifndef LOCAL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#else
#include</Users/dawid/algo/mac/ordered_set>
#endif

const int N = 53;

int n;

int rep[N*N];

VPII G[N*N];

int nr(int x, int y)
{
	return n*(x-1)+y;
}

struct ans
{
	int vis[N*N];
	int a[N*N];
	int dp[N][N][N][N];

	void dfs(int v)
	{
		vis[v] = 1;

		for(auto it:G[v])
		{
			if(!vis[it.st])
			{
				a[it.st] = a[v]^a[it.nd];
				dfs(it.st);
			}
		}
	}

	bool depe(int x1, int y1, int x2, int y2)
	{
		if(dp[x1][y1][x2][y2]!=-1)
			return dp[x1][y1][x2][y2];

		if(x1>x2 || y1>y2)
			return (dp[x1][y1][x2][y2] = 0);

		int d = x2-x1+y2-y1;

		if(d==0)
		{
			dp[x1][y1][x2][y2] = 0;
		}
		else if(d==1)
		{
			dp[x1][y1][x2][y2] = (a[nr(x1, y1)]==a[nr(x2, y2)]);
		}
		else
		{
			if(a[nr(x1, y1)]==a[nr(x2, y2)])
			{
				dp[x1][y1][x2][y2] = 
				(depe(x1+1, y1, x2-1, y2) || 
				depe(x1+1, y1, x2, y2-1) || 
				depe(x1, y1+1, x2-1, y2) || 
				depe(x1, y1+1, x2, y2-1));
			}
			else
				dp[x1][y1][x2][y2] = 0;
		}

		return dp[x1][y1][x2][y2];
	}

	void wypisz()
	{
		cout << "!" << endl; 

		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				cout << a[nr(i, j)];
			}

			cout << endl;
		}

		fflush(stdout);
		exit(0);
	}

	ans()
	{
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < N; ++j)
			{
				for(int k = 0; k < N; ++k)
				{
					for(int l = 0; l < N; ++l)
					{
						dp[i][j][k][l] = -1;
					}
				}
			}
		}
	}
};

int Find(int a)
{
	if(rep[a]!=a)
		rep[a] = Find(rep[a]);

	return rep[a];
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	rep[a] = b;
}

bool ins(int x, int y)
{
	return 1<=x && x<=n && 1<=y && y<=n;
}

int query(int x1, int y1, int x2, int y2)
{
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	fflush(stdout);
	int ans;
	cin >> ans;
	return ans;
}

void krawedz(int x1, int y1, int x2, int y2)
{
	int n1 = nr(x1, y1);
	int n2 = nr(x2, y2);

	if(ins(x2, y2) && Find(n1)!=Find(n2))
	{
		Union(n1, n2);

		if(query(x1, y1, x2, y2))
		{
			G[n1].eb(n2, 0);
			G[n2].eb(n1, 0);
		}
		else
		{
			G[n1].eb(n2, 1);
			G[n2].eb(n1, 1);
		}
	}
}

int32_t main()
{
	cin >> n;

	for(int i = 1; i <= n*n; ++i)
	{
		rep[i] = i;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			krawedz(i, j, i, j+2);
			krawedz(i, j, i+1, j+1);
		}
	}

	ans A1, A2;
	A1.a[1] = A2.a[1] = 1;
	A1.a[2] = 1;
	A2.a[2] = 0;

	A1.dfs(1);
	A1.dfs(2);
	A2.dfs(1);
	A2.dfs(2);

	for(int x1 = 1; x1 <= n; ++x1)
	{
		for(int y1 = 1; y1 <= n; ++y1)
		{
			for(int x2 = x1; x2 <= n; ++x2)
			{
				for(int y2 = y1; y2 <= n; ++y2)
				{
					int d = abs(x1-x2)+abs(y1-y2);
					int p1 = A1.depe(x1, y1, x2, y2);
					int p2 = A2.depe(x1, y1, x2, y2);

					if(d>=2 && p1!=p2)
					{
						if(query(x1, y1, x2, y2)==p1)
							A1.wypisz();
						else
							A2.wypisz();
					}
				}
			}
		}
	}

}