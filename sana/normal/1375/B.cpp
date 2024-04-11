#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t,n,m;
int grid[310][310];

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (cin >> t; t; t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int tgt = 0;
                for (int d = 0; d < 4; d++) {
                    int ni = i+dx[d], nj = j+dy[d];

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) tgt++;
                }
                
                if (grid[i][j] > tgt) ok = false;
                grid[i][j] = tgt;
            }
        }

        if (!ok) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << grid[i][j] << " ";
                }
                cout << '\n';
            }
        }
    }

    return 0;
}