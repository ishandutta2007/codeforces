#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, k = 0, c[300] = {}, a[300], q[10];
    scanf("%d", &n);
    for(i = 1; i <= n; i ++) {
        scanf("%d", a + i);
        c[a[i]] ++;
        if(c[a[i]] == 1) {
                q[++ k] = a[i];
        }
    }
    if(k != 2 || c[q[1]] != c[q[2]]) printf("NO\n");
    else {
        printf("YES\n");
        printf("%d %d\n", q[1], q[2]);
    }
}