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

const int N = 2011;

int n;
int w[N];
bool taken[N];
int p[N];

int main() {
    ios::sync_with_stdio(false);

    int m;
    cin >> n >> m;
    n *= 2;
    memset(w, -1, sizeof(w));
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        w[x] = y;
        w[y] = x;
    }
    int t;
    cin >> t;
    for (int ii = 0; ii < n; ++ii) {
        if ((t + ii) % 2) {
            int x = -1;
            for (int i = 0; i < n; ++i)
                if (!taken[i]) {
                    if (w[i] != -1 && taken[w[i]]) {
                        x = i;
                        break;
                    }
                }
            if (x != -1) {
                taken[x] = 1;
                ++x;
                cout << x << "\n";
                cout.flush();
                continue;
            }
            int bc = -IINF;
            for (int i = 0; i < n; ++i)
                if (!taken[i]) {
                    int c;
                    if (w[i] == -1)
                        c = p[i];
                    else if (p[w[i]] <= p[i])
                        c = IINF;
                    else
                        c = -IINF;
                    if (bc < c) {
                        bc = c;
                        x = i;
                    }
                }
            assert(x != -1);
            taken[x] = 1;
            ++x;
            cout << x << "\n";
            cout.flush();
        } else {
            int x;
            cin >> x;
            --x;
            taken[x] = 1;
        }
    }

    return 0;
}