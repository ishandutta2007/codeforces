
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
#define EPS 1e-9
using namespace std;
map<string,int> is;
map<string,int> x;
map<string,int> y;
bool vis[101][101];
int n,m;
void add(int u,int v,string s)
{
    for (int i=v;i<=m;i++)
    {
        if (!vis[u][i])
        {
            vis[u][i]=1;
            x[s]=u;
            y[s]=i;
            is[s]=1;
            return;
        }
    }
    for (int j=u+1;j<=n;j++)
    {
        for (int i=1;i<=m;i++)
        {
            if (!vis[j][i])
            {
                vis[j][i]=1;
                x[s]=j;
                y[s]=i;
                is[s]=1;
                return;
            }
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int k;
    cin>>n>>m>>k;
    while(k--)
    {
        int typ;
        cin>>typ;
        if (typ==-1)
        {
            string s;
            cin>>s;
            if (is[s])
                cout<<x[s]<<" "<<y[s]<<endl,is[s]=0,vis[x[s]][y[s]]=0;
            else
                cout<<-1<<" "<<-1<<endl;
        }
        else
        {
            int u,v;
            string s;
            cin>>u>>v>>s;
            add(u,v,s);
        }
    }
}