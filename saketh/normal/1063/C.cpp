#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    map<int, bool> res;

    int lblack = 2;
    int xmin = 3, xmax = 1.5e9;
    for (int i = 0; i < N; i++) {
        int midp = (ll(xmin) + xmax) / 2;

        int y = midp/2;
        int x = midp-y;

        cout << x << " " << y << endl;
        string color;
        cin >> color;

        assert(!res.count(midp));
        res[midp] = color == "white";

        if (color == "white") {
            xmax = midp - 1;
        } else {
            lblack = midp;
            xmin = midp + 1;
        }
    }

    for (auto [loc, color] : res) {
        if (color) assert(loc > lblack);
        else assert(loc <= lblack);
    }
    int y = lblack/2;
    int x = lblack-y;
    if (lblack&1) {
        cout << x - 1 << " " << y + 1 << " " << x + 1 << " " << y << endl;
    } else {
        cout << x << " " << y + 1 << " " << x + 1 << " " << y - 1 << endl;
    }

    return 0;
}