#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int n,i,j,k=0,ans=0;
    char a[105];
    scanf("%d", &n);
    scanf("%s", a);
    for(i=0;i<n;i++) {
        if(a[i]=='x' && a[i+1]=='x') {
            k=2;
            for(j=i+2;j<n;j++) {
                if(a[j]=='x') k++;
                else break;
            }
            ans+=k-2;
            i+=k;
        }
    }
    printf("%d\n", ans);
}