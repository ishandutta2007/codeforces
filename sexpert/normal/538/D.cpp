#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

char grid[55][55];
char grid2[55][55];
char ans[105][105];
vector<ii> pos;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'o') {
                pos.push_back({i, j});
            }
        }
    }

    for(int i = 0; i < 2*n - 1; i++) {
        for(int j = 0; j < 2*n - 1; j++) {
            ans[i][j] = '.';
        }
    }
    ans[n - 1][n - 1] = 'o';

    for(int dx = -n + 1; dx < n; dx++) {
        for(int dy = -n + 1; dy < n; dy++) {
            if(dx == 0 && dy == 0)
                continue;
            bool good = true;
            for(auto p : pos) {
                int nx = p.first + dx, ny = p.second + dy;
                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if(grid[nx][ny] == '.') {
                    good = false;
                    break;
                }
            }
            if(good)
                ans[dx + n - 1][dy + n - 1] = 'x';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            grid2[i][j] = '.';
            if(grid[i][j] == 'o')
                grid2[i][j] = 'o'; 
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid2[i][j] != 'o')
                continue;
            for(int dx = -n + 1; dx < n; dx++) {
                for(int dy = -n + 1; dy < n; dy++) {
                    if(ans[dx + n - 1][dy + n - 1] != 'x')
                        continue;
                    int nx = i + dx, ny = j + dy;
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid2[nx][ny] == '.')
                        grid2[nx][ny] = 'x';
                }
            }
        }
    }

    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid2[i][j];
        }
        cout << '\n';
    }*/

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] != grid2[i][j]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    for(int i = 0; i < 2*n - 1; i++) {
        for(int j = 0; j < 2*n - 1; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}