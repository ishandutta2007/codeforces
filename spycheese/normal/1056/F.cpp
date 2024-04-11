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

const int N = 105;

struct Task {
    int a, p;
};

double cpow[N];

int solve() {
    int n;
    double coef, t;
    cin >> n;
    cin >> coef >> t;
    static Task tasks[N];
    for (int i = 0; i < n; ++i)
        cin >> tasks[i].a >> tasks[i].p;
    sort(tasks, tasks + n, [](Task const& a, Task const& b) { return a.a > b.a; });

    double d[N][N*10];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < N*10; ++j)
            d[i][j] = 1e18;

    d[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int p = tasks[i].p;
        for (int cnt = i + 1; cnt > 0; --cnt)
            for (int j = p; j <= 1000; ++j)
                d[cnt][j] = min(d[cnt][j], d[cnt-1][j-p] + 10.0 + tasks[i].a * cpow[cnt]);
    }

    int ans = 0;
    for (int cnt = 1; cnt <= n; ++cnt)
        for (int p = 0; p <= 1000; ++p) {
            double wa = coef;
            double wb = 1 + 10*cnt*coef - t*coef;
            double r = t - d[cnt][p];
            double x = -wb/(2.0*wa);
            x = max(x, 0.0);
            if (wa*x*x + wb*x <= r)
                ans = max(ans, p);
        }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    cpow[0] = 1;
    for (int i = 1; i < N; ++i)
        cpow[i] = cpow[i - 1] / 0.9;

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }

    return 0;
}