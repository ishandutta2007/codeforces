#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct UnionFind {
    int fa[1505];
    void inline init() {memset(fa, -1, sizeof(fa));}
    int inline root(int x) {return fa[x] < 0 ? x : fa[x] = root(fa[x]);}
    bool inline conn(int a, int b) {
        a = root(a); b = root(b);
        if(a == b) return 0;
        if(fa[a] < fa[b]) swap(a, b);
        return fa[b] += fa[a], fa[a] = b, 1;
    }
} uf;

int n, m;
int S[1505][1505], jo[1505][1505];
int cs[1505];
bitset<1505> as[1505];
bitset<1505> s[1505], jmt[1505], ss[1505];
vector<int> nei[1505], con[1505], egs[1505];
int ans[1505];
int l[1505], r[1505], L[1505], R[1505];
bool lgl[1505];
int mty[1505];
bitset<1505> bb[1505], tmp1, tmp2;

int dfs(int now, int frm, int lst = -1) {
    if (SZ(con[now]) == 1) {
        int fr = frm;
        parse(to, nei[now]) {
            fr = dfs(to, fr);
        }
        L[now] = frm; R[now] = frm + cs[con[now][0]] - 1;
        loop(i, cs[con[now][0]]) bb[frm + i][con[now][0]] = 1;
        lgl[con[now][0]] = 1;
        return frm + cs[con[now][0]];
    }
    int u = -1, v = -1;
    loop(i, SZ(con[now])) if (SZ(egs[con[now][i]])) {
        u = con[now][i];
        v = egs[con[now][i]][0];
        break;
    }
    mty[u] = v; mty[v] = u; lgl[u] = lgl[v] = 1;
    jmt[u] = jmt[v] = s[u] & s[v];
    l[u] = 1; r[u] = cs[u];
    l[v] = r[u] - jo[u][v] + 1; r[v] = l[v] + cs[v] - 1;
    vector<int> q;
    parse(to, con[now]) if (!lgl[to]) {
        if (jo[to][u] && jo[to][u] < min(cs[to], cs[u])) q.pub(to), mty[to] = u, lgl[to] = 1;
        if (jo[to][v] && jo[to][v] < min(cs[to], cs[v])) q.pub(to), mty[to] = v, lgl[to] = 1;
    }
    int cur = now;
    while (SZ(q)) {
        int now = q.back(); q.pob();
        int mt = mty[now], mtt = mty[mt];
        jmt[now] = s[now] & s[mt];
        int mtf = (r[mt] < r[mtt]);
        int mtc = jo[now][mt], mttc = (s[now] & jmt[mt]).count();
        if (!mttc || mtc - mttc == cs[mt] - (int)jmt[mt].count()) {
            if (mtf) r[now] = l[mt] + mtc - 1, l[now] = r[now] - cs[now] + 1;
            else l[now] = r[mt] - mtc + 1, r[now] = l[now] + cs[now] - 1;
        }
        else {
            if (!mtf) r[now] = l[mt] + mtc - 1, l[now] = r[now] - cs[now] + 1;
            else l[now] = r[mt] - mtc + 1, r[now] = l[now] + cs[now] - 1;
        }
        parse(to, con[cur]) if (!lgl[to]) {
            if (jo[to][now] && jo[to][now] < min(cs[now], cs[to])) q.pub(to), mty[to] = now, lgl[to] = 1;
        }
    }
    parse(to, con[now]) assert(lgl[to]);
    int mn = 1;
    parse(to, con[now]) mn = min(mn, l[to]);
    int tjar = frm - mn;
    parse(to, con[now]) {
        L[to] = l[to] + tjar, R[to] = r[to] + tjar;
        circ(i, L[to], R[to]) bb[i][to] = 1;
    }
    parse(to, nei[now]) {
        if (to == lst) continue;
        tmp1.reset(); tmp2.reset();
        cont(i, n) if (lgl[i]) (jo[to][i] ? tmp1 : tmp2)[i] = 1;
        int bg = -1;
        cont(i, m) if ((bb[i] & tmp1).count() == tmp1.count() && !(bb[i] & tmp2).count()) {
            bg = i; break;
        }
        if (!~bg) puts("NO"), exit(0);
        dfs(to, bg);
    }
    return frm + as[now].count();
}

int main() {
    scanf("%d", &n); m = n;
    cont(i, n) cont(j, m) {
        scanf("%1d", S[i] + j);
        if (S[i][j]) s[i][j] = 1, ss[j][i] = 1;
    }
    cont(i, n) cont(j, n) jo[i][j] = (s[i] & s[j]).count();
    cont(i, n) cs[i] = s[i].count();
    uf.init();
    cont(i, n) cont(j, i - 1) {
        if (!cs[i] || !cs[j]) continue;
        if (uf.root(i) == uf.root(j)) continue;
        int ct = jo[i][j];
        if (ct && ct < min(cs[i], cs[j])) uf.conn(i, j), egs[i].pub(j);
    }
    vector<int> ns;
    cont(i, n) if (cs[i]) {
        con[uf.root(i)].pub(i);
        as[uf.root(i)] |= s[i];
        ns.pub(i);
    }
    vector<int> ro;
    sort(all(ns), [&] (int a, int b) { return cs[a] < cs[b]; });
    loop(i, SZ(ns)) if (uf.root(ns[i]) == ns[i]) {
        int a = ns[i];
        bool fnd = 0;
        circ(j, i + 1, SZ(ns) - 1) if (a != uf.root(ns[j])) {
            int b = ns[j];
            if (jo[a][b] == cs[a]) {
                nei[uf.root(b)].pub(a); fnd = 1;
                break;
            }
        }
        if (!fnd) ro.pub(a);
    }
    int ptr = 1;
    parse(it, ro) ptr = dfs(it, ptr);
    memset(lgl, 0, sizeof(lgl));
    cont(i, m) cont(j, m) if (!lgl[j] && bb[i] == ss[j]) {
        ans[i] = j;
        lgl[j] = 1;
        break;
    }
    cont(i, m) if (!ans[i]) return puts("NO"), 0;
    cont(i, n) {
        int mode = 0;
        cont(j, m) {
            if (s[i][ans[j]]) {
                if (!mode) mode = 1;
                if (mode == 2) return puts("NO"), 0;
            }
            else {
                if (mode == 1) mode = 2;
            }
        }
    }
	puts("YES");
	cont(i, n) {
		cont(j, m) printf("%c", '0' + S[i][ans[j]]);
		puts("");
	}
    return 0;
}