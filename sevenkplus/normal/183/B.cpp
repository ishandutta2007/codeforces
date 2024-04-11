#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 255
#define M 1000010
int n,m,a[N],S[M],px[N],py[N];
int chk(int x,int y)
{
    if(px[x]==px[y])return px[x];
    if(py[x]==py[y])return -1;
    ll w=(ll)px[x]*py[y]-(ll)py[x]*px[y];
    if(w%(py[y]-py[x])==0)
    {
        ll w1=w/(py[y]-py[x]);
        if(w1<1||w1>m)return -1;
        return w1;
    }
    return -1;
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)S[i]=1;
    for(int i=1;i<=n;i++)scanf("%d%d",px+i,py+i);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int c=chk(i,j);
            if(c<1||c>m)continue;
            int T=0;
            for(int k=1;k<=n;k++)
                if((ll)(px[k]-px[i])*(py[j]-py[i])==(ll)(py[k]-py[i])*(px[j]-px[i]))T++;
            S[c]=max(S[c],T);
        }
    ll T=0;
    for(int i=1;i<=m;i++)T+=S[i];
    cout<<T<<endl;
    return 0;
}