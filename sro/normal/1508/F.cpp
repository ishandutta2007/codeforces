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

const int maxn = 25005, maxq = 100005, blk = 233;
int n, q;
int a[maxn], pos[maxn];
vector<pair<int, int> > qs[maxn];
vector<pair<int, int*> > es[maxn];
int ls[maxq], rs[maxq], ord[maxq];
vector<int> gl[maxn], gr[maxn], bl[maxn], el[maxn], br[maxn], er[maxn];

struct Fenwick {
    int dt[maxn];
    void inline init() {
        cont(i, n) dt[i] = q + 1;
    }
    void inline add(int a, int x) {
        while (a <= n) {
            dt[a] = min(dt[a], x);
            a += a & -a;
        }
    }
    int inline get(int a) {
        int res = q + 1;
        while (a) {
            res = min(res, dt[a]);
            a -= a & -a;
        }
        return res;
    }
} bit;

set<int> st;
set<pair<int, int> > nb;

namespace MoQ {
    void inline Add(int x) {
        auto it = st.insert(x).first;
        if (it != st.begin()) nb.emplace(*prev(it), x);
        if (next(it) != st.end()) nb.emplace(x, *next(it));
        if (it != st.begin() && next(it) != st.end()) nb.erase(mak(*prev(it), *next(it)));
    }

    void inline Del(int x) {
        auto it = st.find(x);
        if (it != st.begin()) nb.erase(mak(*prev(it), x));
        if (next(it) != st.end()) nb.erase(mak(x, *next(it)));
        if (it != st.begin() && next(it) != st.end()) nb.emplace(*prev(it), *next(it));
        st.erase(it);
    }

    int nl = 1, nr = 0;

    void inline Access(int l, int r) {
        while (nl > l) Add(a[--nl]);
        while (nr < r) Add(a[++nr]);
        while (nl < l) Del(a[nl++]);
        while (nr > r) Del(a[nr--]);
    }
}
using MoQ::Access;

int res[maxq];

int main() {
    scanf("%d%d", &n, &q);
    cont(i, n) {
        scanf("%d", a + i);
        pos[a[i]] = i;
    }
    cont(i, q) {
        scanf("%d%d", ls + i, rs + i);
        qs[rs[i]].emb(ls[i], i);
        ord[i] = i;
    }
    sort(ord + 1, ord + q + 1, [&] (int a, int b) {
        return mak(ls[a] / blk, rs[a]) < mak(ls[b] / blk, rs[b]);
    });
    cont($i, q) {
        int i = ord[$i];
        Access(ls[i], rs[i]);
        parse(it, nb) {
            int lp = pos[it.first], rp = pos[it.second];
            if (lp < rp) gr[lp].pub(rp);
            else gl[lp].pub(rp);
        }
        nb.clear();
    }
    cont(i, n) {
        sort(all(gl[i]), greater<int>());
        gl[i].erase(unique(all(gl[i])), gl[i].end());
        sort(all(gr[i]));
        gr[i].erase(unique(all(gr[i])), gr[i].end());
        bl[i].resize(SZ(gl[i])); el[i].resize(SZ(gl[i]));
        br[i].resize(SZ(gr[i])); er[i].resize(SZ(gr[i]));
        int p = 0;
        loop(j, SZ(gl[i])) {
            while (p < SZ(gr[i]) && a[gr[i][p]] > a[gl[i][j]]) ++p;
            es[i].emb(gl[i][j], &bl[i][j]);
            if (p < SZ(gr[i])) {
                es[gr[i][p]].emb(gl[i][j], &el[i][j]);
            } else {
                el[i][j] = q + 1;
            }
        }
        p = 0;
        loop(j, SZ(gr[i])) {
            while (p < SZ(gl[i]) && a[gl[i][p]] > a[gr[i][j]]) ++p;
            es[gr[i][j]].emb(i, &br[i][j]);
            if (p < SZ(gl[i])) {
                es[gr[i][j]].emb(gl[i][p], &er[i][j]);
            } else {
                er[i][j] = q + 1;
            }
        }
    }
    bit.init();
    range(i, n, 1, -1) {
        parse(it, qs[i]) bit.add(it.first, it.second);
        parse(it, es[i]) *it.second = bit.get(it.first);
    }
    cont(i, n) {
        loop(j, SZ(gl[i])) {
            int tl = bl[i][j], tr = min(j < SZ(gl[i]) - 1 ? bl[i][j + 1] : q + 1, el[i][j]);
            if (tl < tr) ++res[tl], --res[tr];
        }
        loop(j, SZ(gr[i])) {
            int tl = br[i][j], tr = min(j < SZ(gr[i]) - 1 ? br[i][j + 1] : q + 1, er[i][j]);
            if (tl < tr) ++res[tl], --res[tr];
        }
    }
    partial_sum(res, res + q + 1, res);
    cont(i, q) printf("%d\n", res[i]);
    return 0;
}