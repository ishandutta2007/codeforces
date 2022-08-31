#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[11], mx, n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%d",*max_element(a+1,a+n+1)^a[n]);
}