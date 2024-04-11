#include <bits/stdc++.h>
using namespace std;

const int N = 52, INF = (int)1e9;

struct edge {
    int ti, tj;
    int c;
};

int n;
int res[N][N];
int vis[N][N];
vector<edge> G[N][N];
int dp[2][N][N][N][N];

void dfs(int vi, int vj, int color) {
    vis[vi][vj] = 1;
    res[vi][vj] = color;
    for(auto e : G[vi][vj]) {
        if(!vis[e.ti][e.tj]) dfs(e.ti, e.tj, color ^ e.c);
    }
}

bool ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1<< "\n";
    fflush(stdout);
    int ans;
    cin >> ans;
    return ans == 1;
}

void set_pv(int i, int j, int &pv_i, int &pv_j) {
    if(i == 0) pv_i = i, pv_j = j - 2;
    else if(j == 0) pv_i = i - 2, pv_j = j;
    else pv_i = i - 1, pv_j = j - 1;
}

void answer(int dif) {
    cout << "!" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i + j) % 2 == 0) cout << res[i][j];
            else cout << (res[i][j] ^ dif);
        }
        cout << endl;
    }
    fflush(stdout);
    exit(0);
}

int main() {
    cin >> n;
    res[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 1 || i + j == 0) continue;
            int pv_i, pv_j;
            set_pv(i, j, pv_i, pv_j);
            int same = ask(pv_i, pv_j, i, j);
            res[i][j] = (!same) ^ res[pv_i][pv_j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0 || i + j <= 1) continue;
            int pv_i, pv_j;
            set_pv(i, j, pv_i, pv_j);
            int d = !ask(pv_i, pv_j, i, j);
            G[i][j].push_back({pv_i, pv_j, d});
            G[pv_i][pv_j].push_back({i, j, d});
        }
    }
    int d = !ask(0, 1, 2, 1);
    G[0][1].push_back({2, 1, d});
    G[2][1].push_back({0, 1, d});
    dfs(0, 1, 0);

    for(int i = 0; i < n; i += 2) {
        if(res[i][i] != res[i+2][i+2]) {
            int sum = res[i][i+1] ^ res[i][i+2] ^ res[i+1][i+2];
            int dif;
            if(sum == res[i][i]) dif = !ask(i, i, i + 1, i + 2) ^ res[i][i] ^ res[i+1][i+2];
            else dif = !ask(i, i + 1, i + 2, i + 2) ^ res[i][i+1] ^ res[i+2][i+2];
            answer(dif);
        }
    }


}