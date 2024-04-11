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

const int T = 25;

int n, m;
vector < string > si;
vector < string > ss1, ss2;
vector < ipair > qs;
vector < int > ans;

int s2i(string const& a) {
    int x = 0;
    for (int i = 0; i < sz(a); ++i)
        if (a[i] == '1')
            x |= 1 << i;
    return x;
}

string pref(string const& s, int t) {
    t = min(t, sz(s));
    return s.substr(0, t);
}
string suf(string const& s, int t) {
    t = min(t, sz(s));
    return s.substr(sz(s)-t, t);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    si.resize(n);
    ans.resize(n + m);
    ss1.resize(n + m);
    ss2.resize(n + m);
    for (int i = 0; i < n; ++i) {
        cin >> si[i];
        ss1[i] = pref(si[i], T);
        ss2[i] = suf(si[i], T);
    }
    cin >> m;
    qs.resize(m);
    ans.resize(n + m);
    ss1.resize(n + m);
    ss2.resize(n + m);
    for (int i = 0; i < m; ++i) {
        cin >> qs[i].X >> qs[i].Y;
        --qs[i].X;
        --qs[i].Y;
        int x = qs[i].X, y = qs[i].Y;
        ss1[n+i] = ss1[x];
        if (sz(ss1[n+i]) < T)
            ss1[n+i] += pref(ss1[y], T - sz(ss1[n+i]));
        ss2[n+i] = ss2[y];
        if (sz(ss2[n+i]) < T)
            ss2[n+i] = suf(ss2[x], T - sz(ss2[n+i])) + ss2[n+i];
    }
    
    ans.resize(m);
    for (int len = 1; true; ++len) {
        bool was = false;

        vector < unordered_set < int > > ss;
        ss.resize(n + m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j + len <= sz(si[i]); ++j)
                ss[i].insert(s2i(si[i].substr(j, len)));
        }

        for (int i = 0; i < m; ++i) {
            string s = ss2[qs[i].X] + ss1[qs[i].Y];
            ss[n+i] = ss[qs[i].X];
            for (int y : ss[qs[i].Y])
                ss[n+i].insert(y);
            for (int j = max(0, sz(ss2[qs[i].X])+1-len); j < sz(ss2[qs[i].X]) && j + len <= sz(s); ++j)
                ss[n+i].insert(s2i(s.substr(j, len)));
            if (sz(ss[n+i]) == (1 << len)) {
                was = 1;
                ans[i] = len;
            }
        }

        if (!was)
            break;
    }

    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";

    return 0;
}