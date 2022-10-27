#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char s[5002];
int a[5002], b[5002];
int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i ++) {
        a[i] = a[i-1], b[i] = b[i-1];
        if (s[i] == 'a') a[i] ++;
        if (s[i] == 'b') b[i] ++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            // [1, i) [i, j] (j, n]
            int tmp = a[i-1] + (a[n] - a[j]) + (b[j] - b[i-1]);
            if (tmp > ans) ans = tmp;
        }
    }
    ans = max(ans, a[n]);
    ans = max(ans, b[n]);
    printf("%d", ans);

}