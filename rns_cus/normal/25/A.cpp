#include<stdio.h>
#define N 111
int a[N], b[N];
int abs(int x){if(x<0)return -x; return x;}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) {
        int ans1 = 0, ans2 = 0;
        for(int j = 1; j<= n; j ++)if(j != i) {
            if(abs(a[i] - a[j]) % 2 == 0) ans1 ++;
            else ans2 ++;
        }
        if(ans1 == n-1 || ans2 == n-1) {printf("%d\n", i);break;}
    }
}