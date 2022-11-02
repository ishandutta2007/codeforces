#include<bits/stdc++.h>
using namespace std;

#define N 555

char a[N][N], b[N][N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) scanf("%d", &b[i][j]);
    for(int i = 1; i <= n; i ++) {
        int cnt1 = 0, cnt2 = 0;
        for(int j = 1; j <= m; j ++) cnt1 += a[i][j];
        for(int j = 1; j <= m; j ++) cnt2 += b[i][j];
        cnt1 %= 2, cnt2 %= 2;
        if(cnt1 != cnt2) {
            puts("No");
            return 0;
        }
    }
    for(int i = 1; i <= m; i ++) {
        int cnt1 = 0, cnt2 = 0;
        for(int j = 1; j <= n; j ++) cnt1 += a[j][i];
        for(int j = 1; j <= n; j ++) cnt2 += b[j][i];
        cnt1 %= 2, cnt2 %= 2;
        if(cnt1 != cnt2) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
}