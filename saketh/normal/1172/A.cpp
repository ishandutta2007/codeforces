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

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi hand(N), pile(N), loc(N + 1, -1);

    for (int i = 0; i < N; i++) {
        cin >> hand[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> pile[i];
        loc[pile[i]] = i;
    }

    // case 1 : don't pull the 1 into our hands
    if (loc[1] != -1) {
        bool tail = true;

        int e = 1 + N - 1 - loc[1];
        for (int v = 2; v <= e; v++) {
            tail &= loc[v] == loc[1] + v - 1;
        }
        for (int v = e + 1; v <= N; v++) {
            tail &= loc[v] <= v - e - 2;
        }

        if (tail) {
            cout << N - e << "\n";
            return 0;
        }
    }

    // case 2: 1 in hand or will need to reach hands
    int moves = loc[1] + 1;
    for (int i = loc[1] + 1; i < N; i++) {
        if (!pile[i]) continue;
        int need = pile[i] - 2;
        moves = max(moves, i - need);
    }
    cout << moves + N << endl;

    return 0;
}