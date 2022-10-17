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

    auto bfs = [](int rr, int rc) {
        vi par(64, -1), dist(64);
        par[8 * rr + rc] = 8 * rr + rc;
        for (queue<int> q({ 8 * rr + rc }); !q.empty(); q.pop()) {
            int loc = q.front();
            int r = loc / 8, c = loc % 8;
            for (int dx = -2; dx <= 2; dx++) {
                for (int dy = -2; dy <= 2; dy++) {
                    if (abs(dx) == 0 || abs(dy) == 0 || abs(dx) + abs(dy) != 3)
                        continue;
                    int nr = r + dx, nc = c + dy;
                    if (nr < 0 || nc < 0 || nr >= 8 || nc >= 8)
                        continue;
                    if (par[8 * nr + nc] != -1)
                        continue;

                    par[8 * nr + nc] = loc;
                    dist[8 * nr + nc] = 1 + dist[loc];
                    q.push(8 * nr + nc);
                }
            }
        }
        // WATCHC(dist);
        return par;
    };

    vvi trees(64);
    for (int r = 0; r < 64; r++) {
        trees[r] = bfs(r / 8, r % 8);
    }

    vs enc(64, "..");
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            enc[8 * r + c][0] = 'a' + c;
            enc[8 * r + c][1] = '1' + r;
        }
    }

    vb board(64);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char col, row;
        cin >> col >> row;

        int r = row - '1';
        int c = col - 'a';

        board[8 * r + c] = true;
    }

    vector<string> moves;
    auto move = [&](int i, int j) {
        vi seq = { j };
        for (int t = j; seq.back() != i; )
            seq.push_back(t = trees[i][t]);
        reverse(all(seq));

        int l = 0;
        for (int x = 1, y; x < seq.size(); x++) {
            if (board[seq[x]]) {
                for (int y = x; y > l; y--) {
                    moves.push_back(enc[seq[y]] + "-" + enc[seq[y-1]]);
                }
                l = x;
            }
        }

        swap(board[i], board[j]);
    };

    for (int i = 0, j; i < N; i++) {
        if (board[i]) continue;
        for (j = N; !board[j]; j++);
        move(i, j);
    }

    cout << moves.size() << "\n";
    for (string m : moves)
        cout << m << "\n";
    return 0;

    return 0;
}