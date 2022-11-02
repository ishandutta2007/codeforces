#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pc putchar
#define gc getchar
#define pb push_back
#define ppb pop_back
#define x first
#define y second
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}
typedef pair <int, int> pii;
const ll linf = 2e18 + 100;
#define N 300005

int n, mx;
int t[N], f[N], id[N], a[N], b[N], ids;
vector <int> v[N<<2];
vector <pii> vv[N<<2];
ll ans;

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int now;
void update(int l, int r, int L, int R, int seg) {
    chkmax(mx, seg);
    if (l <= L && R <= r) {
        v[seg].pb(l);
        return;
    }
    int mid = L + R >> 1;
    if (l <= mid) update(l, r, L, mid, seg << 1);
    if (mid < r) update(l, r, mid + 1, R, seg << 1 | 1);
    return;
}

void update1(ll a, ll b, int k) {
    if (!vv[k].empty() && vv[k].back().x == a) {
        if (vv[k].back().y < b) vv[k].ppb();
        else return;
    }
    pii L(a, b), M, P;
    int sz = vv[k].size();
    while (sz > 1) {
        M = vv[k].back(); P = vv[k][sz-2];
        if (1ll * (M.x - P.x) * (L.y - M.y) >= 1ll * (P.y - M.y) * (M.x - L.x)) vv[k].ppb(), sz --;
        else break;
    }
    vv[k].pb(L);
}

ll query(ll x, int k) {
    if (vv[k].empty()) return - linf;
    int st = -1, en = vv[k].size() - 1, mid;
    while (en - st > 1) {
        mid = st + en >> 1;
        if (1ll * vv[k][mid].x * x + vv[k][mid].y <= 1ll * vv[k][mid + 1].x * x + vv[k][mid + 1].y) st = mid;
        else en = mid;
    }
    return 1ll * vv[k][en].x * x + vv[k][en].y;
}

void query(int p, int L, int R, int seg) {
    chkmax(ans, query(b[p], seg));
    if (L == R) return;
    int mid = L + R >> 1;
    if (p <= mid) query(p, L, mid, seg << 1);
    else query(p, mid + 1, R, seg << 1 | 1);
    return;
}

int main() {
    scanf("%d", &n);
    f1(i, 1, n) f[i] = n;
    f1(i, 1, n) {
        scanf("%d", &t[i]);
        if (t[i] == 1) {
            scanf("%d %d", &a[i], &b[i]);
            id[++ ids] = i;
        }
        else if (t[i] == 2) {
            scanf("%d", &a[i]);
            f[a[i]] = i;
        }
        else scanf("%d", &b[i]);
    }
    sort(id + 1, id + ids + 1, cmp);
    f1(i, 1, ids) update(id[i], f[id[i]], 1, n, 1);
    f1(i, 1, mx) f0(j, 0, v[i].size()) update1(a[v[i][j]], b[v[i][j]], i);
    f1(i, 1, n) if (t[i] == 3) {
        ans = -linf;
        query(i, 1, n, 1);
        if (ans == -linf) puts("EMPTY SET");
        else printf("%I64d\n", ans);
    }
    return 0;
}