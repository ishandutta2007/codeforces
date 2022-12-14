#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int n,k;
int st[1000000];
int sz=0;
bool solve()
{
    int mn=1;
    for (int i=1;i<=k;i++)
    {
        if (sz==0 || st[sz-1]>a[i])
            st[sz++]=a[i];
        else
            return false;
        while(sz && st[sz-1]==mn)
            mn++,sz--;
    }
    return true;
}
bool vis[1000000];
int main()
{
    cin>>n>>k;
    for (int i=1;i<=k;i++)
        cin>>a[i],vis[a[i]]=1;
    if (solve()==false)
    {
        cout<<-1<<endl;
    }
    else
    {
        k++;
        for (int i=sz-1;i>=0;i--)
        {
            int v=st[i]-1;
            while(v>0 && !vis[v])
                a[k++]=v,vis[v]=1,v--;
        }
        int v=n;
        while(v>0 && !vis[v])
            a[k++]=v,vis[v]=1,v--;
        for (int i=1;i<=n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
}