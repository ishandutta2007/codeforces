#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,A,a[10],b[10],c[10],d[10];double S=0.0;
void ff(int x,int y)
{
    if(x==n&&y==0)
    {
        for(int i=0;i<n;i++)d[i]=min(100,b[i]+10*c[i]);
        double T=0;
        for(int k=0;k<(1<<n);k++)
        {
            double U=1.0;
            for(int i=0;i<n;i++)
                if((k>>i)&1)U*=d[i]/100.0;else U*=(1.0-d[i]/100.0);
            int V=0;
            for(int i=0;i<n;i++)
                if((k>>i)&1)V++;
            if(V<=n-V)
            {
                int B=0;
                for(int i=0;i<n;i++)
                    if(!((k>>i)&1))B+=a[i];
                U*=(A+0.0)/(A+B);
            }
            T+=U;
        }
        S=max(S,T);
        return;
    }
    if(x==n)return;
    ff(x+1,y);
    if(y)c[x]++,ff(x,y-1),c[x]--;
}
int main()
{
    scanf("%d%d%d",&n,&k,&A);
    for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i);
    ff(0,k);
    printf("%.9lf\n",S);
    return 0;
}