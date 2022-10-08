#include<cstdio>
#include<algorithm>
using namespace std;
#define N 210
double f[N][N][N],w[N];
int n,m,p,a[N],e[N];
bool cmp(int x,int y){return a[x]>a[y];}
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0,x;i<n;i++)scanf("%d",&x),w[i]=x/100.0;
    for(int i=0;i<n;i++)scanf("%d",a+i),e[i]=i;
    sort(e,e+n,cmp);
    f[0][0][min(n,p)]=1.0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<=n;k++)
            {
                double T=f[i][j][k];
                double win=w[e[i]];int pr=a[e[i]];
                f[i+1][j][k]+=T*(1-win);
                if(pr==-1&&k)f[i+1][j+1][k-1]+=T*win;
                if(pr!=-1)f[i+1][j+1][min(n,k+pr)]+=T*win;
            }
    double S=0;
    for(int i=m;i<=n;i++)
        for(int j=0;j<=n;j++)
            S+=f[n][i][j];
    printf("%.9lf\n",S);
    return 0;
}