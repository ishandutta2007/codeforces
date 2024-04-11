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

const int maxn = 1 << 18;

struct Segtree {
    pair<int, int> mn[maxn << 1], mx[maxn << 1];
    void inline change(int a, pair<int, int> x) {
        a += maxn;
        mn[a] = mx[a] = x;
        while (a >>= 1) mn[a] = min(mn[a << 1], mn[a << 1 | 1]), mx[a] = max(mx[a << 1], mx[a << 1 | 1]);
    }
    void inline chmin(int a, pair<int, int> x) {
        for (a += maxn; a; a >>= 1) mn[a] = min(mn[a], x);
    }
    pair<int, int> inline getmin(int l, int r) {
        pair<int, int> ans = mak(Inf, Inf);
        for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = min(ans, mn[l++]);
            if (r & 1) ans = min(ans, mn[--r]);
        }
        return ans;
    }
    pair<int, int> inline getmax(int l, int r) {
        pair<int, int> ans = mak(-Inf, -Inf);
        for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = max(ans, mx[l++]);
            if (r & 1) ans = max(ans, mx[--r]);
        }
        return ans;
    }
} seg, ar3, ar4;

int n, q;
int a[maxn];
vector<int> st1, st2;
set<int> ps, pps;

int main() {
    scanf("%d%d", &n, &q);
    cont(i, n) scanf("%d", a + i);
    cont(i, n) seg.change(i, mak(a[i], i));
    int pre = -1, ppre = -1;
    cont(i, n) ar3.change(i, mak(Inf, Inf)), ar4.change(i, mak(Inf, Inf));
    cont(i, n) {
        if (!~pre || a[i] != a[pre]) {
            if (~ppre && ((a[pre] > a[ppre]) ^ (a[i] > a[pre]))) ar3.chmin(ppre, mak(i, ppre));
            ppre = pre;
        }
        pre = i;
    }
    cont(i, n) {
        while (SZ(st1) && a[i] > a[st1.back()]) {
            int id = st1.back(); st1.pob();
            if (pps.count(id)) ps.insert(id);
            else pps.insert(id);
        }
        while (SZ(st2) && a[i] < a[st2.back()]) {
            int id = st2.back(); st2.pob();
            if (pps.count(id)) ps.insert(id);
            else pps.insert(id);
        }
        int pt1 = lower_bound(all(st1), i, [&] (int x, int y) { return a[x] > a[y]; }) - st1.begin() - 1;
        int pt2 = lower_bound(all(st2), i, [&] (int x, int y) { return a[x] < a[y]; }) - st2.begin() - 1;
        if (pt1 >= 0 && pt2 >= 0) {
            int to = min(st1[pt1], st2[pt2]);
            auto it = ps.lower_bound(to);
            if (it != ps.begin()) {
                --it;
                ar4.chmin(*it, mak(i, *it));
            }
        }
        st1.pub(i);
        st2.pub(i);
    }
    while (q--) {
        int l, r; scanf("%d%d", &l, &r);
        auto it = ar4.getmin(l, r);
        int lp = it.second, rp = it.first;
        if (rp <= r) {
            int u = seg.getmax(lp + 1, rp - 1).second, v = seg.getmin(lp + 1, rp - 1).second;
            puts("4");
            printf("%d %d %d %d\n", lp, min(u, v), max(u, v), rp);
        }
        else {
            auto it = ar3.getmin(l, r);
            int lp = it.second, rp = it.first;
            if (rp <= r) {
                int u = seg.getmax(lp + 1, rp - 1).second;
                if (a[u] == a[lp] || a[u] == a[rp]) u = seg.getmin(lp + 1, rp - 1).second;
                puts("3");
                printf("%d %d %d\n", lp, u, rp);
            }
            else puts("0");
        }
    }
    return 0;
}