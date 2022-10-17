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
using vb = vector<bool>;
using vs = vector<string>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    ll S, T;
    cin >> N >> M >> S >> T;
    S--;

    auto jump = [&]() {
        if (S < M) S += T;
        else S -= T;

        S %= N;
        if (S < 0) S += N;

        T--;
    };

    while (T % N != 0)
        jump();

    vll last(N, -1);
    while (T > 0) {
        if (last[S] != -1) {
            T %= (last[S] - T);
            if (!T) break;
        }
        last[S] = T;
        for (int i = 0; i < N; i++)
            jump();
    }

    cout << S + 1 << endl;
    return 0;
}