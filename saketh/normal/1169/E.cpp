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

    const int BITS = 19;

    int N, Q;
    cin >> N >> Q;

    vi vals(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
    }

    vi last(BITS);
    vvi jump(N + 1, vi(BITS, N));

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < BITS; j++) {
            for (int k = 0; k < BITS; k++)
                if (vals[i] & (1 << k))
                    jump[i][j] = min(jump[i][j], jump[last[k]][j]);
        }

        for (int j = 0; j < BITS; j++) {
            if (vals[i] & (1 << j)) {
                last[j] = i;
                jump[i][j] = i;
            }
        }
    }

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        bool reach = false;
        for (int j = 0; j < BITS; j++) {
            reach |= (vals[y] & (1 << j)) && (jump[x][j] <= y);
        }

        cout << (reach ? "Shi\n" : "Fou\n");
    }

    return 0;
}