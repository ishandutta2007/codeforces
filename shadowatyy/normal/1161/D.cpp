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

const int mod = 998244353;
const int N = 2007;

int m, ans;

bool zle;

string s;

VPII G[N];

int col[N];

int w1[N];
int w2[N];

void dfs(int v)
{
	for(auto it:G[v])
	{
		int u = it.st;
		int chce = col[v] ^ it.nd;

		if(col[u] == -1)
		{
			col[u] = chce;
			dfs(u);
		}
		else
		{
			if(col[u] != chce)
				zle = 1;
		}
	}
}

void solve(int len)
{	
	zle = 0;
	memset(w1, 0, sizeof w1);
	memset(w2, 0, sizeof w2);

	for(int i = 1; i <= 2*m; ++i)
	{
		col[i] = -1;
		G[i].clear();
	}

	int cnt = 0;

	for(int i = 1; i <= (m+1)/2; ++i)
	{
		w1[i] = w1[m-i+1] = ++cnt;
	}

	for(int i = 1; i <= (len+1)/2; ++i)
	{
		w2[i] = w2[len-i+1] = ++cnt;
	}

	for(int i = 1; i <= len; ++i)
	{
		if(s[i] == '1')
		{
			G[w1[i]].eb(w2[i], 1);
			G[w2[i]].eb(w1[i], 1);
			debug(w1[i], w2[i], 1);
		}
		else if(s[i] == '0')
		{
			G[w1[i]].eb(w2[i], 0);
			G[w2[i]].eb(w1[i], 0);
			debug(w1[i], w2[i], 0);
		}
	}

	for(int i = m; i >= len+1; --i)
	{
		if(s[i] == '?')
			continue;

		int chce = s[i] - '0';

		if(col[w1[i]] == -1)
		{
			col[w1[i]] = chce;
			dfs(w1[i]);
		}
		else
		{
			if(col[w1[i]] != chce)
				zle = 1;
		}
	}
	
	col[w2[len]] = 1;
	dfs(w2[len]);

	int ile = 1;

	for(int i = 1; i <= cnt; ++i)
	{
		if(col[i] == -1)
		{
			col[i] = 1;
			dfs(i);
			ile *= 2;
			ile %= mod;
		}
	}

	if(!zle)
	{
		ans += ile;
		ans %= mod;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	reverse(ALL(s));
	m = siz(s);
	s = '#' + s;

	//solve(1);

	for(int i = 1; i < m; ++i)
	{
		solve(i);
	}

	cout << ans << endl;
}