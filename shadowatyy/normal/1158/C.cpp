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

#define next aafdssd
const int N = 1 << 19;

int t, n;

int load[2 * N];
PII sub[2 * N];

VPII G[N];

int next[N];
int ans[N];

bitset<N> vis;

void update(int v, int c)
{
	sub[v].st += c;
	load[v] += c;
}

void merge(int v)
{
	sub[v] = min(sub[2*v], sub[2*v+1]);
	sub[v].st += load[v];
}

void insert(int a, int b, int c, int v = 1, int l = 0, int r = N - 1)
{
	if(a > r || l > b)
		return;

	if(a <= l && r <= b)
	{
		update(v, c);
		return;
	}

	int mid = (l+r)/2;
	insert(a, b, c, 2*v, l, mid);
	insert(a, b, c, 2*v+1, mid+1, r);
	merge(v);
}

void clear()
{
	for(int i = 1; i <= n; ++i)
	{
		vis[i] = 0;
		G[i].clear();
	}
}

void rebuild(int a, int b, int v = 1, int l = 0, int r = N-1)
{
	if(a > r || l > b)
		return;

	load[v] = 0;

	if(l == r)
	{
		sub[v] = mp(0, v-N);
		return;
	}

	rebuild(a, b, 2*v, l, (l+r)/2);
	rebuild(a, b, 2*v+1, (l+r)/2+1, r);
	merge(v);
}
void solve()
{
	cin >> n;

	insert(0, 0, inf);
	insert(n+1, N-1, inf);

	for(int i = 1; i <= n; ++i)
	{
		cin >> next[i];

		if(next[i] == -1)
			continue;
		else if(next[i] == n+1)
			G[i].eb(i+1, n);
		else
		{
			G[i].eb(i+1, next[i]-1);
			G[next[i]].eb(i, i);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(auto it:G[i])
		{
			insert(it.st, it.nd, 1);
		}
	}

	VI topo;

	while(sub[1].st==0)
	{
		int v = sub[1].nd;
		insert(v, v, inf);
		topo.pb(v);
		vis[v] = 1;

		for(auto it:G[v])
		{
			insert(it.st, it.nd, -1);
		}
	}

	if(siz(topo)!=n)
		cout << -1 << endl;
	else
	{
		reverse(ALL(topo));

		for(int i = 0; i < n; ++i)
		{
			ans[topo[i]] = i+1;
		}

		for(int i = 1; i <= n; ++i)
		{
			cout << ans[i] << " ";
		}

		cout << endl;
	}

	/*for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			for(auto it:G[i])
			{
				insert(it.st, it.nd, -1);
			}
		}
		else
			insert(i, i, -inf);
	}*/
	rebuild(1, n);

	insert(0, 0, -inf);
	insert(n+1, N-1, -inf);
	clear();
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 0; i < N; ++i)
	{
		sub[i+N].nd = i;
	}

	for(int i = N-1; i >= 1; --i)
	{
		merge(i);
	}

	cin >> t;

	while(t--)
		solve();
}