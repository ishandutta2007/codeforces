#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define VPII vector<PII>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

#define Sim template <class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{ return p << "<" << x.first << ", " << x.second << ">"; }
Sim> auto operator << (ostream &p, n y) -> 
typename enable_if <!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{ int o = 0; p << "{"; for(auto c: y) { if(o++) p << ", "; p << c; } return p << "}"; }
void dor() { cerr << endl; }
Sim, class...s> void dor(n p, s...y) { cerr << p; dor(y...); }
Sim, class s> void mini(n &p, s y) { if(p > y) p = y; }
Sim, class s> void maxi(n &p, s y) { if(p < y) p = y; }
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "

const int N = 101;

int n, ans, rozne;

int a[N];
int cnt[N];
bitset<N> ple[N][N*N];

void add(int w, int x)
{
	for(int i = x-1; i >= 0; --i)
	{
		for(int j = i*100; j >= 0; --j)
		{
			if(ple[i][j].any() || (i+j==0))
			{
				ple[i+1][j+w] |= ple[i][j];
				ple[i+1][j+w][w] = 1;
			}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		add(a[i], i);

		if(++cnt[a[i]]==1)
			++rozne;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= 100; ++j)
		{
			if(ple[i][i*j].count()==1 && ple[i][i*j][j])
			{
				if(cnt[j]==i)
				{
					if(rozne<=2)
						ans = max(ans, n);
					else
						ans = max(ans, i);
				}
				else
				{
					if(rozne==1)
						ans = max(ans, n);
					else
						ans = max(ans, i);
				}
			}
		}
	}
	
	cout << ans << endl;
}