#include <bits/stdc++.h>
using namespace std;
pair<int,int>  p[1000000];
int a[1000000];
int oth[1000000];
int vis[1000000];
vector<pair<int,int> > vec;
set<pair<int,int> > s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=2*n;i++)
    {
        cin>>p[i].first;
        p[i].second=i;
    }
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        if (p[u].first>p[v].first)
            vec.push_back({u,v});
        else
            vec.push_back({v,u});
        oth[u]=v;
        oth[v]=u;
    }
    int t;
    cin>>t;
    int num=0;
    while (t==2)
    {
        num++;
        int id;
       cin>>id;
        vis[id]=1;
        if (oth[id]>0)
        {
            vis[oth[id]]=1;
            cout<<oth[id]<<endl;
            fflush(stdout);
        }
        else
        {
            t=1;
        }
        if (num==n)break;
    }

    for (int i=0;i<vec.size();i++)
    {
        if (vis[vec[i].first])continue;
        cout<<vec[i].first<<endl;
        fflush(stdout);
        int x;
        cin>>x;
        vis[x]=1;
        vis[vec[i].first]=1;
    }
    for (int i=1;i<=2*n;i++)
    {
        if (!vis[i])
        s.insert(p[i]);
    }
    while(!s.empty())
    {
        pair<int,int> pp = *s.rbegin();
        s.erase(--s.end());
        cout<<pp.second<<endl;
        fflush(stdout);
        if (s.empty())return 0;
        int x;
        cin>>x;
        s.erase(p[x]);
    }
}