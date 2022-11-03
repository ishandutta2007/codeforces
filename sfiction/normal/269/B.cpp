/*
ID: Sfiction
OJ: CF
PROB: 269B
*/
#include <cstdio>
const int MAXN=5000;
int que[MAXN+1],len;
int main()
{
    int N,M;
    int spe,i;
    int high,low,median;
    double temp;
    scanf("%d%d",&N,&M);
    len=1;
    for (i=0;i<N;++i)
    {
        scanf("%d%lf",&spe,&temp);
        high=len;
        low=0;
        while (high-low>1)
        {
            median=(high+low)>>1;
            if (spe<que[median]) high=median;
            else low=median;
        }
        if (high==len) que[len++]=spe;
        else if (spe<que[high]) que[high]=spe;
    }
    printf("%d",N-len+1);
    return 0;
}