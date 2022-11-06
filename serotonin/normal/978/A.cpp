#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j,k=0,a[55];
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d", &a[i]);
    for(i=n-1;i>=0;i--) {
        if(a[i]!=0) k++;
        if(a[i]==0) continue;
        for(j=i-1;j>=0;j--) {
            if(a[j]==a[i]) a[j]=0;
        }
    }
    printf("%d\n", k);
    for(i=0;i<n;i++) {
        if(i==n-1) {
            if(a[i]!=0) printf("%d\n", a[i]);
        }
        else {
            if(a[i]!=0) printf("%d ", a[i]);
        }
    }
}