# include<iostream>
# include<iomanip>
#include <cstdio>
# include <algorithm>
#include <vector>
#include <cctype>
using namespace std;
vector<int> adj[1000000];
bool vis[1000000];
bool vi[1000000];
int pa[1000000];
int v1,v2;
void getCycle(int v)
{
    vis[v]=1;
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (vis[u])
        {
            if (pa[v]==u)
                continue;
            else
            {
                v1=u;
                v2=v;
            }
        }
        else
        {
            pa[u]=v;
            getCycle(u);
        }
    }
}
bool tree;
void isTree(int v,int j)
{
    vi[v]=1;
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (vi[u])
        {
            if (vi[u]==j  && pa[v]!=u)
                tree=0;
        }
        else
        {
            isTree(u,j);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        pa[i]=-1;
    for (int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    v1=-1,v2=-1;
    getCycle(0);
    for (int i=0;i<n;i++)
    {
        if (vis[i]==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if (v1<0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    while(v1!=-1)
    {
        vi[v1]=1;
        v1=pa[v1];
    }
    while(v2!=-1)
    {
        vi[v2]=1;
        v2=pa[v2];
    }
    int trees=0;
    int j=1;
    for (int i=0;i<n;i++)
    {
        if (!vi[i])
        {
            j++;
            tree=1;
            isTree(i,j);
            if (tree==0)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            trees++;
        }
    }
    if (n==m)
        cout<<"FHTAGN!"<<endl;
        else
            cout<<"NO"<<endl;
}