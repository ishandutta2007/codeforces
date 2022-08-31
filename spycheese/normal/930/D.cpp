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

const int N = 100179;

ll solve(vector<ipair> a) {
    if (a.empty())
        return 0;
    vector<vector<int>> w(N*6);
    multiset<int> ss1, ss2;
    for (ipair & p : a) {
        int x = p.X;
        int y = p.Y;
        p.X = (x+y) / 2;
        p.Y = (x-y) / 2;
        w[p.X+N*2].push_back(p.Y);
        ss2.insert(p.Y);
    }
    ll ans = 0;
    for (int i = 0; i < N*6; ++i) {
        for (int y : w[i]) {
            ss2.erase(ss2.find(y));
            ss1.insert(y);
        }
        if (ss1.empty() || ss2.empty())
            continue;
        ans += max(0, min(*ss1.rbegin(), *ss2.rbegin()) - max(*ss1.begin(), *ss2.begin()));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ipair> a1, a2;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if ((x + y) % 2 == 0)
            a1.push_back({x, y});
        else
            a2.push_back({x, y + 1});
    }

    cout << solve(a1) + solve(a2) << "\n";

    return 0;
}