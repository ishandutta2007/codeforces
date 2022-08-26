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

const int N = 1555;

int n, s, m, k, s0;
int arr[N];
ipair segs0[N], segs[N];
int prv[N];

bool solve(int thr) {
    static int a[N];
    a[0] = 0;
    for (int i = 0; i < n; ++i)
        a[i + 1] = a[i] + (arr[i] < thr);

    static int d[N];
    for (int i = 0; i < s; ++i) {
        d[i] = a[segs[i].Y] - a[segs[i].X];
    }

    for (int iter = 0; iter < m - 1; ++iter) {
        static int dm[N];
        dm[0] = 0;
        for (int i = 0; i < s; ++i)
            dm[i + 1] = max(dm[i], d[i]);
        static int nd[N];
        for (int i = 0; i < s; ++i) {
            int j = prv[i];
            nd[i] = d[j] + a[segs[i].Y] - a[segs[j].Y];
            nd[i] = max(nd[i], dm[j] + a[segs[i].Y] - a[segs[i].X]);
        }
        memcpy(d, nd, sizeof(int) * s);
    }

    for (int i = 0; i < s; ++i)
        if (d[i] >= k)
            return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s0 >> m >> k;
    vector<int> allX;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        allX.push_back(arr[i]);
    }
    for (int i = 0; i < s0; ++i) {
        cin >> segs0[i].X >> segs0[i].Y;
        --segs0[i].X;
    }

    for (int i = 0; i < s0; ++i) {
        int l = segs0[i].X, r = segs0[i].Y;
        bool fail = false;
        for (int j = 0; j < s0; ++j) {
            int cl = segs0[j].X, cr = segs0[j].Y;
            if (cl == l && cr == r) {
                if (i < j) {
                    fail = true;
                    break;
                }
            } else {
                if (cl <= l && r <= cr) {
                    fail = true;
                    break;
                }
            }
        }
        if (!fail)
            segs[s++] = segs0[i];
    }
    m = min(m, s);
    sort(segs, segs + s);

    for (int i = 0; i < s; ++i) {
        for (int j = 0; j <= i; ++j)
            if (segs[j].Y >= segs[i].X) {
                prv[i] = j;
                break;
            }
    }

    if (!solve(IINF)) {
        cout << -1 << "\n";
        return 0;
    }

    sort(all(allX));
    allX.erase(unique(all(allX)), allX.end());
    int bl = 0, br = sz(allX);
    while (br - bl > 1) {
        int mid = (bl + br) / 2;
        if (solve(allX[mid]))
            br = mid;
        else
            bl = mid;
    }

    cout << allX[bl] << "\n";

    return 0;
}