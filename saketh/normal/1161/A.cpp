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

    int N, K;
    cin >> N >> K;

    vi fst(N, INT_MAX), lst(N, INT_MIN);

    for (int i = 0, v; i < K; i++) {
        cin >> v;
        v--;

        fst[v] = min(fst[v], i);
        lst[v] = max(lst[v], i);
    }

    int ans = 0;
    for (int a = 0; a < N; a++) {
        for (int b = max(0, a - 1); b <= min(a + 1, N - 1); b++) {
            if (fst[a] > lst[b]) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}