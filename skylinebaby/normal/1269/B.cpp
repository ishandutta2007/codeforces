#include<bits/stdc++.h>
using namespace std;
int a[2123];
int b[2123];
int c[2123];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    sort(b, b + n);
    int ans = m;
    for(int i = 0; i < n; i++)
    {
        int x = b[i] + m - a[0];
        x = x % m;
        for(int i = 0; i < n; i++) c[i] = (a[i] + x) % m;
        sort(c, c + n);
        int flag = 0;
        for(int i = 0; i < n; i++) if (b[i] != c[i]) flag = 1;
        if(flag == 0) ans = min(ans, x);    
    }
    printf("%d\n", ans);
    return 0;
}