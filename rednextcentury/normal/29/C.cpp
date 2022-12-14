
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
#define EPS 1e-9
using namespace std;
map<int,int> adj1;
map<int,int> adj2;
map<int,int> num;
map<int,int> vis;
int a[1000001];
int m;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        num[u]++;
        num[v]++;
        if (num[u]==1)
            adj1[u]=v,a[m++]=u;
        else
            adj2[u]=v;
        if (num[v]==1)
            adj1[v]=u,a[m++]=v;
        else
            adj2[v]=u;
    }
    int v=0;
    for (int i=0;i<m;i++)
        if (num[a[i]]==1)
            v=a[i];
    cout<<v<<" ";
    vis[v]=1;
    v=adj1[v];
    while(num[v]==2)
    {
        vis[v]=1;
        cout<<v<<" ";
        if (!vis[adj1[v]])
            v=adj1[v];
        else
            v=adj2[v];
    }
    cout<<v<<endl;
}