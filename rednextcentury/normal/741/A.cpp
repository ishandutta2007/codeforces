#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int sz;
bool vis[1000000];
void dfs(int i)
{
    vis[i]=1;
    sz++;
    if (!vis[a[i]])
        dfs(a[i]);
}
long long GCD(long long a,long long b)
{
    if (a%b==0)
        return b;
    if (b%a==0)
        return a;
    return GCD(b%a,a);
}
long long LCM(long long a,long long b)
{
    return (a/GCD(a,b)*b);
}
int num[100000];
int main()
{
    int n;
    cin>>n;
    bool imp=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]>n)
            imp=1;
        if(++num[a[i]]>1)
            imp=1;
    }
    long long ans=1;
    if (imp)
        cout<<-1<<endl;
    else{
    for (int i=1;i<=n;i++)
    {
        sz=0;
        if (!vis[i])dfs(i);
        else continue;
        if (sz%2==0)sz/=2;
        ans=LCM(ans,sz);
    }
    cout<<ans<<endl;
    }
}