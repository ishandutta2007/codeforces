#include<bits/stdc++.h>
using namespace std;

int a[100010];

int main() {
    int n, i, rlt = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; i ++) {
        scanf("%d", a + i);
        a[i] += a[i - 1];
    }
    for(i = 1; i < n; i ++) if(a[i] * 2 == a[n]) rlt ++;
    printf("%d", rlt);
}