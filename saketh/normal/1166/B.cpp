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

    int K;
    cin >> K;

    for (int r = 5; r <= K; r++) {
        if (K % r) continue;
        if (K / r < 5) break;

        int c = K / r;

        string res(K, ' ');
        string vow = "aeiou";

        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                res[i * c + j] = vow[(i+j) % 5];
            }
        }

        for (int i = 0; i < K; i++) {
            cout << res[i];
            //if (i % c == c - 1) cout << endl;
        }
        cout << endl;

        return 0;
    }

    cout << -1 << endl;

    return 0;
}