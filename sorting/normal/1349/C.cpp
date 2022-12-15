#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t;
    cin >> n >> m >> t;

    const int k_N = 1e3 + 7;
    static string s[k_N];
    static bool b[k_N][k_N], visited[k_N][k_N];
    static int iterations[k_N][k_N];

    for(int i = 0; i < n; ++i)
        cin >> s[i];

    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            array<pair<int, int>, 4> adjacent{pair{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
            for(auto [x_to, y_to]: adjacent){
                if(x_to < 0 || x_to > n - 1 || y_to < 0 || y_to > m - 1)
                    continue;

                if(s[x][y] == s[x_to][y_to]){
                    b[x][y] = true;
                    break;
                }
            }
        }
    }

    queue<pair<int, int>> bfs;
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            if(b[x][y]){
                bfs.push({x, y});
                visited[x][y] = true;
                iterations[x][y] = 1;
            }
        }
    }

    if(bfs.empty()){
        for(int i = 0; i < t; ++i){
            int x, y;
            long long p;
            cin >> x >> y >> p;
            --x;
            --y;

            cout << s[x][y] << "\n";
        }
        return 0;
    }

    while(!bfs.empty()){
        auto [x, y] = bfs.front();
        bfs.pop();

        array<pair<int, int>, 4> adjacent{pair{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
        for(auto [x_to, y_to]: adjacent){
            if(x_to < 0 || x_to > n - 1 || y_to < 0 || y_to > m - 1)
                continue;

            if(!visited[x_to][y_to]){
                visited[x_to][y_to] = true;
                iterations[x_to][y_to] = iterations[x][y] + 1;
                bfs.push({x_to, y_to});
            }
        }
    }

    for(int i = 0; i < t; ++i){
        int x, y;
        long long p;
        cin >> x >> y >> p;
        --x;
        --y;

        if(p < iterations[x][y]){
            cout << s[x][y] << "\n";
            continue;
        }
        if((p - iterations[x][y]) & 1){
            cout << s[x][y] << "\n";
            continue;
        }

        if(s[x][y] == '1')
            cout << "0\n";
        else
            cout << "1\n";
    }
}