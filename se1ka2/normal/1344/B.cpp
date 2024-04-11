#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, m;
    cin >> n >> m;
    string s[1002];
    for(int i = 0; i < n; i++) cin >> s[i];
    bool f = true;
    bool g[2]{0};
    for(int i = 0; i < n; i++){
        int c = 0;
        for(int j = 0; j < m; j++){
            if(s[i][j] == '#' && (j == 0 || s[i][j - 1] == '.')) c++;
        }
        if(c >= 2) f = false;
        if(c == 0) g[0] = true;
    }
    for(int j = 0; j < m; j++){
        int c = 0;
        for(int i = 0; i < n; i++){
            if(s[i][j] == '#' && (i == 0 || s[i - 1][j] == '.')) c++;
        }
        if(c >= 2) f = false;
        if(c == 0) g[1] = true;
    }
    if(!f || (g[0] ^ g[1])){
        cout << "-1" << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '#'){
                ans++;
                queue<P> que;
                s[i][j] = '.';
                que.push(P(i, j));
                while(que.size()){
                    P p = que.front();
                    que.pop();
                    int x = p.first, y = p.second;
                    for(int k = 0; k < 4; k++){
                        int u = x + dx[k], v = y + dy[k];
                        if(u >= 0 && u < n && v >= 0 && v < m && s[u][v] == '#'){
                            s[u][v] = '.';
                            que.push(P(u, v));
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}