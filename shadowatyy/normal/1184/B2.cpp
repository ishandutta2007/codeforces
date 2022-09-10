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

struct matching 
    {
    int n;
    vector<VI> V;
    vector<bool> odw;
    VI para;
    VI strona;
    
    matching(int n) : n(n) // zakadam numeracje od 1, nie moe by 0
        {
        V.resize(n+1);
        odw.resize(n+1);
        para.resize(n+1);
        }
    void addedge(int a, int b) // zakadam e a jest z lewej, b z prawej
        {
        V[a].PB(b);
        strona.PB(a);
        }
    bool skojarz(int x)       // x naley do strona
        {
        odw[x] = 1;
        for(auto v : V[x])
            if(!para[v] || (!odw[para[v]] && skojarz(para[v])))
                {
                para[v] = x;
                para[x] = v;
                return 1;
                }
        return 0;
        }
    VPII go()
        {
        sort(ALL(strona)); strona.resize(unique(ALL(strona))-strona.begin());
        
        REP(i, n+1)
            random_shuffle(ALL(V[i]));
        sort(ALL(strona), [&](int a, int b){return V[a].size()<V[b].size();});
        
        
        bool ok = 0;
        do
          {
          ok = 0;
          for(auto i : strona)odw[i] = 0;
          for(auto i : strona)
            if(!para[i] && skojarz(i))
              ok = 1;
          }
        while(ok);

        VPII res;
        for(auto i : strona)
            if(para[i])
                res.PB(MP(i, para[i]));
        return res;
        }
    };

const int N = 107;
const int S = 1007;

int n, m, s, b, k, h;

int dist[N][N];

int x[S];
int f[S];
int a[S];

int y[S];
int d[S];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(i==j)
				dist[i][j] = 0;
			else
				dist[i][j] = inf;
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		int x, y;
		cin >> x >> y;
		dist[x][y] = dist[y][x] = min(dist[x][y], 1);
	}

	cin >> s >> b >> k >> h;

	for(int i = 1; i <= s; ++i)
	{
		cin >> x[i] >> a[i] >> f[i];
	}

	for(int i = 1; i <= b; ++i)
	{
		cin >> y[i] >> d[i];
	}

	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}

	matching M(s+b);

	for(int i = 1; i <= s; ++i)
	{
		for(int j = 1; j <= b; ++j)
		{
			if(f[i]>=dist[x[i]][y[j]] && a[i]>=d[j])
				M.addedge(i, s+j);
		}
	}

	int sko = siz(M.go());
	int wolne = s-sko;
	ll curr = (ll)k*sko;
	ll ans = curr;

	for(int i = 1; i <= s; ++i)
	{
		curr += h;

		if(wolne)
			--wolne;
		else
		{
			--sko;
			curr -= k;
		}

		ans = min(ans, curr);
	}

	cout << ans << endl;
}