#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

const int MAXN = 300500;
const int MAXK = 19;

int par[MAXK][MAXN];
int tin[MAXN], tout[MAXN];
bool used[MAXN];
int h[MAXN];

const int MOD = 1000000009;
const int BASE = 1248217;
int hs[MAXK][MAXN];
int rhs[MAXK][MAXN];
int pows[MAXN];

vector< vector< int > > g;

/*int SA[MAXN];
int SA_pos[MAXN];*/

int n, m;
char buf[MAXN];

void
dfs(int x, int pr)
{
    static int timer = 0;
    used[x] = true;
    h[x] = h[pr] + 1;
    tin[x] = timer++;
    par[0][x] = pr;

    hs[0][x] = buf[x];
    rhs[0][x] = buf[pr];

    for (auto son : g[x]) {
        if (son != pr) {
            dfs(son, x);
        }
    }
    tout[x] = timer++;
}

void
propagate()
{
    for (int lvl = 1; lvl < MAXK; ++lvl) {
        // parents now
        for (int i = 1; i <= n; ++i) {
            par[lvl][i] = par[lvl - 1][par[lvl - 1][i]];
        }
        // hashes now
        for (int i = 1; i <= n; ++i) {
            hs[lvl][i] = (1ll * hs[lvl - 1][i] * pows[1 << (lvl - 1)] + hs[lvl - 1][par[lvl - 1][i]]) % MOD;
            rhs[lvl][i] = (1ll * rhs[lvl - 1][par[lvl - 1][i]] * pows[1 << (lvl - 1)] + rhs[lvl - 1][i]) % MOD;
        }
    } 
}

void
precalc()
{
    pows[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        pows[i] = 1ll * pows[i - 1] * BASE % MOD;
    }
}

inline bool
is_par(int pr, int son)
{
    return (tin[pr] <= tin[son] && tout[pr] >= tout[son]);
}

int
lca(int u, int v)
{
    if (is_par(u, v)) {
        return u;
    }
    if (is_par(v, u)) {
        return v;
    }
    int curv = u;
    for (int i = MAXK - 1; i >= 0; --i) {
        int nextv = par[i][curv];
        if (nextv != 0 && !is_par(nextv, v)) {
            curv = nextv;
        }
    }
    return par[0][curv];
}

int
up_vertex(int u, int height)
{
    for (int i = MAXK - 1; i >= 0; --i) {
        if (height >= (1 << i)) {
            u = par[i][u];
            height ^= (1 << i);
        }
    }
    return u;
}

