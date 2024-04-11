#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,p,x[10],y[10],xT,yT,S=-1;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<p;i++)scanf("%d%d",x+i,y+i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int T=n+m;
            for(int k=0;k<p;k++)T=min(T,abs(i-x[k])+abs(j-y[k]));
            if(T>S)S=T,xT=i,yT=j;
        }
    printf("%d %d\n",xT,yT);
    return 0;
}