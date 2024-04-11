/*
ID: Sfiction
OJ: CF
PROB: 340B
*/
#include <cstdio>
const int MAXN=300;
int x[MAXN],y[MAXN];
int main()
{
    int n;
    int i,j,k;
    int ax,ay;
    int t,min,max,ans;
    scanf("%d",&n);
    for (i=0;i<n;++i) scanf("%d%d",&x[i],&y[i]);
    ans=0;
    for (i=0;i<n;++i)
        for (j=i+1;j<n;++j)
        {
            min=max=0;
            ax=x[j]-x[i];
            ay=y[j]-y[i];
            for (k=0;k<n;++k)
            {
                t=ax*(y[k]-y[i])-ay*(x[k]-x[i]);
                if (t<min) min=t;
                else if (t>max) max=t;
            }
            if (min<0&&max>0&&max-min>ans) ans=max-min;
        }
    printf("%d",ans>>1);
    if (ans&1) printf(".5");
    return 0;
}