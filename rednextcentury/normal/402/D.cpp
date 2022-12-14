#include <bits/stdc++.h>
using namespace std;


int pre[1000000];
int a[100000];
int b[100000];
int ret=0;
int val=0;
int n,m;
int Count(int x)
{
    int ans=0;
    for (int i=2;i*i<=x;i++)
    {
        while(x%i==0)
            x/=i,ans++;
    }
    if (x>1)ans++;
    return ans;
}
bool Good(int x)
{
    val=0;
    for (int i=1;i<=m;i++)
    {
        while(x%b[i]==0)
            x/=b[i],val++;
    }
    val-=Count(x);
    if (val>=0)
        return 1;
    return 0;
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (i==1)pre[i]=a[i];
        else pre[i]=__gcd(a[i],pre[i-1]);
    }
    for (int i=1;i<=m;i++)
        cin>>b[i];
    for (int i=1;i<=n;i++)
    {
        Good(a[i]);
        ret-=val;
    }
    int div = 1;
    for (int i=n;i>=1;i--)
    {
        int cur = pre[i]/div;
        if (Good(cur))
            div*=cur,ret+=i*val;
    }
    cout<<ret<<endl;
}