#include<cstdio>
#include<cstring>
typedef long long ll;
int A[2521],a[19],t;
ll f[19][48][252],L,R;
int g(int a,int b){return b?g(b,a%b):a;}
ll ff(int p,int l,int s,bool b)
{
    if(p==-1)
        return s%l==0;
    if(!b&&f[p][A[l]][s]!=-1)
        return f[p][A[l]][s];
    int e=b?a[p]:9;
    ll r=0;
    for(int i=0;i<=e;i++)
        r+=ff(p-1,i?l*i/g(l,i):l,p?(s*10+i)%252:(s*10+i),b&&i==e);
    return b?r:f[p][A[l]][s]=r;
}
ll ff(ll x)
{
    int l=0;
    for(;x;a[l++]=x%10,x/=10);
    return ff(l-1,1,0,1);
}
int main()
{
    for(int i=1,s=-1;i<=2520;A[i]=s+=(2520%i==0),i++);
    memset(f,-1,sizeof f);
    for(scanf("%d",&t);t--;scanf("%I64d%I64d",&L,&R),printf("%I64d\n",ff(R)-ff(L-1)));
    return 0;
}