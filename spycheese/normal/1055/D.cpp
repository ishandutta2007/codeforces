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

const int N = 3033;

int n;
string v1[N], v2[N];

string a1, a2;
string sp1, sp2;

int z[N*2];
void zf(string const& s) {
    z[0] = 0;
    int ir = 0;
    int n = sz(s);
    for (int i = 1; i < n; ++i) {
        if (i < ir + z[ir])
            z[i] = min(ir + z[ir] - i, z[i - ir]);
        else
            z[i] = 0;
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] > ir + z[ir])
            ir = i;
    }
}

int main() {
    ios::sync_with_stdio(false);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        static char buf[N];
        scanf("%s", buf);
        v1[i] = buf;
    }
    for (int i = 0; i < n; ++i) {
        static char buf[N];
        scanf("%s", buf);
        v2[i] = buf;

        if (v1[i] == v2[i])
            continue;
        int x1 = 0;
        while (v1[i][x1] == v2[i][x1])
            ++x1;
        int x2 = sz(v1[i]) - 1;
        while (v1[i][x2] == v2[i][x2])
            --x2;
        string ca1 = v1[i].substr(x1, x2 - x1 + 1);
        string ca2 = v2[i].substr(x1, x2 - x1 + 1);
        if (a1.empty()) {
            a1 = ca1;
            a2 = ca2;
            sp1 = v1[i].substr(0, x1);
            reverse(all(sp1));
            sp2 = v1[i].substr(x2 + 1, sz(v1[i]) - (x2 + 1));
        } else {
            if (a1 != ca1 || a2 != ca2) {
                cout << "NO\n";
                return 0;
            }
            for (int j = 0; j < sz(sp1); ++j)
                if (x1 - 1 - j < 0 || sp1[j] != v1[i][x1 - 1 - j]) {
                    sp1.erase(sp1.begin() + j, sp1.end());
                    break;
                }
            for (int j = 0; j < sz(sp2); ++j)
                if (x2 + 1 + j >= sz(v1[i]) || sp2[j] != v1[i][x2 + 1 + j]) {
                    sp2.erase(sp2.begin() + j, sp2.end());
                    break;
                }
        }
    }

    reverse(all(sp1));
    string ans1 = sp1 + a1 + sp2;
    string ans2 = sp1 + a2 + sp2;

    for (int i = 0; i < n; ++i) {
        string ss = ans1 + '+' + v1[i];
        zf(ss);
        int pos = -1;
        for (int j = 0; j < sz(v1[i]); ++j)
            if (sz(ans1) == z[sz(ans1) + 1 + j]) {
                pos = j;
                break;
            }
        if (pos == -1) {
            if (v1[i] != v2[i]) {
                cout << "NO\n";
                return 0;
            }
        } else {
            string nv = v1[i];
            for (int j = 0; j < sz(ans1); ++j)
                nv[pos + j] = ans2[j];
            if (nv != v2[i]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    cout << ans1 << "\n";
    cout << ans2 << "\n";

    return 0;
}