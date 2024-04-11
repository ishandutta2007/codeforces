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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    auto dist = [&](int i, int j) {
        return ll(abs(x[j] - x[i]) + abs(y[j] - y[i]));
    };

    ll total = 0;
    int xmin = INT_MAX, xmax = INT_MIN;
    int ymin = INT_MAX, ymax = INT_MIN;

    for (int i = 0; i < N; i++) {
        total += dist(i, (i+1)%N);

        xmin = min(xmin, x[i]);
        xmax = max(xmax, x[i]);
        ymin = min(ymin, y[i]);
        ymax = max(ymax, y[i]);
    }

    if (N == 3) {
        cout << total << endl;
        return 0;
    }

    vi extr;
    for (int i = 0; i < N; i++) {
        if (x[i] == xmin || x[i] == xmax || y[i] == ymin || y[i] == ymax) {
            extr.push_back(i);
        }
    }

    assert(extr.size() <= 8);
    assert(extr.size() >= 2);

    ll ans = 0;
    for (int i = 0; i < extr.size(); i++) {
        for (int j = i + 1; j < extr.size(); j++) {
            int a = extr[i], b = extr[j];
            for (int c = 0; c < N; c++) {
                if (a == c || b == c) continue;
                ans = max(ans, dist(a, b) + dist(b, c) + dist(a, c));
            }
        }
    }

    cout << ans;
    for (int u = 4; u <= N; u++)
        cout << " " << total << " ";
    cout << endl;

    return 0;
}