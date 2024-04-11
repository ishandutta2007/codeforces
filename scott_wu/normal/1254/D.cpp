#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 150100;
const ll MOD = 998244353;
const int BSIZE = 500;
const int BNUM = 610; // mult to 2N

int N, Q;
vector <int> edge[MAXN];
int par[MAXN];
int lo[MAXN], hi[MAXN];
int sz[MAXN];
int nbig;
int bnum[MAXN];
ll bscore[MAXN];
vector <int> bigs;
vector <int> ord;
int rord[MAXN];

ll inv[MAXN];
int nadd[BNUM][MAXN];

ll cpow (ll b, int e)
{
    if (e == 0) return 1;
    ll v = cpow (b, e / 2);
    v = (v * v) % MOD;
    if (e % 2 == 1) v = (v * b) % MOD;
    return v;
}

void flood (int cloc, int last)
{
    lo[cloc] = ord.size();
    ord.push_back(cloc);
    par[cloc] = last;
    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        flood (neigh, cloc);
    }
    hi[cloc] = ord.size();
    sz[cloc] = hi[cloc] - lo[cloc];
}

int seg[MAXN]; // partial diff
int sadd[MAXN];

void pupd (int cloc, int v)
{
    sadd[cloc] += v;
    if (sadd[cloc] >= MOD) sadd[cloc] -= MOD;
    seg[cloc/BSIZE] += v;
    if (seg[cloc/BSIZE] >= MOD) seg[cloc/BSIZE] -= MOD;
}

void upd (int rlo, int rhi, int v)
{
    // add to range
    //cout << rlo << " " << rhi << " " << v << "\n";
    pupd (rlo, v);
    pupd (rhi, MOD - v);
}

ll get_val (int x)
{
    // can sqrt
    int nf = x / BSIZE;
    ll ans = 0;
    for (int i = 0; i < nf; i++)
        ans += seg[i];
    for (int i = nf * BSIZE; i <= x; i++)
        ans += sadd[i];
    return ans % MOD;
}

void add_to (int v, ll d)
{
    upd (lo[v], lo[v] + 1, d);
    for (int neigh : edge[v])
    {
        if (par[neigh] != v) continue;
        int nn = N - sz[neigh];
        ll ndiff = (nn * inv[N]) % MOD;
        ndiff = (ndiff * d) % MOD;
        upd (lo[neigh], hi[neigh], ndiff);
    }
    ll ndiff = (sz[v] * inv[N]) % MOD;
    ndiff = (ndiff * d) % MOD;
    upd (0, lo[v], ndiff);
    upd (hi[v], N, ndiff);
}

void proc_big (int v)
{
    int bloc = bnum[v];
    nadd[bloc][lo[v]] = 1;
    for (int neigh : edge[v])
    {
        if (par[neigh] != v) continue;
        int nn = N - sz[neigh];
        int ndiff = (nn * inv[N]) % MOD;
        for (int i = lo[neigh]; i < hi[neigh]; i++)
            nadd[bloc][i] = ndiff;
    }
    
    int ndiff = (sz[v] * inv[N]) % MOD;
    for (int i = 0; i < lo[v]; i++)
        nadd[bloc][i] = ndiff;
    for (int i = hi[v]; i < N; i++)
        nadd[bloc][i] = ndiff;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    flood (0, 0);

    for (int i = 1; i <= N; i++)
        inv[i] = cpow (i, MOD - 2);

    nbig = 0;
    for (int i = 0; i < N; i++)
    {
        bscore[i] = 0;
        if (edge[i].size() >= BSIZE)
        {
            bnum[i] = nbig++;
            bigs.push_back(i);
            proc_big (i);
        }
        else
            bnum[i] = -1;
    }

    for (int q = 0; q < Q; q++)
    {
        int t, v; cin >> t >> v;
        v--;
        if (t == 1)
        {
            ll d; cin >> d;
            if (bnum[v] != -1)
                bscore[v] = (bscore[v] + d) % MOD;
            else
            {
                // some stuff
                add_to (v, d);
            }
        }
        else
        {
            // some stuff
            int cloc = lo[v];
            ll ans = get_val (cloc);
            for (int big : bigs)
            {
                if (!bscore[big]) continue;
                ans = ans + bscore[big] * nadd[bnum[big]][cloc];
                ans = ans % MOD;
            }
            cout << ans << "\n";
        }
    }
}