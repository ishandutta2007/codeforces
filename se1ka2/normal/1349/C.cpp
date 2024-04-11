#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

string c[1003];
int d[1002][1002];
int p[1002][1002];

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) cin >> c[i];
    queue<P> que;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) d[i][j] = p[i][j] = -1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 1; j++){
            if(c[i][j] == c[i][j + 1]){
                if(d[i][j] == -1){
                    d[i][j] = 0;
                    p[i][j] = c[i][j] - '0';
                    que.push(P(i, j));
                }
                if(d[i][j + 1] == -1){
                    d[i][j + 1] = 0;
                    p[i][j + 1] = c[i][j + 1] - '0';
                    que.push(P(i, j + 1));
                }
            }
        }
    }
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n - 1; i++){
            if(c[i][j] == c[i + 1][j]){
                if(d[i][j] == -1){
                    d[i][j] = 0;
                    p[i][j] = c[i][j] - '0';
                    que.push(P(i, j));
                }
                if(d[i + 1][j] == -1){
                    d[i + 1][j] = 0;
                    p[i + 1][j] = c[i + 1][j] - '0';
                    que.push(P(i + 1, j));
                }
            }
        }
    }
    while(que.size()){
        P q = que.front();
        que.pop();
        int x = q.first, y = q.second;
        for(int i = 0; i < 4; i++){
            int u = x + dx[i], v = y + dy[i];
            if(u >= 0 && u < n && v >= 0 && v < m && d[u][v] == -1){
                d[u][v] = d[x][y] + 1;
                p[u][v] = p[x][y];
                que.push(P(u, v));
            }
        }
    }
    while(t--){
        int x, y;
        ll q;
        cin >> x >> y >> q;
        x--; y--;
        if(d[x][y] >= q || d[x][y] == -1) cout << c[x][y] << endl;
        else cout << (p[x][y] + q) % 2 << endl;
    }
}