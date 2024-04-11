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

const int N = 200179;

int n;
vector<ipair> ia[N];

ll t;
multiset<ipair> ww;

int main() {
    scanf("%d%lld", &n, &t);
    for (int i = 0; i < n; ++i) {
        int a, r;
        scanf("%d%d", &a, &r);
        ia[a].push_back({r,i+1});
    }

    for (int cnt = n; cnt >= 0; --cnt) {
        for (ipair x : ia[cnt]) {
            ww.insert(x);
            t -= x.X;
        }
        while (sz(ww) > cnt) {
            auto it = prev(ww.end());
            t += it->first;
            ww.erase(it);
        }
        if (sz(ww) == cnt && t >= 0) {
            std::cout << cnt << "\n" << cnt << "\n";
            for (ipair x : ww)
                std::cout << x.Y << " ";
            std::cout << "\n";
            break;
        }
    }

    return 0;
}