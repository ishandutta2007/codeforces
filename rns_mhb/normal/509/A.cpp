#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, a[11][11], j;
    for(i = 1; i < 11; i ++) a[1][i] = a[i][1] = 1;
    for(i = 2; i < 11; i ++) for (j = 2; j < 11; j ++) a[i][j] = a[i - 1][j] + a[i][j - 1];
    int n;
    scanf("%d", &n);
    printf("%d\n", a[n][n]);
}