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

const int N = 57;

int n;

VI G[N];

LD kom[N][N][N][N];
LD bez[N][N];
LD kra[N][N]; 

int sub[N];

void merge(int v, int u)
{	
	LD tmp[N];
	memset(tmp, 0, sizeof tmp);

	for(int i = 0; i <= sub[v]; ++i)
	{
		for(int j = 0; j <= sub[u]; ++j)
		{
			tmp[i+j] += bez[v][i]*kra[u][j]*kom[sub[v]+sub[u]][i+j][sub[v]][i];
		}
	}

	memcpy(bez[v], tmp, sizeof bez[v]);
	sub[v] += sub[u];
}

void dfs(int v, int p)
{
	bez[v][0] = 1;

	for(auto u:G[v])
	{
		if(u==p)
			continue;

		dfs(u, v);
		merge(v, u);
		debug(I(u), I(kra[u][0]), I(kra[u][1]));
	}

	sub[v]++;

	if(v==1)
		debug(bez[v][0], bez[v][1], bez[v][2]);

	for(int s = 0; s <= sub[v]; ++s)
	{
		for(int wyb = 1; wyb <= sub[v]; ++wyb)
		{
			int oki = max(wyb-1, s-1);
			LD prob = 1.0/sub[v];

			if(wyb>s)
				prob /= 2;

			kra[v][s] += bez[v][oki]*prob;
		}
	}		
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j <= i; ++j)
		{
			kom[i][j][0][0] = 1;
		}
	}

	for(int i = 1; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			for(int k = 1; k < N; ++k)
			{
				for(int l = 0; l < N; ++l)
				{
					LD ok = (LD)j/i;

					if(j>0 && l>0)
						kom[i][j][k][l] += ok * kom[i-1][j-1][k-1][l-1];

					kom[i][j][k][l] += (1-ok) * kom[i-1][j][k-1][l];
				}
			}
		}
	}

	debug(kom[2][0][1][0]);

	cout << fixed << setprecision(15);

	cin >> n;

	if(n==1)
	{
		cout << 1 << endl;
		return 0;
	}

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			memset(bez[j], 0, sizeof bez[j]);
			memset(kra[j], 0, sizeof kra[j]);
		}

		memset(sub, 0, sizeof sub);
		dfs(i, -1);
		cout << bez[i][0] << endl;
	}
}