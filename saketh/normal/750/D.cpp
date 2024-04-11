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
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;

const int LIM = 350;

const int dir[8][2] = { {0, 1},
                        {1, 1},
                        {1, 0},
                        {1, -1},
                        {0, -1},
                        {-1, -1},
                        {-1, 0},
                        {-1, 1} };

void clear(vvvb &state) {
    for (vvb &grid : state)
        for (vb &row : grid)
            fill(all(row), false);
}

void step(vvvb &state, vvvb &succ, vvb &ever) {
    clear(succ);
    for (int d = 0; d < 8; d++) {
        for (int l = 0; l < LIM; l++)
            for (int r = 0; r < LIM; r++)
                if (state[d][l][r]) {
                    int ll = l + dir[d][0];
                    int rr = r + dir[d][1];
                    succ[d][ll][rr] = true;
                    ever[ll][rr] = true;
                }
    }
    swap(state, succ);
}

void end_stage(vvvb &state, vvvb &succ) {
    clear(succ);
    for (int d = 0; d < 8; d++) {
        for (int l = 0; l < LIM; l++)
            for (int r = 0; r < LIM; r++)
                if (state[d][l][r]) {
                    int d1 = (d + 1) % 8;
                    int d2 = (d + 7) % 8;
                    succ[d1][l][r] = true;
                    succ[d2][l][r] = true;
                }
    }
    swap(state, succ);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int S;
    cin >> S;

    vi stages(S);
    for (int i = 0; i < S; i++)
        cin >> stages[i];

    stages[0]--;

    vvvb state(8, vvb(LIM, vb(LIM, false)));
    vvvb temp = state;

    state[0][LIM/2][LIM/2] = true;

    vvb ever(LIM, vb(LIM, false));
    ever[LIM/2][LIM/2] = true;

    for (int s = 0; s < S; s++) {
        for (int i = 0; i < stages[s]; i++) {
            step(state, temp, ever);
        }
        end_stage(state, temp);
    }

    int ans = 0;
    for (vb &row : ever)
        for (bool elt : row)
            ans += elt;
    cout << ans << endl;

    return 0;
}