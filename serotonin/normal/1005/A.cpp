#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int n,a[1005],ans[1005],i,x=0,j;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
        if(a[i]==1) {
            x++;
            if(x>1) ans[x-2]=a[i-1];
        }
    }
    printf("%d\n", x);
    for(i=0;i<=x-2;i++) printf("%d ", ans[i]);
    printf("%d\n", a[n-1]);
}