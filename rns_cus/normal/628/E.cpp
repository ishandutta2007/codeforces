#include <bits/stdc++.h>
using namespace std;

#define N 3030
#define M 6060

int n, m, a[N][N], b[N][N], f[N][N], x[M];
char s[N][N];
long long ans;
vector <int> v[N];

void add(int r) {
    while(r) {
        x[r] ++;
        r -= r&-r;
    }
}

int calc(int r) {
    int rt = 0;
    while(r < M) {
        rt += x[r];
        r += r&-r;
    }
    return rt;
}

int main() {
    scanf("%d %d\n", &n, &m);
    for(int i = 0; i < n;i ++) gets(s[i]);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            a[i][j] = s[i][j] == 'z';
            if(j && a[i][j]) a[i][j] += a[i][j-1];
        }
        for(int j = m - 1; j >= 0; j --) {
            b[i][j] = s[i][j] == 'z';
            if(j < m - 1 && b[i][j]) b[i][j] += b[i][j+1];
            f[i][j] = s[i][j] == 'z';
            if(f[i][j] && i && j < m - 1) f[i][j] += f[i-1][j+1];
        }
    }
    for(int i = 0; i < n; i ++) for(int j = 0; j < m; j ++) if(f[i][j] > b[i][j]) f[i][j] = b[i][j];
    for(int k = 0; k < n + m - 1; k ++) {
        for(int i = 0; i < n; i ++) v[i].clear();
        memset(x, 0, sizeof(x));
        for(int i = 0; i <= k; i ++) {
            int j = k - i;
            if(i >= n || j >= m || s[i][j] == '.') continue;
            if(i >= f[i][j]) v[i-f[i][j]].push_back(i + 1);
        }
        for(int i = 0; i <= k; i ++) {
            int j = k - i;
            if(i >= n || j >= m) continue;
            if(s[i][j] == 'z') {
                add(i + a[i][j]);
                ans += calc(i + 1);
            }
            for(int r = 0; r < v[i].size(); r ++) {
                ans -= calc(v[i][r]);
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}