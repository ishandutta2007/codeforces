#include<iostream>
# include <cstring>
#include <algorithm>
#include <stdio.h>
#include<vector>
using namespace std;
int a[1000];
int q[100000];
int vis[100000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    for (int i=0;i<m;i++)
    {
        cin>>q[i];
        for (int x=i-1;x>=0;x--)
        {
            if (q[x]==q[i])
                break;
            if (vis[q[x]]!=i)
            {
                vis[q[x]]=i;
                ans+=a[q[x]-1];
            }
        }
    }
    cout<<ans<<endl;
}