#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000010
int a[N],n,st[N],sn,le[N],ri[N];double C[N],Cp[N],S[N];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=0;i<n;i++)
    {
        while(sn&&a[st[sn-1]]>a[i])sn--;
        st[sn++]=i;
        if(sn<=1)le[i]=i+1;
        else le[i]=i-st[sn-2];
    }
    sn=0;
    for(int i=n-1;i>=0;i--)
    {
        while(sn&&a[st[sn-1]]>=a[i])sn--;
        st[sn++]=i;
        if(sn<=1)ri[i]=n-i;
        else ri[i]=st[sn-2]-i;
    }
    for(int i=0;i<n;i++)
    {
        int x=le[i],y=ri[i];
        double Ca=a[i];
        if(x>y)swap(x,y);
        Cp[x]+=Ca;
        C[y]+=Ca*x,C[x]-=Ca*x;
        C[x+y-1]+=Ca*(x+y),Cp[x+y-1]-=Ca,
        C[y]-=Ca*(x+y),Cp[y]+=Ca;
    }
    double Wp=0,W=0;
    for(int i=n;i>=1;i--)
        Wp+=Cp[i],W+=C[i],
        S[i]=(Wp*i+W)/(n-i+1);
    int _;scanf("%d",&_);
    for(int x;_--;)
        scanf("%d",&x),printf("%.18lf\n",S[x]);
    return 0;
}