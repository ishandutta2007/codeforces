#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ans = 0;
    char a[111][111];
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
        gets(a[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int j2 = j + 1; j2 < n; j2++) {
                if (a[i][j] == 'C' && a[i][j2] == 'C')
                    ans++;
                if (a[j][i] == 'C' && a[j2][i] == 'C')
                    ans++;
            }
    printf("%d", ans);
}