#include<stdio.h>

int main()
{
    int n, m, k = 0, sum = 0, c[26] = {}, a[11111], b[11111], i, j, x;
    char p[2], s[111][111];
    scanf("%d%d", &m, &n);
    scanf("%s", p);
    c[p[0] - 'A'] = 1;
    for(i = 0; i < m; i ++) {
            scanf("%s", s[i]);
            for(j = 0; j < n; j ++)
                if(s[i][j] == p[0]) a[++k] = i, b[k] = j;
    }

    for(i = 1; i <= k; i ++) {
        if(a[i] + 1 < m && s[a[i] + 1][b[i]] != '.') {
            x = s[a[i] + 1][b[i]] - 'A';
            c[x] = 1;
        }
        if(a[i] - 1 >= 0 && s[a[i] - 1][b[i]] != '.') {
            x = s[a[i] - 1][b[i]] - 'A';
            c[x] = 1;
        }
        if(b[i] + 1 < n && s[a[i]][b[i] + 1] != '.') {
            x = s[a[i]][b[i] + 1] - 'A';
            c[x] = 1;
        }
        if(b[i] - 1 >= 0 && s[a[i]][b[i] - 1] != '.') {
            x = s[a[i]][b[i] - 1] - 'A';
            c[x] = 1;
        }
    }
    for(i = 0; i < 26; i ++) sum += c[i];
    printf("%d\n", sum - 1);
}