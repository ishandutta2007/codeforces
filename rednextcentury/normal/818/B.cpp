#include<bits/stdc++.h>
using namespace std;
int b[1000000];
int a[1000000];
bool vis[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
        cin>>b[i];
    for (int i=0;i<m-1;i++)
    {
        int dist=b[i+1]-b[i];
        if (dist<=0)dist+=n;
        if (a[b[i]]==dist)
            continue;
        if (vis[dist] || (a[b[i]] && a[b[i]]!=dist))
        {
            cout<<-1<<endl;
            return 0;
        }
        vis[dist]=1;
        a[b[i]]=dist;
    }
    for (int i=0;i<n;i++)
    {
        if (a[i+1]==0)
        {
            for (int j=1;j<=n;j++){
                if (!vis[j])
                {
                    vis[j]=1;
                    a[i+1]=j;
                    break;
                }
            }
        }
    }
    for (int i=0;i<n;i++)
        cout<<a[i+1]<<' ';
    cout<<endl;
}