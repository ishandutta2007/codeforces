#include<cstdio>
#include<algorithm>
using namespace std;
double f[1010][1010];int n,m;
double ff(int n,int m)
{
    if(n==0)return 1.0/(1+m);
    if(m==0)return 1.0;
    if(f[n][m]>-1e-8)return f[n][m];
    double A=(double)m/(m+1)*(1-ff(m-1,n)),C=1.0/(m+1),B=C+A,D=1-ff(m,n-1);
    double p=(D-1)/(A-1+D-B);
    return f[n][m]=A*p+1-p;
}
int main()
{
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=1000;j++)f[i][j]=-1;
    scanf("%d%d",&n,&m);
    printf("%.9lf %.9lf\n",ff(n,m),1-ff(n,m));
    return 0;
}