#include <bits/stdc++.h>
using namespace std;

const int K = 9, N = 2005, M = (int)1e5 + 50;

struct P {
    int x, y;
};

int n, m, k, s;
int mp[N][N];
P loc[K][K];
int num[M];
int di[3] = {-1, 0, 1};

int getval(int i, int j, int t) {
    return i * di[t / 3] + j * di[t % 3];
}

int dis(P &p1, P &p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k >> s;
    memset(loc, -1, sizeof(loc));
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < K; j++) loc[i][j].x = loc[i][j].y = -1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mp[i][j], mp[i][j]--;
            for(int t = 0; t < K; t++) {
                P &p = loc[mp[i][j]][t];
                if(p.x == -1 || getval(i, j, t) > getval(p.x, p.y, t)) {
                    p.x = i, p.y = j;
                }
            }
        }
    }
    for(int i = 0; i < s; i++) cin >> num[i], num[i]--;
    int nw = 1, la = 0;
    int res = 0;
    for(int i = 1; i < s; i++) {
        for(int j = 0; j < K; j++) {
            for(int t = 0; t < K; t++) {
                res = max(res, dis(loc[num[i]][j], loc[num[i-1]][t]));
            }
        }
    }
    cout << res << endl;
}