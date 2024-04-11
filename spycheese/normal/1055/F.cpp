#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

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
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 1000123;

int n;
ll k;
ll a[N];
int cl[N], cr[N];

int main() {
    scanf("%d%I64d", &n, &k);
    a[0] = 0;
    for (int i = 1; i < n; ++i) {
        int p;
        ll w;
        scanf("%d%I64d", &p, &w);
        --p;
        a[i] = a[p] ^ w;
    }

    --k;
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        cl[i] = 0;
        cr[i] = n;
    }

    ll cpref = 0;
    for (int z = 61; z >= 0; --z) {
        static int nxt[N];
        nxt[n] = n;
        for (int i = n - 1; i >= 0; --i)
            if (a[i] & (1ll << z))
                nxt[i] = i;
            else
                nxt[i] = nxt[i + 1];
        ll cnt0 = 0;
        for (int i = 0; i < n; ++i) {
            int mid = min(cr[i], nxt[cl[i]]);
            if (a[i] & (1ll << z))
                cnt0 += cr[i] - mid;
            else
                cnt0 += mid - cl[i];
        }
        if (cnt0 > k) {
            for (int i = 0; i < n; ++i) {
                int mid = min(cr[i], nxt[cl[i]]);
                if (a[i] & (1ll << z))
                    cl[i] = mid;
                else
                    cr[i] = mid;
            }
        } else {
            k -= cnt0;
            for (int i = 0; i < n; ++i) {
                int mid = min(cr[i], nxt[cl[i]]);
                if (a[i] & (1ll << z))
                    cr[i] = mid;
                else
                    cl[i] = mid;
            }
            cpref += 1ll << z;
        }
    }

    cout << cpref << "\n";


    return 0;
}