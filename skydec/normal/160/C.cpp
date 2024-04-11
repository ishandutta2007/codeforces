#include<stdio.h>
#include<algorithm>
#include<cstring>
#define MAXN 110000
using namespace std;
typedef long long LL;
LL k;int n;int a[MAXN];
int main()
{
    scanf("%d%I64d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
            int j=i;
            while(j<n&&a[j+1]==a[i])j++;
            if(k<=(j-i+1)*1ll*n)
            {
                                printf("%d %d\n",a[i],a[(k-1)/(j-i+1)+1]);
                                return 0;
                                }
            k-=(j-i+1)*1ll*n;
            i=j;
            }
    return 0;
}