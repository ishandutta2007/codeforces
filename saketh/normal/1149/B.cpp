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

    const int INF = INT_MAX;

    int N, Q;
    cin >> N >> Q;

    string univ;
    cin >> univ;

    vector<array<int, 26>> jump(N + 1);
    for (int& inx : jump.back()) {
        inx = INF;
    }
    for (int i = N - 1; i >= 0; i--) {
        jump[i] = jump[i+1];
        jump[i][univ[i] - 'a'] = i + 1;
    }

    const int MLEN = 251;
    vector<vvi> dp(MLEN, vvi(MLEN, vi(MLEN, INF)));
    dp[0][0][0] = 0;

    vector<vector<char>> relig(3);
    array<int, 3> size = { 0, 0, 0 };

    for (int q = 0; q < Q; q++) {
        char op, elt;
        int which;

        cin >> op >> which;
        which--;

        if (op == '+') {
            cin >> elt;
            relig[which].push_back(elt);
        }

        for (int a = (which == 0 ? size[0] : 0); a <= relig[0].size(); a++) {

            for (int b = (which == 1 ? size[1] : 0); b <= relig[1].size(); b++) {

                for (int c = (which == 2 ? size[2] : 0); c <= relig[2].size(); c++) {

                    //cout << "Extending state " << a << " " << b << " " << c << " = " << dp[a][b][c] << endl;

                    if (op == '-') {
                        dp[a][b][c] = INF;
                    } else {
                        if (dp[a][b][c] >= N) continue;
                        if (a < relig[0].size()) {
                            dp[a+1][b][c] = min(dp[a+1][b][c], jump[dp[a][b][c]][relig[0][a] - 'a']);
                        }
                        if (b < relig[1].size()) {
                            dp[a][b+1][c] = min(dp[a][b+1][c], jump[dp[a][b][c]][relig[1][b] - 'a']);
                        }
                        if (c < relig[2].size()) {
                            dp[a][b][c+1] = min(dp[a][b][c+1], jump[dp[a][b][c]][relig[2][c] - 'a']);
                        }
                    }
                }
            }
        }

        if (op == '+') {
            size[which]++;
        }
        if (op == '-') {
            relig[which].pop_back();
            size[which]--;
        }

        if (dp[size[0]][size[1]][size[2]] != INF) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        /*for (int r = 0; r < 3; r++) {
            WATCHC(relig[r]);
        }*/
    }

    return 0;
}