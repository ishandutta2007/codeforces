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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi vals(N);
    vector<array<int, 5>> pred(N, { -1, -1, -1, -1, -1 });

    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        if (i) {
            for (int pv = 0; pv < 5; pv++) {
                if (pred[i-1][pv] == -1) continue;
                for (int cv = 0; cv < 5; cv++) {
                    if (vals[i] == vals[i-1] && cv == pv) continue;
                    if (vals[i] > vals[i-1] && !(cv > pv)) continue;
                    if (vals[i] < vals[i-1] && !(cv < pv)) continue;
                    pred[i][cv] = pv;
                }
            }
        } else {
            pred[i] = { 0, 0, 0, 0, 0 };
        }
    }

    vi res(N);
    for (int lv = 0; lv < 5; lv++) {
        if (pred[N-1][lv] == -1) continue;
        for (int i = N - 1; i >= 0; i--) {
            res[i] = lv + 1;
            lv = pred[i][lv];
        }

        for (int i = 0; i < N; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}