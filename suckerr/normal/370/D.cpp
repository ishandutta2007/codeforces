#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

const int N = 2222;
const int inf = 10000000;

char map[N][N], mmp[N][N];
int n, m, size;

int solve(int w1, int w2, int u, int d, int l, int r) {
    if (w1 == 0) {
        r = l + size;
        if (r > m) {
            r = m;
            l = r - size;
        }
    } else {
        l = r - size;
        if (l <= 0) {
            l = 1;
            r = l + size;
        }
    }
    
    if (w2 == 0) {
        d = u + size;
        if (d > n) {
            d = n;
            u = d - size;
        }
    } else {
        u = d - size;
        if (u <= 0) {
            u = 1;
            d = u + size;
        }
    }
    
    if (u <= 0 || l <= 0 || r > m || d > n)
        return 0;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            mmp[i][j] = map[i][j];
    
    for(int i = l; i <= r; i++) {
        mmp[u][i] = mmp[d][i] = '+';
    }
    
    for(int i = u; i <= d; i++) {
        mmp[i][l] = mmp[i][r] = '+';
    }
    
    bool flag = true;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if (map[i][j] == 'w' && mmp[i][j] != '+') {
                return 0;
            }
        }
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if (mmp[i][j] == '+' && map[i][j] != 'w')
                map[i][j] = '+';            
        }

    return 1;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", map[i] + 1);
    }   
    int l = inf, r = -inf, d = -inf, u = inf;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if (map[i][j] == 'w') {
                l = min(l, j);
                r = max(r, j);
                d = max(d, i);
                u = min(u, i);
            }
        }
    
    size = max(r - l, d - u);
    
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++) {
            if (solve(i, j, u, d, l, r)) {
                for(int k = 1; k <= n; k++)
                    puts(map[k] + 1);
                exit(0);
            }
        }
    printf("-1\n");
        
    return 0;
}