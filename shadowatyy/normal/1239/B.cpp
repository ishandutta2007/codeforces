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
#define endl '\n'
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

const int N = 3e5+7;

int n;

string s;

int a[N];
int zly[N];
int ok[N];
int trzeba[N];

int bans, bl, br;

int ile_zly(int a, int b)
{
	return zly[b]-(a==0?0:zly[a-1]);
}

int ile_ok(int a, int b)
{
	return ok[b]-(a==0?0:ok[a-1]);
}

int ile_trzeba(int a, int b)
{
	return trzeba[b]-(a==0?0:trzeba[a-1]);
}

VI kon, poc;

void solve1(int ind)
{
	kon.clear();

	memset(a, 0, sizeof a);
	memset(zly, 0, sizeof zly);
	memset(ok, 0, sizeof ok);

	int mam = 0;
	int curr = 0;

	for(int i = 0; i < n; ++i)
	{
		if(s[(i+ind)%n]=='(')
			++curr;
		else
		{
			--curr;
			kon.pb(i);
		}

		if(!curr)
			++mam;

		if(curr<2)
			zly[i+1] = 1;

		if(curr==2)
			ok[i+1] = 1;

		a[i+1] = curr;
	}

	for(int i = 0; i < n; ++i)
	{
		zly[i+1] += zly[i];
		ok[i+1] += ok[i];
	}

	int ans = mam;
	int al = 0, ar = 0;

	for(int i = 0; i < n; ++i)
	{
		if(s[(i+ind)%n]=='(')
		{
			int l = upper_bound(ALL(kon), i) - kon.begin();

			if(l!=siz(kon))
			{
				int r = siz(kon)-1;

				while(l<r)
				{
					int m = (l+r)/2;

					if(l==m)
						++m;

					if(!ile_zly(i+1, kon[m]))
						l = m;
					else
						r = m-1;
				}

				if(!ile_zly(i+1, kon[l]) && ans < mam + ile_ok(i+1, kon[l]))
				{
					ans = mam + ile_ok(i+1, kon[l]);
					al = (i+ind)%n;
					ar = (kon[l]+ind)%n;
				}
			}
		}
	}

	if(bans<ans)
	{
		bans = ans;
		bl = al;
		br = ar;
	}
}

void solve2(int ind)
{
	poc.clear();

	memset(a, 0, sizeof a);
	memset(zly, 0, sizeof zly);
	memset(ok, 0, sizeof ok);
	memset(trzeba, 0, sizeof trzeba);

	int mam = 0;
	int curr = 0;

	for(int i = 0; i < n; ++i)
	{
		if(s[(i+ind)%n]=='(')
		{
			++curr;
			poc.pb(i);
		}
		else
		{
			--curr;
		}

		if(!curr)
			++mam;

		debug(i, curr);

		if(curr==0)
			zly[i+1] = 1;

		if(curr==-2)
			ok[i+1] = 1;

		if(curr==-1)
			trzeba[i+1] = 1;

		a[i+1] = curr;
	}

	for(int i = 0; i < n; ++i)
	{
		zly[i+1] += zly[i];
		ok[i+1] += ok[i];
		trzeba[i+1] += trzeba[i];
	}

	int musze = ile_trzeba(0, n) + ile_ok(0, n);

	int ans = -inf;
	int al = 0, ar = 0;

	for(int i = 0; i < n; ++i)
	{
		if(s[(i+ind)%n]==')')
		{
			int l = upper_bound(ALL(poc), i) - poc.begin();

			if(l!=siz(poc))
			{
				int r = siz(poc)-1;

				while(l<r)
				{
					int m = (l+r)/2;

					if(ile_ok(i+1, poc[m])+ile_trzeba(i+1, poc[m])==musze)
						r = m;
					else
						l = m+1;
				}

				if(ile_ok(i+1, poc[l])+ile_trzeba(i+1, poc[l])==musze && ans < mam - ile_zly(i+1, poc[l]) + ile_ok(i+1, poc[l]))
				{
					ans = mam - ile_zly(i+1, poc[l]) + ile_ok(i+1, poc[l]);
					al = (i+ind)%n;
					ar = (poc[l]+ind)%n;
				}
			}
		}
	}

	if(bans<ans)
	{
		bans = ans;
		bl = al;
		br = ar;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> s;

	int curr = 0;
	int mn = 0;
	int ind = 0;

	for(int i = 0; i < n; ++i)
	{
		if(s[i]=='(')
			++curr;
		else
			--curr;

		if(curr<mn)
		{
			mn = curr;
			ind = i+1;
		}
	}

	if(curr)
	{
		cout << 0 << endl << 1 << " " << 1 << endl;
		exit(0);
	}

	//debug(ind);
	solve1(ind);
	solve2(ind+1);
	solve2(ind+2);
	solve2(ind-1+n);
	solve2(ind-2+n+n);

	cout << bans << endl << bl+1 << " " << br+1 << endl;
}