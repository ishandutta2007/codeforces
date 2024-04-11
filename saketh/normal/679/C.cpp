#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;

void dfs(int R, int C, vector<vector<char>> &grid, vector<vector<int>> &comp, int cnum, int &csize, int r, int c) {
    if (r < 0 || c < 0) return;
    if (r >= R || c >= C) return;
    if (comp[r][c] != -1) return;
    if (grid[r][c] != '.') return;

    comp[r][c] = cnum;
    csize++;

    array<int, 2> dir[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (auto d : dir) {
        dfs(R, C, grid, comp, cnum, csize, r + d[0], c + d[1]);
    }
}

void upd(vector<int> &pres, vector<int> &csize, int &tot_pres, int inx, int ch) {
    if (inx == -1) return;
    if (ch == -1 && pres[inx] == 1) tot_pres -= csize[inx];
    if (ch == 1 && pres[inx] == 0) tot_pres += csize[inx];
    pres[inx] += ch;
}

#define inc(x) upd(pres, compsize, tot_pres, x, 1)
#define dec(x) upd(pres, compsize, tot_pres, x, -1)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, K;
    cin >> N >> K;

    int R = N, C = N;
    vector<vector<char>> grid(R, vector<char>(C));
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            cin >> grid[r][c];

    for (auto p : grid) {
        WATCHC(p);
    }

    vector<vector<int>> comp(R, vector<int>(C, -1));
    vector<int> compsize;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (comp[r][c] != -1) continue;
            if (grid[r][c] != '.') continue;
            compsize.push_back(0);
            dfs(R, C, grid, comp, compsize.size() - 1, compsize.back(), r, c);
        }
    }

    int ans = 0;

    for (int r = 0; r + K <= R; r++) {
        vector<int> pres(compsize.size(), 0);
        int tot_pres = 0;
        int blocked = 0;

        for (int r2 = r; r2 < r + K; r2++) {
            for (int c = 0; c < K; c++) {
                if (comp[r2][c] == -1) blocked++;
                else inc(comp[r2][c]);
            }
        }

        if (r > 0)
            for (int c = 0; c < K; c++)
                inc(comp[r-1][c]);

        if (r + K < R)
            for (int c = 0; c < K; c++)
                inc(comp[r+K][c]);

        if (K < C)
            for (int r2 = r; r2 < r + K; r2++)
                inc(comp[r2][K]);

        ans = max(ans, tot_pres + blocked);

        TRACE(cout << "For picking " << r << " " << 0 << " we get " << tot_pres + blocked << endl);

        for (int c = 1; c + K <= C; c++) {
            if (r > 0) {
                dec(comp[r-1][c-1]);
                inc(comp[r-1][c+K-1]);
            }
            if (r + K < R) {
                dec(comp[r+K][c-1]);
                inc(comp[r+K][c+K-1]);
            }
            if (c >= 2) {
                for (int r2 = r; r2 < r + K; r2++)
                    dec(comp[r2][c-2]);
            }
            if (c + K < C) {
                for (int r2 = r; r2 < r + K; r2++)
                    inc(comp[r2][c+K]);
            }

            for (int r2 = r; r2 < r + K; r2++) {
                if (comp[r2][c-1] == -1) blocked--;
                if (comp[r2][c+K-1] == -1) blocked++;
            }

            TRACE(cout << "For picking " << r << " " << c << " we get " << tot_pres + blocked << endl);

            ans = max(ans, tot_pres + blocked);
        }
    }

    cout << ans << endl;
    return 0;
}