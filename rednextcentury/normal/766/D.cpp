#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
string a[100001];
map<string,int> mp;
vector<int> groups[1000000];
int hate[100001];
int group[1000000];
int sz[1000000];
void add(int u,int v)
{
    for (int i=0;i<groups[u].size();i++)
    {
        group[groups[u][i]]=v;
        groups[v].push_back(groups[u][i]);
        sz[v]++;
    }
    groups[u].clear();
    sz[u]=0;
}
void dsu(int u,int v)
{
    if (u==v)return;
    if (groups[u].size()<groups[v].size())
        add(u,v);
    else add(v,u);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for (int i=0;i<n;i++)
    {
        group[i]=i;
        sz[i]=1;
        groups[i].push_back(i);
        hate[i]=-1;
        cin>>a[i];
        mp[a[i]]=i;
    }
    for (int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        string xx,yy;
        cin>>xx>>yy;
        int u=mp[xx],v=mp[yy];
        int U=group[u],V=group[v];
        if (t==1)
        {
            if (hate[U]==-1)
                swap(u,v),swap(U,V);
            if (hate[U]==V)
                cout<<"NO"<<endl;
            else if (hate[U]==-1)
            {
                cout<<"YES"<<endl;
                dsu(U,V);
            }
            else
            {
                cout<<"YES"<<endl;
                if (hate[V]!=-1)
                {
                    int x=hate[V];
                    if (groups[hate[U]].size()>=groups[x].size())
                        x=hate[U];
                    dsu(hate[U],hate[V]);
                    int y=V;
                    if (groups[U].size()>=groups[y].size())
                        y=U;
                    dsu(U,V);
                    hate[x]=y;
                    hate[y]=x;
                }
                else
                {
                    int x=hate[U];
                    int y=V;
                    if (groups[U].size()>=groups[y].size())
                        y=U;
                    dsu(U,V);
                    hate[y]=x;
                    hate[x]=y;
                }
            }
        }
        else
        {
            if (hate[U]==-1)
                swap(u,v),swap(U,V);
            if (U==V)
                cout<<"NO"<<endl;
            else if (hate[U]==-1)
            {
                hate[U]=V;
                hate[V]=U;
                cout<<"YES"<<endl;
            }
            else if (hate[V]==-1)
            {
                int x=hate[U];
                if (groups[V].size()>=groups[x].size())
                    x=V;
                dsu(V,hate[U]);

                hate[U]=x;
                hate[x]=U;
                cout<<"YES"<<endl;
            }
            else
            {
                int x=U;
                if (groups[hate[V]].size()>=groups[x].size())
                    x=hate[V];
                dsu(hate[V],U);
                int y=V;
                if (groups[hate[U]].size()>=groups[y].size())
                    y=hate[U];
                dsu(hate[U],V);
                hate[x]=y;
                hate[y]=x;
                cout<<"YES"<<endl;
            }
        }
    }
    for (int i=0;i<q;i++)
    {
        string x,y;
        cin>>x>>y;
        int u=mp[x],v=mp[y];
        if (group[u]==group[v])
            cout<<1<<endl;
        else if (hate[group[u]]==group[v])
            cout<<2<<endl;
        else cout<<3<<endl;
    }
}