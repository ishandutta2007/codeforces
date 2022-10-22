#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

string bd[1100];
int when[1100][1100];

int n,m,t;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        cin >> bd[i];
    }

    queue< pair<int,int> > q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            when[i][j] = -1;
            for (int d = 0; d < 4; d++) {
                int ni = i+dx[d];
                int nj = j+dy[d];
                if (ok(ni,nj) && bd[i][j]==bd[ni][nj]) {
                    when[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int i = cur.first, j = cur.second;
        for (int d = 0; d < 4; d++) {
            int ni = i+dx[d];
            int nj = j+dy[d];
            if (ok(ni,nj) && when[ni][nj] == -1) {
                when[ni][nj] = when[i][j] + 1;
                q.push({ni,nj});
            }
        }
    }

    for (; t; t--) {
        int i, j;
        long long k;
        cin >> i >> j >> k; i--; j--;

        long long ch = 0;
        if (when[i][j] != -1 && when[i][j] < k) ch = (k - when[i][j])%2;
        
        if (ch) cout << (char)(bd[i][j]^1) << '\n';
        else cout << bd[i][j] << '\n';
    }

    return 0;
}