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

const int N = 100179;

struct Step {
    int x1, y1, x2, y2;
};

vector<Step> solve(vector<vector<pair<string,int>>> &f) {
    int sx = sz(f);
    int sy = sz(f[0]);
    vector<Step> ans;

    auto step = [&](int x1, int y1, int x2, int y2) {
        ans.push_back({x1, y1, x2, y2});
        f[x2][y2].X.push_back(f[x1][y1].X[f[x1][y1].Y++]);
    };
    auto top = [&](int x, int y) {
        return f[x][y].X[f[x][y].Y] - '0';
    };
    auto empty = [&](int x, int y) {
        return f[x][y].Y == sz(f[x][y].X);
    };

    int sz0 = sz(f[0][0].X);
    int sz1 = sz(f[0][1].X);

    for (int i = 0; i < sz0; ++i)
        if (top(0, 0) == 0)
            step(0, 0, 1, 0);
        else
            step(0, 0, 0, 1);
    for (int i = 0; i < sz1; ++i)
        if (top(0, 1) == 1)
            step(0, 1, 1, 1);
        else
            step(0, 1, 0, 0);

    for (int x = 0; x < sx; ++x)
        for (int y = 2; y < sy; ++y)
            while (!empty(x, y))
                step(x, y, x, top(x, y));
    for (int x = 1; x < sx; ++x) {
        while (true) {
            if (!empty(x, 0)) {
                if (top(x, 0) == 0)
                    step(x, 0, 0, 0);
                else
                    step(x, 0, x, 1);
            } else if (!empty(x, 1)) {
                if (top(x, 1) == 1)
                    step(x, 1, 0, 1);
                else
                    step(x, 1, x, 0);
            } else
                break;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<pair<string,int>>> f1(n, vector<pair<string,int>>(m));
    vector<vector<pair<string,int>>> f2(n, vector<pair<string,int>>(m));
    static char ss[N];
    for (auto &f : f1)
        for (auto &s : f) {
            scanf("%s", ss);
            s.X = ss;
            s.Y = 0;
            reverse(all(s.X));
        }
    for (auto &f : f2)
        for (auto &s : f) {
            scanf("%s", ss);
            s.X = ss;
            s.Y = 0;
        }

    auto ans1 = solve(f1);
    auto ans2 = solve(f2);
    reverse(all(ans2));
    cout << sz(ans1) + sz(ans2) << "\n";
    for (auto const& s : ans1)
        cout << s.x1 + 1 << " " << s.y1 + 1 << " " << s.x2 + 1 << " " << s.y2 + 1 << "\n";
    for (auto const& s : ans2)
        cout << s.x2 + 1 << " " << s.y2 + 1 << " " << s.x1 + 1 << " " << s.y1 + 1 << "\n";

    return 0;
}