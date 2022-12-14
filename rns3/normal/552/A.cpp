#include<stdio.h>

int main(){
    //freopen("1.in", "r", stdin);
    int n, x, y, x1, y1;
    scanf("%d", &n);
    int ans = 0;
    for(int i=0; i<n; i++){
        scanf("%d%d%d%d", &x, &y, &x1, &y1);
        ans+=(x1-x+1)*(y1-y+1);
    }
    printf("%d\n", ans);
    return 0;
}