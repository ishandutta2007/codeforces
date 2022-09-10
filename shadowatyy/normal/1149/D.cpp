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

const int N = 77;

int n, m, a, b, cnt, cnt_c; 

VPII G[N];

int dist[N][1<<18];
int comp[N];
int size[N];
int ciekawa[N];
int pozycja[N];

void dfs(int v)
{
	comp[v] = cnt;
	++size[cnt];

	for(auto it:G[v])
	{
		if(it.nd == a && !comp[it.st])
			dfs(it.st);
	}
}

queue<PII> A, B;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> a >> b;

	for(int i = 1; i <= m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].eb(b, c);
		G[b].eb(a, c);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!comp[i])
		{
			debug("nowa spojna");
			++cnt;
			dfs(i);
		}
	}

	for(int i = 1; i <= cnt; ++i)
	{
		if(size[i] >= 4)
		{
			pozycja[i] = cnt_c++;
			ciekawa[i] = 1;
		}

		debug(i, ciekawa[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < 1 << cnt_c; ++j)
		{
			dist[i][j] = inf;
		}
	}

	debug(comp[1]);
	debug(comp[3]);

	int m = 0;

	if(ciekawa[comp[1]])
		m |= 1 << pozycja[comp[1]];

	dist[1][m] = 0;
	A.emplace(1, m);
	debug(m);

	while(siz(A) || siz(B))
	{
		int v = -1;
		int m = -1;

		if(B.empty())
		{
			v = A.front().st;
			m = A.front().nd;
			A.pop();
		}
		else if(A.empty())
		{
			v = B.front().st;
			m = B.front().nd;
			B.pop();
		}
		else
		{
			int va = A.front().st;
			int ma = A.front().nd;
			int vb = B.front().st;
			int mb = B.front().nd;

			if(dist[va][ma] < dist[vb][mb])
			{
				v = va;
				m = ma;
				A.pop();
			}
			else
			{
				v = vb;
				m = mb;
				B.pop();
			}
		}

		debug("teraz", v, m);

		for(auto it:G[v])
		{
			int u = it.st;
			int s = comp[u];
			int w = it.nd;

			if(ciekawa[s] && (m & (1 << pozycja[s])) && w == b)
				continue;

			if(comp[v] == comp[u] && w == b)
				continue;

			int nm = m;

			if(ciekawa[s])
				nm |= 1 << pozycja[s];

			if(dist[u][nm] > dist[v][m] + w)
			{
				debug("rel", u, nm);
				dist[u][nm] = dist[v][m] + w;

				if(w == a)
					A.emplace(u, nm);
				else
					B.emplace(u, nm);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < 1 << cnt_c; ++j)
		{
			mini(dist[i][0], dist[i][j]);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << dist[i][0] << " ";
	}

	cout << endl;
}