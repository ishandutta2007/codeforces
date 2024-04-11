#include<cstdio>
typedef long long ll;
#define N 1000200
int x[N],y[N],n;
ll calc(int *a)
{
    ll S1=0,S2=0;
    for(int i=0;i<n;i++)S1+=a[i],S2+=(ll)a[i]*a[i];
    return S2*(n-1)-(S1*S1-S2);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",x+i,y+i);
    printf("%I64d\n",calc(x)+calc(y));
    return 0;
}