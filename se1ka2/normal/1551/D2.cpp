#include <iostream>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int dir[102][102];
char ans[102][102];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int nn = n, mm = m;
        if(m % 2){
            for(int i = 0; i < n; i++){
                if(i % 2) dir[i][m - 1] = 2;
                else dir[i][m - 1] = 0;
            }
            mm--;
        }
        if(n % 2){
            for(int j = 0; j < m; j++){
                if(j % 2) dir[n - 1][j] = 3;
                else dir[n - 1][j] = 1;
            }
            k -= m / 2;
            nn--;
        }
        if(k < 0 || k > nn * mm / 2 || k % 2){
            cout << "NO" << endl;
            continue;
        }
        else cout << "YES" << endl;
        for(int j = 0; j < mm; j += 2){
            for(int i = 0; i < nn; i++){
                if(k){
                    dir[i][j] = 1;
                    dir[i][j + 1] = 3;
                    k--;
                }
                else if(i % 2) dir[i][j] = dir[i][j + 1] = 2;
                else dir[i][j] = dir[i][j + 1] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) ans[i][j] = '?';
        }
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                if(ans[x][y] != '?') continue;
                bool b[30]{0};
                for(int c = 0; c < 2; c++){
                    x += dx[dir[x][y]];
                    y += dy[dir[x][y]];
                    for(int i = 0; i < 4; i++){
                        int u = x + dx[i], v = y + dy[i];
                        if(u >= 0 && u < n && v >= 0 && v < m && ans[u][v] != '?'){
                            b[ans[u][v] - 'a'] = true;
                        }
                    }
                }
                for(int i = 0; i < 26; i++){
                    if(!b[i]){
                        ans[x][y] = ans[x + dx[dir[x][y]]][y + dy[dir[x][y]]] = char('a' + i);
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << ans[i][j];
            cout << endl;
        }
    }
}