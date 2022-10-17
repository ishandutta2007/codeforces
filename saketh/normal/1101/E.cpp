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

    int N;
    cin >> N;

    char op;
    int x = 0, y = 0;

    for (int i = 0, h, w; i < N; i++) {
        cin >> op >> h >> w;
        if (h > w) swap(h, w);

        if (op == '+') {
            x = max(x, h);
            y = max(y, w);
        } else {
            cout << (h >= x && w >= y ? "YES\n" : "NO\n");
        }
    }

    return 0;
}