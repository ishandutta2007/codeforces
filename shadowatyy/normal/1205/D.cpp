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

#define int ll
const int N = 1007;

int n;

VI G[N];

int a[N];
int b[N];
int sub[N];
int max_sub[N];
int dp[N];
int skad[N];
int wez[N];
int vis[N];

map<PII, int> ans;

void dfs(int v)
{
	sub[v] = 1;

	for(auto it:G[v])
	{
		if(!sub[it])
		{
			dfs(it);
			sub[v] += sub[it];
			maxi(max_sub[v], sub[it]);
		}
	}
}

void solve(int v, int mul)
{
	vis[v] = 1;

	int mam = 0;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			ans[mp(v, it)] = mul*(mam+1);
			solve(it, mul);
			mam += sub[it];
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
		cin >> a[i] >> b[i];
		G[a[i]].pb(b[i]);
		G[b[i]].pb(a[i]);
	}

	dfs(1);

	int c = 1;

	for(int v = 1; v <= n; ++v)
	{
		maxi(max_sub[v], n-sub[v]);

		if(max_sub[v]<max_sub[c])
			c = v;
	}

	memset(sub, 0, sizeof sub);

	dfs(c);

	dp[0] = 1;

	for(auto it:G[c])
	{
		int val = sub[it];

		for(int i = N-1; i >= val; --i)
		{
			if(dp[i-val] && !dp[i])
			{
				dp[i] = 1;
				skad[i] = val;
			}
		}
	}

	int ile = -1;
	int wyn = inf;

	for(int i = 0; i <= n; ++i)
	{
		if(dp[i] && wyn>abs(i-(n-i)))
		{
			wyn = abs(i-(n-i));
			ile = i;
		}
	}

	int curr = ile;

	while(curr)
	{
		int teraz = skad[curr];

		for(auto it:G[c])
		{
			if(sub[it]==teraz && !wez[it])
			{
				wez[it] = 1;
				curr -= teraz;
				break;
			}
		}
	}

	vis[c] = 1;
	
	int mam = 0;

	for(auto it:G[c])
	{
		if(wez[it])
		{
			ans[mp(c, it)] = mam+1;
			solve(it, 1);
			mam += sub[it];
		}
	}

	mam = 0;

	for(auto it:G[c])
	{
		if(!wez[it])
		{
			ans[mp(c, it)] = (ile+1)*(mam+1);
			solve(it, ile+1);
			mam += sub[it];
		}
	}

	for(int i = 1; i < n; ++i)
	{
		cout << a[i] << " " << b[i] << " ";

		if(ans.count(mp(a[i], b[i])))
			cout << ans[mp(a[i], b[i])] << endl;
		else
			cout << ans[mp(b[i], a[i])] << endl;
	}
}