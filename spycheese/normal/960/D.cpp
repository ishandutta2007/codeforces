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

const int N = 61;

ll st[N];
ll sh[N];

int getLev(ll x) {
    for (int i = 0; i < N; ++i) {
        if (x >= st[i] && (i == N - 1 || x < st[i + 1]))
            return i;
    }
    assert(0);
}

int main() {
    st[0] = 1;
    for (int i = 1; i < N; ++i)
        st[i] = st[i-1]*2;
    int qq;
    scanf("%d", &qq);
    while (qq--) {
        int tt;
        scanf("%d", &tt);
        if (tt == 3) {
            ll x;
            scanf("%lld", &x);
            int lev = getLev(x);
            ll pos = (x - st[lev] + sh[lev]) & ((1LL << lev) - 1);
            cout << x;
            while (lev != 0) {
                pos /= 2;
                --lev;
                cout << " " << (st[lev] + ((pos - sh[lev]) & ((1LL << lev) - 1)));
            }
            cout << "\n";
        } else {
            ll x, k;
            scanf("%lld%lld", &x, &k);
            int lev = getLev(x);
            k &= ((1LL << lev) - 1);
            for (int i = lev; i < (tt == 1 ? lev + 1 : N); ++i) {
                (sh[i] += k) &= ((1LL << i) - 1);
                k *= 2;
            }
        }
    }

    return 0;
}