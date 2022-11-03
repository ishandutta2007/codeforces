/*
ID: Sfiction
OJ: CF
PROB: 341B
*/
/*


*/
#include <cstdio>
const int MAXN=100000;
int a[MAXN+1];
int que[MAXN+1],len;
int main()
{
    int n;
    int i;
    int high,low,median;
    scanf("%d",&n);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    len=1;
    for (i=1;i<=n;++i)
    {
        high=len;
        low=0;
        while (high-low>1)
        {
            median=(high+low)>>1;
            if (que[median]>a[i]) high=median;
            else low=median;
        }
        if (low+1==len) que[len++]=a[i];
        else if (que[low+1]>a[i]) que[low+1]=a[i];
    }
    printf("%d",len-1);
    return 0;
}