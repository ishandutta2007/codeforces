#include <bits/stdc++.h>
using namespace std;
const int N = 70;
int n , m , A, B;
int f[N], s[N], id[N];
vector<pair<int, int>> e[N];
int dp[1 << 17][N], res[N];

int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}

int main() {
    cin >> n >> m >> A >> B;
    for (int i = 0 ; i < n ; ++ i) {
        f[i] = i;
        s[i] = 1;
    }
    for (int i = 0 ; i < m ; ++ i) {
        int x , y , w;
        cin >> x >> y >> w;
        -- x;
        -- y;
        e[x].emplace_back(y , w);
        e[y].emplace_back(x , w);
        if (w == A) {
            x = getf(x);
            y = getf(y);
            if (x != y) {
                f[x] = y;
                s[y] += s[x];
            }
        }
    }
    int cnt = 0;
    for (int i = 0 ; i < n ; ++ i) {
        if (getf(i) == i && s[i] > 3) {
            id[i] = 1 << cnt ++;
        }
    }
    for (int i = 0 ; i < n ; ++ i) {
        if (getf(i) != i) {
            id[i] = id[getf(i)];
        }
    }
    memset(dp , 0x3f , sizeof(dp));
    memset(res , 0x3f , sizeof(res));
    int inf = dp[0][0];
    dp[id[0]][0] = 0;
    priority_queue<pair<int , int>> Q;
    for (int k = 0 ; k < 1 << cnt ; ++ k) {
        for (int i = 0 ; i < n ; ++ i) {
            if (dp[k][i] < inf) {
                Q.push(make_pair(-dp[k][i], i));
            }
        }
        while (!Q.empty()) {
            int x = Q.top().second;
            int w = -Q.top().first;
            Q.pop();
            if (w > dp[k][x]) {
                continue;
            }
            res[x] = min(res[x] , w);
            for (auto &edge : e[x]) {
                int y = edge.first;
                int z = edge.second;
                if (z == B && ((getf(x) == getf(y)) || (k & id[y]))) {
                    continue;
                }
                int j = k | id[y];
                if (dp[j][y] > dp[k][x] + z) {
                    dp[j][y] = dp[k][x] + z;
                    if (j == k) {
                        Q.push(make_pair(-dp[j][y], y));
                    }
                }
            }
        }
    }
    for (int i = 0 ; i < n ; ++ i) {
        printf("%d%c" , res[i] , " \n"[i + 1 == n]);
    }
}