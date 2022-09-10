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

#define int ll
const int mod = 998244353;
const int N = 3e5+7;

int n, ans;

int vis[N];

int dp[N][4];

VI G[N];

void dfs(int v)
{
	vis[v] = 1;
	dp[v][0] = 1;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dfs(it);
			
			int t0 = dp[v][0];
			int t1 = dp[v][1];
			int t2 = dp[v][2];
			//int t3 = dp[v][3];

			int zostaw = (dp[it][0]+dp[it][1])%mod;

			dp[v][0] = t0*zostaw%mod;
			dp[v][1] = (t1*(zostaw+dp[it][1]) + (t0+t2)*(dp[it][2]+dp[it][0]))%mod;
			dp[v][2] = (t2*(zostaw+dp[it][1]) + t0*(dp[it][1]))%mod;

			//debug(I(v), I(dp[v][0]), I(dp[v][1]), I(dp[v][2]));
		}
	}


}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	int r = 1;

	dfs(r);

	//cout << (dp[r][0]+dp[r][1]+dp[r][3])%mod << endl;
	cout << (dp[r][0]+dp[r][1])%mod << endl;
}