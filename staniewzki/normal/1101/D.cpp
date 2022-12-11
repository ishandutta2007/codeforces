#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define ST first
#define ND second
#define V vector
#define RS resize
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
#define S(a) (int)a.size()

template<class T> void db(T a) {cerr << a;}
template<class L, class R> void db(pair<L, R> a) {cerr << "(" << a.ST << ", " << a.ND << ")";}
template<class T> void db(V<T> v) 
{cerr << "{"; REP(i, S(v)) cerr << (i != 0 ? ", " : ""), db(v[i]); cerr << "}";}
template<class T> void dump(const char *s, T a) { cerr << s << ": "; db(a); cerr << "\n"; }
template<class T, class... TS> void dump(const char *s, T a, TS... x)
{ while(*s != ',') cerr<< *s++; cerr << ": "; db(a); dump(s + 1, x...); }

#ifdef DEBUG
#define DB(...) dump(#__VA_ARGS__, __VA_ARGS__); 
#else
#define DB(...)
#endif

using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;

int sz = 2e5;
VI di(sz + 1, 1);
void sieve()
{
	for(int i = 2; i <= sz; i++)
	{
		if(di[i] == 1)
		{
			di[i] = i;
			for(int j = i * 2; j <= sz; j += i)
				di[j] = i;
		}
	}	
}

void get_primes(VI &primes, int val)
{
	while(val != 1)
	{
		if(primes.empty() || primes.back() != di[val])
			primes.EB(di[val]);
		val /= di[val];
	}
}

VVI g;
VI val;
int ans = 0;
V<bool> blocked;

VI size;
int centr;
bool find_centroid_dfs(int v, int s, int p = -1)
{
    size[v] = 1;
    bool is_centroid = true;
    REP(i, S(g[v]))
    {
        int u = g[v][i];
        if(p != u && !blocked[u])
        {
            if(find_centroid_dfs(u, s, v))
				return 1;

            size[v] += size[u];
            if(size[u] * 2 > s)
                is_centroid = false;
        }
    }

    if((s - size[v]) * 2 > s)
        is_centroid = false;
	if(is_centroid)
		centr = v;
	
	return centr != -1;
}

int find_centroid(int v)
{
	centr = -1;
    find_centroid_dfs(v, 1e9);
    find_centroid_dfs(v, size[v]);
	return centr;
}

struct path
{
	int gcd;
	int len;
	path(int gcd = -1, int len = 0) : gcd(gcd), len(len) {}
};

path add(path a, int x)
{
	if(a.gcd == -1)
		a.gcd = x;
	else
		a.gcd = __gcd(a.gcd, x);
	a.len++;
	return a;
}

void get_paths(int v, V<path> &paths, path cur, int p)
{
	cur = add(cur, val[v]);
	if(cur.gcd == 1)
		return;

	paths.EB(cur);
	for(int &u : g[v])
	{
		if(!blocked[u] && p != u)
			get_paths(u, paths, cur, v);
	}
}

VI mx(2 * 1e5 + 1);
void add_paths_comming_through(int v)
{
	V<V<path>> paths(S(g[v]));
	REP(i, S(g[v]))
	{
		int u = g[v][i];
		if(!blocked[u])
		{
			get_paths(u, paths[i], path(), v);
			for(auto &p : paths[i])
			{
				ans = max(ans, p.len);
				int G = __gcd(p.gcd, val[v]);
				if(G != 1)
					ans = max(ans, p.len + 1);

				VI primes;
				get_primes(primes, __gcd(G, val[v]));
				for(int x : primes)
					ans = max(ans, mx[x] + p.len + 1);
			}

			for(auto &p : paths[i])
			{
				VI primes;
				get_primes(primes, p.gcd);
				DB(primes);
				for(int x : primes)
					mx[x] = max(mx[x], p.len);
			}
		}
	}

	REP(i, S(g[v]))
	{
		int u = g[v][i];
		if(!blocked[u])
		{
			for(auto &p : paths[i])
			{
				VI primes;
				get_primes(primes, p.gcd);
				for(int x : primes)
					mx[x] = 0;
				}
		}
	}
}

void centroid_decomposition(int v)
{
    int centroid = find_centroid(v);
    add_paths_comming_through(centroid);
    blocked[centroid] = true;
    for(auto &u : g[centroid])
    {
        if(!blocked[u])
            centroid_decomposition(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	sieve();

    int n;
    cin >> n;

	val.RS(n);
	REP(i, n)
		cin >> val[i];

    g.RS(n);
    REP(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        g[a - 1].EB(b - 1);
        g[b - 1].EB(a - 1);
    }

    blocked.RS(n);
    size.RS(n);
    centroid_decomposition(0);

    cout << ans << "\n";
}