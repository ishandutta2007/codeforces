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

typedef vector<vector<int>> Mat;

Mat flip(Mat const& a) {
    Mat b(sz(a[0]), vector<int>(sz(a)));
    for (int i = 0; i < sz(a); ++i)
        for (int j = 0; j < sz(a[0]); ++j)
            b[j][i] = a[i][j];
    return b;
}

pair<int, Mat> solve(Mat const& a) {
    int res = IINF;
    int sx = sz(a);
    int sy = sz(a[0]);
    Mat b(sx, vector<int>(sy));
    Mat curb(sx, vector<int>(sy));

    int o[4] = {0, 1, 2, 3};
    do {
        if (o[0] > o[1])
            continue;
        if (o[2] > o[3])
            continue;
        int total = 0;
        for (int i = 0; i < sx; ++i) {
            int v[2];
            v[0] = o[0 + (i%2) * 2];
            v[1] = o[1 + (i%2) * 2];
            int cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < sy; ++j) {
                if (a[i][j] != v[j % 2])
                    ++cnt1;
                if (a[i][j] != v[(j^1) % 2])
                    ++cnt2;
            }
            if (cnt1 < cnt2) {
                total += cnt1;
                for (int j = 0; j < sy; ++j)
                    curb[i][j] = v[j % 2];
            } else {
                total += cnt2;
                for (int j = 0; j < sy; ++j)
                    curb[i][j] = v[(j^1) % 2];
            }
        }
        if (total < res) {
            swap(b, curb);
            res = total;
        }
    } while (next_permutation(o, o+ 4));

    return {res, b};
}

const string S = "ACGT";
int main() {
    ios::sync_with_stdio(false);

    int sx, sy;
    cin >> sx >> sy;
    vector<vector<int>> a(sx, vector<int>(sy));
    for (int i = 0; i < sx; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < sy; ++j) {
            char c = s[j];
            if (c == 'A') a[i][j] = 0;
            if (c == 'C') a[i][j] = 1;
            if (c == 'G') a[i][j] = 2;
            if (c == 'T') a[i][j] = 3;
        }
    }

    auto ans1 = solve(a);
    auto ans2 = solve(flip(a));
    ans2.Y = flip(ans2.Y);

    auto &ans = (ans1.X < ans2.X ? ans1.Y : ans2.Y);
    for (int i = 0; i < sx; ++i) {
        for (int j = 0; j < sy; ++j)
            cout << S[ans[i][j]];
        cout << "\n";
    }

    return 0;
}