#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<array<double, 2>> proj(double x, double y, double a, double b, double c) {
    vector<array<double, 2>> res;
    if (abs(b) > 1e-9)
        res.push_back({ x, (-c - a * x) / b });
    if (abs(a) > 1e-9)
        res.push_back({ (-c - b * y) / a, y });
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    double a, b, c;
    cin >> a >> b >> c;
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double ans = abs(x2 - x1) + abs(y2 - y1);
    auto p1 = proj(x1, y1, a, b, c);
    auto p2 = proj(x2, y2, a, b, c);
    for (auto a : p1) {
        for (auto b : p2) {
            double cand = abs(x1 - a[0]) + abs(y1 - a[1]);
            cand += sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
            cand += abs(x2 - b[0]) + abs(y2 - b[1]);
            ans = min(ans, cand);
        }
    }

    cout << ans << endl;
    return 0;
}