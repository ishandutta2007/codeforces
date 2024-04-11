#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vi read() {
    int K;
    cin >> K;
    vi res(K);
    for (int i = 0; i < K; i++)
        cin >> res[i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vvi moves = { read(), read() };

    // 0 = unknown, -1 = loss, 1 = win
    vvi state(2, vi(N, 0));

    // number of reachable states that are wins for the other player
    vvi reach(2, vi(N, 0));

    state[0][0] = -1;
    state[1][0] = -1;

    queue<array<int, 2>> proc;
    proc.push( {0, 0} );
    proc.push( {1, 0} );

    while (!proc.empty()) {
        int p = proc.front()[0];
        int l = proc.front()[1];
        proc.pop();

        TRACE(cout << "Proc " << p << " " << l << " " << state[p][l] << endl;)

        for (int j : moves[!p]) {
            int f = (l - j + N) % N;
            if (f == 0) continue;

            if (state[p][l] == -1) {
                // points to a loss
                if (state[!p][f] != 0) {
                    assert(state[!p][f] == 1);
                } else {
                    state[!p][f] = 1;
                    proc.push( { !p, f } );
                }
            } else if (state[p][l] == 1) {
                // points to a win
                reach[!p][f]++;
                if (reach[!p][f] == moves[!p].size()) {
                    state[!p][f] = -1;
                    proc.push( { !p, f } );
                }
            } else assert(false);
        }
    }

    for (int p = 0; p < 2; p++) {
        for (int l = 1; l < N; l++) {
            int a = state[p][l];
            if (a == -1) cout << "Lose ";
            else if (a == 0) cout << "Loop ";
            else cout << "Win ";
        }
        cout << "\n";
    }

    return 0;
}