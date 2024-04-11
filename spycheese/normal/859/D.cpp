#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

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

const int N = 64;

int n;
ld p[N][N];
vector < ld > pwin[N*2-1];
int _cl[N*2-1], _cr[N*2-1], score[N*2-1];
ld d[N*2-1];

void go1(int v, int cl, int cr, int sc) {
    _cl[v] = cl;
    _cr[v] = cr;
    score[v] = sc;
    pwin[v].resize(n, 0);
    if (cl == cr) {
        pwin[v][cl] = 1.0;
        return;
    } else {
        int v1 = v*2+1, v2 = v*2+2;
        int mid = (cl+cr)/2;
        go1(v1, cl, mid, sc/2);
        go1(v2, mid+1, cr, sc/2);
        for (int i = cl; i <= mid; ++i)
            for (int j = mid+1; j <= cr; ++j) {
                pwin[v][i] += pwin[v1][i]*pwin[v2][j]*p[i][j];
                pwin[v][j] += pwin[v1][i]*pwin[v2][j]*p[j][i];
            }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    n = (1 << n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
            p[i][j] /= 100;
        }

    go1(0, 0, n - 1, n / 2);

    for (int v = n*2 - 2; v >= 0; --v) {
        int cl = _cl[v];
        int cr = _cr[v];
        if (cl == cr) {
            d[v] = 0.0;
            continue;
        }
        for (int x = cl; x <= cr; ++x) {
            ld cd = pwin[v][x] * score[v];
            int cx = x + n-1;
            while (cx != v) {
                cd += pwin[cx][x] * score[cx];
                cd += d[((cx-1)^1)+1];
                cx = (cx-1) / 2;
            }
            d[v] = max(d[v], cd);
        }
    }

    cout.precision(25);
    cout << d[0] << "\n";

    return 0;
}