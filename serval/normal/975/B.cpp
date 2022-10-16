#include <cstdio>
using namespace std;
long long r[50];
long long d[50];
int i,j;
long long ans,ret;
int main()
{
    for (i=1;i<=14;i++)
        scanf("%I64d",&r[i]);
    for (i=1;i<=14;i++)
    {
        for (j=1;j<=14;j++)
            d[i+j]=r[i+j]+r[i]/14;
        for (j=1;j<=r[i]%14;j++)
            d[i+j]++;
        ret=0;
        for (j=1;j<=14;j++)
            if (d[i+j]%2==0)
                ret+=d[i+j];
        if (ret>ans)
            ans=ret;
        r[i+14]=r[i];
    }
    printf("%I64d\n",ans);
    return 0;
}