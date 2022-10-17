#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int d2(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2)
         + (y1 - y2) * (y1 - y2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    vi x(3), y(3);
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];

    vector<pair<int, int>> pos;

    for (int a = 0; a < 3; a++) {
        for (int b = a + 1; b < 3; b++) {
            int c = 0 + 1 + 2 - a - b;

            int px = x[a] + x[b] - x[c];
            int py = y[a] + y[b] - y[c];

            if (d2(px, py, x[a], y[a]) == d2(x[c], y[c], x[b], y[b])
             && d2(px, py, x[b], y[b]) == d2(x[c], y[c], x[a], y[a]))
                pos.emplace_back(px, py);
        }
    }

    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());

    cout << pos.size() << "\n";
    for (auto p : pos)
        cout << p.first << " " << p.second << "\n";
    return 0;
}