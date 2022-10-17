#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    int ans = INT_MAX, ax, ay;
    for (int x = 0; x <= 1000; x++) {
        for (int y = 0; y <= 1000; y++) {
            int res = 1
                + abs(x - xa) + abs(y - ya)
                + abs(x - xb) + abs(y - yb)
                + abs(x - xc) + abs(y - yc);
            if (res < ans) {
                ans = res;
                ax = x;
                ay = y;
            }
        }
    }

    auto print_path = [](int ax, int ay, int x, int y) {
        while (ax != x) {
            cout << x << " " << y << "\n";
            if (x < ax) x++;
            else x--;
        }
        while (ay != y) {
            cout << x << " " << y << "\n";
            if (y < ay) y++;
            else y--;
        }
    };

    cout << ans << endl;
    cout << ax << " " << ay << "\n";
    print_path(ax, ay, xa, ya);
    print_path(ax, ay, xb, yb);
    print_path(ax, ay, xc, yc);

    return 0;
}