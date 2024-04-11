#include<stdio.h>
#include<math.h>
unsigned long long int a[101],ans[101];

int main()
{
    int t,i,j,n,k=0,flag;
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%I64d", &a[i]);

    for(i=0;i<n;i++) {
        flag=0;
        for(j=0;j<n;j++) {
            if(a[i]*3==a[j] || a[j]*2==a[i]) {
                flag++;
                break;
            }
        }
        if(flag==0) break;
    }

    ans[k]=a[i];
    for(t=0;t<n;t++) {
        for(j=0;j<n;j++) {
            if(a[j]*3==a[i] || a[i]*2==a[j]) {
                k++;
                ans[k]=a[j];
                i=j;
                break;
            }
        }
    }

    for(i=0;i<n;i++) {
        if(i==n-1) printf("%I64d\n", ans[i]);
        else printf("%I64d ", ans[i]);
    }
}