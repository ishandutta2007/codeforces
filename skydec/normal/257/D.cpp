#include<stdio.h>
#define MAXN 110000
using namespace std;
int a[MAXN];
int ans[MAXN];
int n,k;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    k=a[n];ans[n]=1;
    for(int i=n-1;i>=1;i--)
    if(k>0)k-=a[i],ans[i]=0;else k+=a[i],ans[i]=1;
    if(k<0)
    {
           k=-k;
           for(int i=1;i<=n;i++)ans[i]=1-ans[i];
           }
    char c[2];c[0]='-';c[1]='+';
    for(int i=1;i<=n;i++)putchar(c[ans[i]]);
    return 0;
}