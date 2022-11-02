#include<bits/stdc++.h>
using namespace std;

int a[150010];

int main() {
    int t, n;
    scanf("%d", &t);
    while(t --) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        int ans = 0;
        for(int i = n - 1; i; i --) {
            if(a[i] > a[i+1]) ans ++;
            a[i] = min(a[i], a[i+1]);
        }
        printf("%d\n", ans);
    }
}