int
main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    precalc();
    scanf("%d", &n);
    //cin >> n;
    g.clear();
    g.resize(n + 1);
    buf[0] = 0;
    h[0] = -1;
    scanf(" %s", buf + 1);
    /*for (int i = 1; i <= n; ++i) {
        cin >> buf[i];
    }*/
    for (int i = 1; i < n; ++i) {
        int a, b;
        //cin >> a >> b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    propagate();
    //cin >> m;
    scanf("%d", &m);
    for (int qid = 0; qid < m /*&& qid < 100000*/; ++qid) {
        int a, b, c, d;
        //cin >> a >> b >> c >> d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int u1 = lca(a, b), u2 = lca(c, d);
        int len1 = h[a] - h[u1], len2 = h[c] - h[u2];
        int clen = min(h[a] + h[b] - 2 * h[u1], h[c] + h[d] - 2 * h[u2]);
        { // making paths of equal length
            if (len1 > clen) {
                len1 = clen;
                b = u1 = up_vertex(a, len1);
            } else {
                b = up_vertex(b, h[b] - h[u1] - (clen - len1));
            }
            if (len2 > clen) {
                len2 = clen;
                d = u2 = up_vertex(c, len2);
            } else {
                d = up_vertex(d, h[d] - h[u2] - (clen - len2));
            }
        }
        if (len1 > len2) {
            swap(a, c);
            swap(b, d);
            swap(u1, u2);
            swap(len1, len2);
        }
        int svlen1 = len1, svlen2 = len2;
        int aa = a, bb = b, cc = c, dd = d;
        int cur_ans = 0;
        {
            // finding LCP up to lca of both vertices
            bool ok = true;
            int i = MAXK - 1;
            int rlen = len1;
            for (; i >= 0 && ok; --i) {
                if (rlen >= (1 << i)) {
                    if (hs[i][a] == hs[i][c]) {
                        cur_ans += (1 << i);
                        rlen -= (1 << i);
                        a = par[i][a], c = par[i][c];
                    } else {
                        ok = false;
                    }
                }
            }
            if (!ok) {
                while (i >= 0) {
                    if (hs[i][a] == hs[i][c]) {
                        cur_ans += (1 << i);
                        a = par[i][a], c = par[i][c];
                    }
                    --i;
                }
            }
        }
        if (cur_ans == len1) {
            if (len1 != len2) { // going down in first, up in second
                int idealh = len2 - len1;
                int fv = a = up_vertex(b, h[b] - h[u1] - idealh), sv = c;
                vector< int > vertices;
                vertices.reserve(19);
                for (int i = 0, curv = fv; i < MAXK; ++i) {
                    if (idealh & (1 << i)) {
                        vertices.push_back(curv);
                        curv = par[i][curv];
                    }
                }
                bool ok = true;
                int i = MAXK - 1;
                for (; i >= 0 && ok; --i) {
                    if (idealh >= (1 << i)) {
                        if (rhs[i][vertices.back()] == hs[i][sv]) {
                            vertices.pop_back();
                            cur_ans += (1 << i);
                            idealh -= (1 << i);
                            sv = par[i][sv];
                        } else {
                            ok = false;
                        }
                    }
                }
                if (!ok) {
                    // fv is end of checked segment
                    fv = vertices.back();
                    while (i >= 0) {
                        int nextv = par[i][fv];
                        if (rhs[i][nextv] != hs[i][sv]) {
                            fv = nextv;
                        } else {
                            cur_ans += (1 << i);
                            sv = par[i][sv];
                        }
                        --i;
                    }
                }
            }
            if (cur_ans == len2) {
                int rlen = clen - len2;
                int fv = b, sv = d;
                vector< int > v1, v2;
                v1.reserve(19), v2.reserve(19);
                for (int i = 0; i < MAXK; ++i) {
                    if (rlen & (1 << i)) {
                        v1.push_back(fv);
                        v2.push_back(sv);
                        fv = par[i][fv];
                        sv = par[i][sv];
                    }
                }
                int i = MAXK - 1;
                bool ok = true;
                for (; i >= 0 && ok; --i) {
                    if (rlen >= (1 << i)) {
                        if (rhs[i][v1.back()] == rhs[i][v2.back()]) {
                            v1.pop_back();
                            v2.pop_back();
                            cur_ans += (1 << i);
                            rlen -= (1 << i);
                        } else {
                            ok = false;
                        }
                    }
                }
                if (!ok) {
                    fv = v1.back(), sv = v2.back();
                    while (i >= 0) {
                        int nfv = par[i][fv], nsv = par[i][sv];
                        if (rhs[i][nfv] != rhs[i][nsv]) {
                            fv = nfv, sv = nsv;
                        } else {
                            cur_ans += (1 << i);
                        }
                        --i;
                    }
                }
            }
        }
        if (cur_ans > svlen1) {
            aa = up_vertex(bb, clen - cur_ans);
        } else {
            aa = up_vertex(aa, cur_ans);
        }
        if (cur_ans > svlen2) {
            cc = up_vertex(dd, clen - cur_ans);
        } else {
            cc = up_vertex(cc, cur_ans);
        }
        cur_ans += buf[aa] == buf[cc];
        printf("%d\n", cur_ans);
        //cout << cur_ans << '\n';
    }
    return 0;
}