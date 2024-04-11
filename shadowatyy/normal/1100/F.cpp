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

const int N = 1<<20;

int bit[N];

struct gauss
{
	VI curr;

	void add(int x)
	{
		for(auto it:curr)
		{
			if(x&bit[it])
				x ^= it;
		}

		if(x)
		{
			for(auto &it:curr)
			{
				if(it&bit[x])
					it ^= x;
			}	

			curr.pb(x);
		}
	}

	void merge(gauss &sec)
	{
		for(auto it:sec.curr)
		{
			add(it);
		}
	}

	int ask()
	{
		sort(ALL(curr));
		reverse(ALL(curr));

		int ans = 0;

		for(auto it:curr)
			ans = max(ans, ans^it);

		return ans;
	}
};

int n, q;

int t[N];
int l[N];
int r[N];
int ans[N];

gauss g[N];

void solve(int a, int b, VI que)
{
	if(que.empty())
		return;

	int m = (a+b)/2;

	for(int i = a; i <= b; ++i)
	{
		g[i] = gauss();
	}

	g[m].add(t[m]);

	for(int i = m+1; i <= b; ++i)
	{
		g[i] = g[i-1];
		g[i].add(t[i]);
	}

	for(int i = m-1; i >= a; --i)
	{
		g[i] = g[i+1];
		g[i].add(t[i]);
	}

	VI L, R;

	for(auto it:que)
	{
		if(r[it]<m)
			L.pb(it);
		else if(m<l[it])
			R.pb(it);
		else
		{
			gauss foo = g[l[it]];
			foo.merge(g[r[it]]);
			ans[it] = foo.ask();
		}
	}

	solve(a, m-1, L);
	solve(m+1, b, R);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 1; i < N; ++i)
	{
		bit[i] = 1<<(31-__builtin_clz(i));
	}

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];
	}

	cin >> q;

	VI que;

	for(int i = 1; i <= q; ++i)
	{
		cin >> l[i] >> r[i];
		que.pb(i);
	}

	solve(1, n, que);

	for(int i = 1; i <= q; ++i)
	{
		cout << ans[i] << endl;
	}
}