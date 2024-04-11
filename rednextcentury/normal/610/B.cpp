#include <bits/stdc++.h>
using namespace std;
bool vis[1000000];
int a[1000000];
int main()
{
    int n;
    cin>>n;
    int mn = 2000000000;
    for (int i=0;i<n;i++)
        cin>>a[i],mn=min(mn,a[i]);
    for (int i=0;i<n;i++)
        a[i]-=mn;
    long long ret=0;
    for (int i=0;i<n;i++)
    {
        int j=i;
        int num=0;
        bool ok=0;
        while(!vis[j] && a[j]>0)
        {
            num++;
            vis[j]=1;
            j++;
            if (j==n)
            {
                j=0;
                memset(vis,0,sizeof(vis));
                ok=1;
            }
        }
        ret=max(ret,0LL+num);
        if (ok)break;
        i=j;
    }
    cout<<ret+1LL*n*1LL*mn<<endl;
}