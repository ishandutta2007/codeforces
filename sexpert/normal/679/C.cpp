#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int comp[MAXN][MAXN], cnt[MAXN*MAXN], sz[MAXN*MAXN], xct[MAXN][MAXN], n, k, rcur, ccur, active;
char board[MAXN][MAXN];
vector<int> dx = {-1, 0, 0, 1}, dy = {0, -1, 1, 0};

void dfs(int r, int c, int col) {
    comp[r][c] = col;
    sz[col]++;
    for(int i = 0; i < 4; i++) {
        int nr = r + dx[i], nc = c + dy[i];
        if(nr < 1 || nr > n || nc < 1 || nc > n || comp[nr][nc] != 0)
            continue;
        dfs(nr, nc, col);
    }
}

int qry(int r, int c) { return xct[r][c] - xct[r - k][c] - xct[r][c - k] + xct[r - k][c - k]; }

void moveRight() {
    for(int r = rcur - k + 1; r <= rcur; r++) {
        int x = comp[r][ccur - k];
        if(x < 1) continue;
        cnt[x]--;
        if(!cnt[x])
            active -= sz[x];
    }
    int x = comp[rcur + 1][ccur - k + 1];
    if(x >= 1) {
        cnt[x]--;
        if(!cnt[x])
            active -= sz[x];
    }
    x = comp[rcur - k][ccur - k + 1];
    if(x >= 1) {
        cnt[x]--;
        if(!cnt[x])
            active -= sz[x];
    }
    ccur++;
    for(int r = rcur - k + 1; r <= rcur; r++) {
        int x = comp[r][ccur + 1];
        if(x <= 0) continue;
        if(!cnt[x])
            active += sz[x];
        cnt[x]++;
    }
    x = comp[rcur + 1][ccur];
    if(x >= 1) {
        if(!cnt[x])
            active += sz[x];
        cnt[x]++;
    }
    x = comp[rcur - k][ccur];
    if(x >= 1) {
        if(!cnt[x])
            active += sz[x];
        cnt[x]++;
    }
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> board[i][j];
            xct[i][j] = (board[i][j] == 'X') + xct[i - 1][j] + xct[i][j - 1] - xct[i - 1][j - 1];
            if(board[i][j] == 'X')
                comp[i][j] = -1;
        }
    }
    int ncomps = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(comp[i][j] == -1) continue;
            if(!comp[i][j]) dfs(i, j, ++ncomps);
        }
    }
    int ans = 0;
    for(rcur = k; rcur <= n; rcur++) {
        for(int i = 0; i < MAXN*MAXN; i++)
            cnt[i] = 0;
        active = 0;
        for(int r = rcur - k; r <= rcur + 1; r++) {
            for(int c = 0; c <= k + 1; c++) {
                if((r == rcur - k && c == 0) || (r == rcur + 1 && c == 0) || (r == rcur - k && c == k + 1) || (r == rcur + 1 && c == k + 1))
                    continue;
                if(comp[r][c] <= 0) continue;
                int x = comp[r][c];
                if(!cnt[x])
                    active += sz[x];
                cnt[x]++;
            }
        }
        ccur = k;
        while(ccur <= n) {
            ans = max(ans, qry(rcur, ccur) + active);
            moveRight();
        }
    }
    cout << ans << endl;
}