#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (string &str : grid)
        cin >> str;

    vector<array<int, 26>> ctable(3); vi ccount(3);
    auto clear = [&](int i) { ctable[i].fill(0); ccount[i] = 0; };
    auto ins = [&](int i, char c) { if (!ctable[i][c-'a']++) ccount[i]++; };
    auto del = [&](int i, char c) { if (!--ctable[i][c-'a']) ccount[i]--; };

    ll ans = 0;

    vi streak(N, 0);
    for (int c = 0; c < M; c++) {
        for (int r = 0; r < N; r++) {
            if (c > 0 && grid[r][c] == grid[r][c-1])
                streak[r]++;
            else streak[r] = 1;
        }

        for (int fb = 1; fb < N; fb++) {
            int md = INT_MAX;
            clear(0); clear(1); clear(2);

            for (int ln = 1; ln <= fb && fb + 2 * ln <= N; ln++) {
                md = min(md, streak[fb - ln]);
                md = min(md, streak[fb + 2 * ln - 2]);
                md = min(md, streak[fb + 2 * ln - 1]);

                ins(0, grid[fb - ln][c]);
                ins(1, grid[fb + ln - 1][c]);
                if (ln > 1) {
                    del(2, grid[fb + ln - 1][c]);
                    ins(2, grid[fb + 2 * ln - 2][c]);
                }
                ins(2, grid[fb + 2 * ln - 1][c]);

                if (ccount[0] > 1 || ccount[1] > 1) break;
                if (grid[fb - ln][c] == grid[fb + ln - 1][c]) break;

                if (ccount[2] == 1 && grid[fb + ln - 1][c] != grid[fb + 2 * ln - 1][c]) {
                    ans += md;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}