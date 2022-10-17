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

    vi minn(180);
    int found = 0;

    for (int n = 3; found < 179; n++) {
        for (int d = 1; d <= n - 2; d++) {
            if (180 * d % n) continue;
            int a = 180 * d / n;
            if (!minn[a]) {
                minn[a] = n;
                found++;
            }
        }
    }

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int a;
        cin >> a;
        cout << minn[a] << "\n";
    }

    return 0;
}