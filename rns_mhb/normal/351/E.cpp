#include <stdio.h>
#define M 2001
int a[M];

int main(){
    //freopen("Ee.in", "r", stdin);
    int i, j, k, ans=0, n;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", a+i);
        if(a[i]<0)a[i]=-a[i];
    }
    for(i=0; i<n; i++){
        int x=0, y=0;
        for(j=0; j<n; j++)if(a[i]>a[j]){
            if(i>j)x++;else if(i<j)y++;
        }
        if(x>y)x=y;
        ans += x;
    }
    printf("%d\n", ans);
}