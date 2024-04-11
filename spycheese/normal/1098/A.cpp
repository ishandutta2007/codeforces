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

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

// ========================================================================= //

const int N = 100179;

int n;
vector<int> e[N];
ll s[N];
ll ans = 0;

void dfs(int v, ll sp = 0) {
    ans += s[v] - sp;
    if (s[v] - sp < 0) {
        cout << "-1\n";
        exit(0);
    }
    for (int v2 : e[v]) {
        if (e[v2].empty())
            continue;
        ll cur = LINF;
        for (int v3 : e[v2])
            cur = min(cur, s[v3] - s[v]);
        if (cur < 0) {
            cout << "-1\n";
            exit(0);
        }
        ans += cur;
        for (int v3 : e[v2])
            dfs(v3, s[v] + cur);
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        e[x].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    dfs(0);
    cout << ans << "\n";

    return 0;
}