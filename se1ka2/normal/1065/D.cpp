#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int INF = 100000000;
const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

P dp[102][3];

int main()
{
    int n;
    cin >> n;
    int a[12][12];
    P r[102];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        cin >> a[i][j];
        a[i][j]--;
        r[a[i][j]] = P(i, j);
    }
    for(int i = 1; i < n * n; i++) for(int j = 0; j < 3; j++) dp[i][j] = P(INF, INF);
    for(int i = 1; i < n * n; i++){
        if(r[i].first == r[i - 1].first || r[i].second == r[i - 1].second){
            for(int j = 0; j < 3; j++){
                if(j == 0) dp[i][0] = min(dp[i][0], P(dp[i - 1][j].first + 1, dp[i - 1][j].second));
                else dp[i][0] = min(dp[i][0], P(dp[i - 1][j].first + 2, dp[i - 1][j].second + 1));
            }
        }
        else{
            for(int j = 0; j < 3; j++){
                if(j == 0) dp[i][0] = min(dp[i][0], P(dp[i - 1][j].first + 2, dp[i - 1][j].second));
                else dp[i][0] = min(dp[i][0], P(dp[i - 1][j].first + 3, dp[i - 1][j].second + 1));
            }
        }
        
        if(abs(r[i].first - r[i - 1].first) == abs(r[i].second - r[i - 1].second)){
            for(int j = 0; j < 3; j++){
                if(j == 1) dp[i][1] = min(dp[i][1], P(dp[i - 1][j].first + 1, dp[i - 1][j].second));
                else dp[i][1] = min(dp[i][1], P(dp[i - 1][j].first + 2, dp[i - 1][j].second + 1));
            }
        }
        else if(abs(r[i].first + r[i - 1].first + r[i].second + r[i - 1].second) % 2 == 0){
            for(int j = 0; j < 3; j++){
                if(j == 1) dp[i][1] = min(dp[i][1], P(dp[i - 1][j].first + 2, dp[i - 1][j].second));
                else dp[i][1] = min(dp[i][1], P(dp[i - 1][j].first + 3, dp[i - 1][j].second + 1));
            }
        }
        else{
            dp[i][1] = min(dp[i][1], P(dp[i - 1][0].first + 3, dp[i - 1][0].second + 1));
            dp[i][1] = min(dp[i][1], P(dp[i - 1][1].first + 4, dp[i - 1][1].second + 2));
            for(int j = 0; j < 8; j++){
                int x = r[i - 1].first + dx[j], y = r[i - 1].second + dy[j];
                if(x >= 0 && x < n && y >= 0 && y < n && abs(x - r[i].first) == abs(y - r[i].second))
                    dp[i][1] = min(dp[i][1], P(dp[i - 1][2].first + 3, dp[i - 1][2].second + 1));
            }
            if(!(n == 3 && r[i - 1] == P(1, 1)))
                dp[i][1] = min(dp[i][1], P(dp[i - 1][2].first + 4, dp[i - 1][2].second + 1));
        }
        
        if(n == 3 && r[i] == P(1, 1)) continue;
        for(int j = 0; j < 8; j++){
            int x = r[i].first + dx[j], y = r[i].second + dy[j];
            if(x >= 0 && x < n && y >= 0 && y < n && (x == r[i - 1].first || y == r[i - 1].second))
                dp[i][2] = min(dp[i][2], P(dp[i - 1][0].first + 3, dp[i - 1][0].second + 1));
        }
        dp[i][2] = min(dp[i][2], P(dp[i - 1][0].first + 4, dp[i - 1][0].second + 1));
        for(int j = 0; j < 8; j++){
            int x = r[i].first + dx[j], y = r[i].second + dy[j];
            if(x >= 0 && x < n && y >= 0 && y < n && abs(x - r[i - 1].first) == abs(y - r[i - 1].second))
                dp[i][2] = min(dp[i][2], P(dp[i - 1][1].first + 3, dp[i - 1][1].second + 1));
        }
        if(abs(r[i].first + r[i - 1].first + r[i].second + r[i - 1].second) % 2 == 0)
            dp[i][2] = min(dp[i][2], P(dp[i - 1][1].first + 4, dp[i - 1][1].second + 1));
        else
            dp[i][2] = min(dp[i][2], P(dp[i - 1][1].first + 5, dp[i - 1][1].second + 1));
        queue<P> que;
        int c[12][12];
        for(int k = 0; k < n; k++) for(int j = 0; j < n; j++) c[k][j] = -1;
        que.push(P(r[i].first, r[i].second));
        c[r[i].first][r[i].second] = 0;
        while(que.size()){
            P p = que.front();
            que.pop();
            for(int j = 0; j < 8; j++){
                int x = p.first + dx[j], y = p.second + dy[j];
                if(x >= 0 && x < n && y >= 0 && y < n && c[x][y] == -1){
                    c[x][y] = c[p.first][p.second] + 1;
                    que.push(P(x, y));
                }
            }
        }
        int d = c[r[i - 1].first][r[i - 1].second];
        if(d == -1) continue;
        for(int j = 0; j < 3; j++){
            if(j == 2) dp[i][2] = min(dp[i][2], P(dp[i - 1][j].first + d, dp[i - 1][j].second));
            else dp[i][2] = min(dp[i][2], P(dp[i - 1][j].first + d + 1, dp[i - 1][j].second + 1));
        }
        
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++) dp[i][j] = min(dp[i][j], P(dp[i][k].first + 1, dp[i][k].second + 1));
        }
    }
    P ans = P(INF, INF);
    for(int j = 0; j < 3; j++) ans = min(ans, dp[n * n - 1][j]);
    cout << ans.first << " " << ans.second << endl;
}