#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int d[2002][2002];

int main()
{
    int n, m;
    cin >> n >> m;
    string s[2005];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    queue<P> que;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                que.push(P(i, j));
                d[i][j] = 1;
            }
            else{
                for(int k = 0; k < 4; k++){
                    int x = i + dx[k], y = j + dy[k];
                    if(s[i][j] != s[x][y]){
                        que.push(P(i, j));
                        d[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }
    while(que.size()){
        P p = que.front();
        que.pop();
        int x = p.first, y = p.second;
        for(int i = 0; i < 4; i++){
            int u = x + dx[i], v = y + dy[i];
            if(u >= 0 && u < n && v >= 0 && v < m && d[u][v] == 0){
                d[u][v] = d[x][y] + 1;
                que.push(P(u, v));
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans += d[i][j];
        }
    }
    cout << ans << endl;
}