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

const int N = 100111;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    static set<ipair> ss[N];
    for (int i = 0; i < n; ++i)
        ss[i].insert({-1, 0});
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        --x;
        --y;
        auto it = ss[x].lower_bound(ipair(w, -1));
        --it;
        int len = it->second + 1;
        ans = max(ans, len);
        it = ss[y].insert({w, len}).X;
        --it;
        if (it->second >= len) {
            ++it;
            ss[y].erase(it);
        } else {
            ++it;
            ++it;
            while (it != ss[y].end() && it->second <= len)
                it = ss[y].erase(it);
        }
    }
    cout << ans << "\n";

    return 0;
}