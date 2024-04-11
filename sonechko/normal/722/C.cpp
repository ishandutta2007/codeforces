#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 11;
ll a[N],b[N],c[N],ans[N],p[N],res[N];
int gol(int l)
{
    if (p[l]==0) return l;
    int k=gol(p[l]);
    p[l]=k;
    return k;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        a[i]=-1;
    }
    for (int j=1; j<=n; j++)
    {
        cin>>c[j];
    }
    ans[n+1]=0;
    a[0]=-1;
    a[n+1]=-1;
    ll one=0;
    for (int j=n; j>=2; j--)
    {
        int l=c[j];
        a[l]=b[l];
        int i=l;
        if (a[i-1]!=-1&&a[i+1]!=-1)
        {
            int x=gol(i-1);
            int y=gol(i+1);
            res[i]=res[x]+res[y]+a[i];
            p[x]=i;
            p[y]=i;
        } else
        if (a[i-1]!=-1)
        {
            int x=gol(i-1);
            res[i]=res[x]+a[i];
            p[x]=i;
        } else
        if (a[i+1]!=-1)
        {
            int x=gol(i+1);
            res[i]=res[x]+a[i];
            p[x]=i;
        } else
        {
            res[i]=a[i];
        }
        one=max(one,res[i]);
        ans[j]=one;
    }
    for (int j=2; j<=n+1; j++)
        cout<<ans[j]<<"\n";
}