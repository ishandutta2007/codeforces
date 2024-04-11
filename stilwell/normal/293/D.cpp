#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k,x1,x2;
int x[100005],y[100005];
int l[3000005],r[3000005];
long long S[3000005],A,B,K;
double ans,sum,sum2,sum3;

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]),x[i]+=1000001,y[i]+=1000001;
    for(i=1;i<=2000005;++i)l[i]=3000000,r[i]=-3000000;
    x[n+1]=x[1];y[n+1]=y[1];
    for(i=1;i<=n;++i)
    if(x[i]==x[i+1])
    {
        if(y[i]>r[x[i]])r[x[i]]=y[i];
        if(y[i]-1<l[x[i]])l[x[i]]=y[i]-1;
        if(y[i+1]>r[x[i]])r[x[i]]=y[i+1];
        if(y[i+1]-1<l[x[i]])l[x[i]]=y[i+1]-1;
    }
    else
    {
        if(x[i]<x[i+1])B=x[i+1]-x[i],A=y[i]*B,K=y[i+1]-y[i];
        else B=x[i]-x[i+1],A=y[i+1]*B,K=y[i]-y[i+1];
        x1=x[i];x2=x[i+1];if(x1>x2)swap(x1,x2);
        for(j=x1;j<=x2;++j)
        {
            if(A/B>r[j])r[j]=A/B;
            if(A/B-(A%B==0)<l[j])l[j]=A/B-(A%B==0);
            A+=K;
        }
    }
    for(i=1;i<=2000005;++i)if(l[i]<=r[i])++S[l[i]+1],--S[r[i]+1];
    for(i=1;i<=2000005;++i)S[i]+=S[i-1];
    sum=sum2=sum3=0;
    for(i=1;i<=2000005;++i)
    {
        ans+=S[i]*(sum3*i*i-sum2*i*2+sum);
        sum+=(double)i*i*S[i];sum2+=(double)i*S[i];sum3+=S[i];
    }
    for(i=1;i<=2000005;++i)if(l[i]<=r[i])S[i]=r[i]-l[i];else S[i]=0;
    sum=sum2=sum3=0;
    for(i=1;i<=2000005;++i)
    {
        ans+=S[i]*(sum3*i*i-sum2*i*2+sum);
        sum+=(double)i*i*S[i];sum2+=(double)i*S[i];sum3+=S[i];
    }
    printf("%.20lf\n",ans/(sum3*(sum3-1)));
}