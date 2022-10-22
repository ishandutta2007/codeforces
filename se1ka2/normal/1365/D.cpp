#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        char c[52][52];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> c[i][j];
            }
        }
        bool f = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(c[i][j] == 'B'){
                    for(int k = 0; k < 4; k++){
                        int x = i + dx[k], y = j + dy[k];
                        if(x >= 0 && x < n && y >= 0 && y < m){
                            if(c[x][y] == '.') c[x][y] = '#';
                            else if(c[x][y] == 'G') f = false;
                        }
                    }
                }
            }
        }
        queue<P> que;
        if(c[n - 1][m - 1] != '#') que.push(P(n - 1, m - 1));
        bool used[52][52];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) used[i][j] = false;
        }
        while(que.size()){
            P p = que.front();
            que.pop();
            int x = p.first, y = p.second;
            for(int i = 0; i < 4; i++){
                int u = x + dx[i], v = y + dy[i];
                if(u >= 0 && u < n && v >= 0 && v < m && !used[u][v] && c[u][v] != '#'){
                    used[u][v] = true;
                    que.push(P(u, v));
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(c[i][j] == 'G' && !used[i][j]) f = false;
            }
        }
        if(f) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}