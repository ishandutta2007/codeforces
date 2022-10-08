#include<cstdio>
#include<algorithm>
using namespace std;
#define N 3010
int n;double x[N],y[N],z[N],a[N],S;
double ff(int i,int j)
{
    if(y[j]>=z[i])return 0;
    double S=x[i];
    if(y[j]>=y[i]&&y[j]<=z[i])S=min(S,x[i]-(y[j]-y[i])*x[i]/(z[i]-y[i]));
    if(z[j]>=y[i]&&z[j]<=z[i])S=min(S,x[i]+x[j]-(z[j]-y[i])*x[i]/(z[i]-y[i]));
    if(z[i]>=y[i]&&z[i]<=z[j])S=min(S,(z[i]-y[j])*x[j]/(z[j]-y[j]));
    return S;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lf%lf%lf",x+i,y+i,z+i);
    S=a[0]=x[0];
    for(int i=1;i<n;S=max(S,a[i]),i++)
        for(int j=0;j<i;j++)a[i]=max(a[i],a[j]+x[i]-ff(j,i));
    printf("%.9lf\n",S);
    return 0;
}