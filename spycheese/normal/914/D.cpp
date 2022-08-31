#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 1 << 19;

struct SegTree {
    int t[N*2-1];
    void set(int p, int v) {
        t[p += N - 1] = v;
        while (p != 0) {
            (--p) /= 2;
            t[p] = __gcd(t[p*2+1], t[p*2+2]);
        }
    }

    pair<int, bool> prefCnt(int l, int k, int c = 0, int cl = 0, int cr = N - 1) {
        if (cr < l)
            return {0, true};
        if (cl == cr) {
            if (t[c] % k == 0)
                return {1, true};
            else
                return {0, false};
        }
        int c1 = c*2+1, c2 = c*2+2, mid = (cl+cr) / 2;
        if (cl >= l && t[c] % k == 0)
            return {cr - cl + 1, true};
        ipair a1 = prefCnt(l, k, c1, cl, mid);
        if (!a1.Y)
            return a1;
        ipair a2 = prefCnt(l, k, c2, mid+1, cr);
        return {a2.X + a1.X, a2.Y};
    }
    pair<int, bool> sufCnt(int r, int k, int c = 0, int cl = 0, int cr = N - 1) {
        if (cl > r)
            return {0, true};
        if (cl == cr) {
            if (t[c] % k == 0)
                return {1, true};
            else
                return {0, false};
        }
        int c1 = c*2+1, c2 = c*2+2, mid = (cl+cr) / 2;
        if (cr <= r && t[c] % k == 0)
            return {cr - cl + 1, true};
        ipair a2 = sufCnt(r, k, c2, mid+1, cr);
        if (!a2.Y)
            return a2;
        ipair a1 = sufCnt(r, k, c1, cl, mid);
        return {a1.X + a2.X, a1.Y};
    }
} st;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        st.set(i, x);
    }
    int qq;
    scanf("%d", &qq);
    while (qq--) {
        int tt;
        scanf("%d", &tt);
        if (tt == 2) {
            int i, y;
            scanf("%d%d", &i, &y);
            --i;
            st.set(i, y);
        } else {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            --l;
            --r;
            if (st.prefCnt(l, k).X + st.sufCnt(r, k).X >= (r - l + 1) - 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}