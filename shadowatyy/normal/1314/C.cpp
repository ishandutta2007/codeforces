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

int n, m, k;

string s;

vector<pair<string, int> > suf;

VPII subs;

int pos[N];
int seg[N][N];
int con[N];
int lcp[N];

int dp[N][N];

void clear()
{
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			dp[i][j] = 0;
		}
	}
}

void solve(int ban)
{
	clear();

	for(int i = 1; i <= n; ++i)
	{
		con[i] = 1;
	}

	for(int i = 0; i < ban; ++i)
	{
		int ind = subs[i].st;
		int len = subs[i].nd - ind + 1;
		maxi(con[ind], len + 1);
	}

	dp[1][con[1]] = 1;

	for(int l = 1; l <= m; ++l)
	{
		for(int i = 1; i < n; ++i)
		{
			dp[l][i+1] += dp[l][i];
			mini(dp[l][i+1], INF);
			dp[l+1][i+con[i+1]] += dp[l][i];
			mini(dp[l+1][i+con[i+1]], INF);
		}
	}
}

bool comp(PII a, PII b)
{
	int x = pos[a.st];
	int y = pos[b.st];

	if(x==y)
		return a.nd < b.nd;

	if(x>y)
		swap(x, y);

	int l = seg[x][y-1];

	if(l < min(a.nd-a.st+1, b.nd-b.st+1))
		return pos[a.st]<pos[b.st];
	else
		return a.nd-a.st+1 < b.nd-b.st+1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k >> s;

	s = '#' + s;

	for(int i = 1; i <= n; ++i)
	{
		suf.eb(s.substr(i, inf), i);
	}

	sort(ALL(suf));

	debug(siz(suf));

	for(int i = 0; i < n; ++i)
	{
		pos[suf[i].nd] = i;

		if(i==n-1)
			continue;

		while(lcp[i] < min(siz(suf[i].st), siz(suf[i+1].st)) && suf[i].st[lcp[i]]==suf[i+1].st[lcp[i]])
			++lcp[i];
	}

	for(int i = 0; i < n; ++i)
	{
		seg[i][i] = lcp[i];
	}

	for(int len = 2; len <= n; ++len)
	{
		for(int i = 1; i + len - 1 <= n; ++i)
		{	
			int j = i + len - 1;
			seg[i][j] = min(seg[i][j-1], lcp[j]);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; ++j)
		{
			subs.eb(i, j);
		}
	}

	sort(ALL(subs), comp);

	debug(s, subs);

	int l = 0, r = siz(subs)-1;

	while(l<r)
	{
		int mid = (l+r)/2;

		if(l==mid)
			++mid;

		solve(mid);

		if(dp[m][n] < k)
			r = mid-1;
		else
			l = mid;
	}

	solve(-1);
	debug(dp[m][n]);
	solve(1);
	debug(dp[m][n]);
	debug(l);
	auto ans = subs[l];
	int len = ans.nd - ans.st + 1;
	cout << s.substr(ans.st, len) << endl;
}