#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
const long double eps=1e-18;
int n,L,v1,v2;long double p[N*4],a[N*2],S[N];int pl;
int main()
{
    scanf("%d%d%d%d",&n,&L,&v1,&v2);
    for(int i=0;i<n;i++)cin>>a[i];
    long double l2=v2;l2*=L;l2/=v1+v2;
    for(int i=0;i<n;i++)a[i+n]=a[i]+L+L;
    p[pl++]=0,p[pl++]=L*2;
    for(int i=0;i<n*2;i++)
        p[pl++]=max(min(a[i],L*(long double)2.0),(long double)0.0),
        p[pl++]=max(min(a[i]-l2,L*(long double)2.0),(long double)0.0);
    sort(p,p+pl);
    for(int i=1,j=-1,k=-1;i<pl;i++)
    {
        while(j<n*2-1&&a[j+1]<p[i]+l2-eps)j++;
        while(k<n*2-1&&a[k+1]<p[i]-eps)k++;
        S[j-k]+=p[i]-p[i-1];
    }
    for(int i=0;i<=n;i++)printf("%.18lf\n",(double)S[i]/L/2);
    return 0;
}