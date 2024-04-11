#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
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

// builds sequence of moves to get cube i to (i, i) for all i
vector<array<int, 4>> solve(int N, int M, vi &cx, vi &cy) {
    vector<array<int, 4>> res;

    vvi grid(N, vi(N, -1));
    for (int i = 0; i < M; i++)
        grid[cx[i]][cy[i]] = i;

    auto move = [&](int x1, int y1, int x2, int y2) {
        int cube = grid[x1][y1];
        assert(cube != -1);
        assert(grid[x2][y2] == -1);
        res.push_back({ x1, y1, x2, y2 });
        swap(grid[x1][y1], grid[x2][y2]);
        cx[cube] = x2, cy[cube] = y2;
    };

    // Phase 1: make all the x coordinates distinct
    vi order(M);
    for (int i = 0; i < M; i++)
        order[i] = i;
    sort(all(order), [&](int i, int j) {
        return cx[i] < cx[j];
    });

    vi xdest(M);
    for (int i = 0; i < M; i++)
        xdest[order[i]] = i;

    for (int y = 0; y < N; y++) {
        vi col;
        for (int i : order)
            if (cy[i] == y)
                col.push_back(i);

        while (true) {
            bool moved = false;
            for (int i : col) {
                if (cx[i] == xdest[i]) continue;
                int nx = (xdest[i] < cx[i]) ? cx[i] - 1 : cx[i] + 1;
                if (grid[nx][cy[i]] == -1) {
                    move(cx[i], cy[i], nx, cy[i]);
                    moved = true;
                    break;
                }
            }
            if (!moved) break;
        }
    }

    // Phase 2: Move everyone to their final y-coordinate
    for (int i = 0; i < M; i++) {
        while (cy[i] != i)
            move(cx[i], cy[i], cx[i], cy[i] > i ? cy[i] - 1 : cy[i] + 1);
    }

    // Phase 3: Move everyone to their final x-coordinate
    for (int i = 0; i < M; i++) {
        while (cx[i] != i)
            move(cx[i], cy[i], cx[i] > i ? cx[i] - 1 : cx[i] + 1, cy[i]);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    auto get_moves = [&]() {
        vi x(M), y(M);
        for (int i = 0; i < M; i++) {
            cin >> x[i] >> y[i];
            x[i]--, y[i]--;
        }
        return solve(N, M, x, y);
    };

    auto a = get_moves(), b = get_moves();
    cout << a.size() + b.size() << "\n";

    for (auto e : a) {
        for (int v : e)
            cout << v + 1 << " ";
        cout << "\n";
    }

    reverse(all(b));
    for (auto e : b) {
        cout << e[2]+1 << " " << e[3]+1 << " " << e[0]+1 << " " << e[1]+1 << "\n";
    }

    return 0;
}