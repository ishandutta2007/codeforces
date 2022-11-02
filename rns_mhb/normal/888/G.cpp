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
#define f2(i, a, b) for (int i = a; i > b; i --)
#define f3(i, a, b) for (int i = a; i >= b; i --)
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;
typedef vector <int> vi;

const int inf = 0x3f3f3f3f;
const ll linf = 2e18 + 100;
const double eps = 1e-7;

#define N 200005

int n, a[N];

struct Trie {
    int tot, rt;
    int nxt[3000005][2];
    void init() {
		tot = 0;
		rt = make_node();
    }
    int make_node() {
        tot ++;
        memset(nxt[tot], 0, sizeof nxt[tot]);
        return tot;
    }
    void insert(int val) {
        int nd = rt, x;
        for (int i = 0; i < 30; i ++) {
			x = (val >> (29 - i)) & 1;
            if (!nxt[nd][x]) nxt[nd][x] = make_node();
            nd = nxt[nd][x];
        }
    }
    int query(int val) {
        int nd = rt, x, res = 0;
        f0(i, 0, 30) {
			x = (val >> (29 - i)) & 1;
            if (nxt[nd][x]) nd = nxt[nd][x];
            else nd = nxt[nd][x^1], res += 1 << (29 - i);
        }
        return res;
    }
} A;

ll func(int L, int R, int h) {
    if (h<0) return 0;
    int x = 1 << h;
    int mid = lower_bound(a+L, a+R+1, x) - a;
    f1(i, mid, R) a[i] -= x;
    if (mid == R+1) return func(L, R, h-1);
    if (mid == L) return func(L, R, h-1);
    ll res = 2e18;
    A.init();
    f1(i, L, mid-1) A.insert(a[i]);
    f1(i, mid, R) chkmin(res, 1ll * A.query(a[i]));
    res += x;
    res += func(L, mid-1, h-1) + func(mid, R, h-1);
    return res;
}

int main() {
    scanf("%d", &n);
    f1(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1;
    printf("%I64d\n", func(1, n, 29));
	return 0;
}