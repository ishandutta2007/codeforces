#include<bits/stdc++.h>
using namespace std;
int n,m;
set<int> S;
int tot=0;
int x[1000000];
int y[1000000];
map<int,int> mp;
vector<pair<int,int> > v[1000000];
int last[1000000];
int len;
vector<int> vis[1000000];
pair<int,int> A[1000000];
int N;
void Setup()
{
    cin>>n>>m;
    len=n+n-2;
    N=n;
    S.insert(1);
    S.insert(n);
    for (int i=0;i<m;i++)
    {
        cin>>x[i]>>y[i];
        A[i].second=x[i];
        A[i].first=y[i];
        S.insert(x[i]);
        if (x[i]<n)
            S.insert(x[i]+1);
    }
    sort(A,A+m);
    for (int i=0;i<m;i++)
    {
        x[i]=A[i].second;
        y[i]=A[i].first;
    }
    int id=1;
    for (set<int>::iterator it=S.begin();it!=S.end();it++)
        mp[*it]=id++;
    for (int i=1;i<id;i++)
        last[i]=0;
    for (int i=0;i<m;i++)
    {
        x[i]=mp[x[i]];
        if (y[i]-last[x[i]]>1)
            v[x[i]].push_back(make_pair(last[x[i]]+1,y[i]-1));
        last[x[i]]=y[i];
    }
    for (int i=1;i<id;i++)
    {
        if (n-last[i]>0)
            v[i].push_back(make_pair(last[i]+1,n));
        for (int j=0;j<v[i].size();j++)
            vis[i].push_back(0);
    }
    id--;
    n=id;
}
void weirdSol()
{
    vis[1][0]=1;
    for (int i=2;i<=n;i++)
    {
        /*if (v[i-1].size()!=vis[i-1].size() || v[i].size()!=vis[i].size())
        {
            cout<<-1<<endl;
            return;
        }*/
        int l=0,r=0;
        v[0].clear();
        vis[0].clear();
        for (int j=0;j<v[i-1].size();j++)
        {
            if (vis[i-1][j])
                v[0].push_back(v[i-1][j]),vis[0].push_back(1);
        }
        swap(v[0],v[i-1]);
        swap(vis[0],vis[i-1]);
        /*cout<<i<<": ";
        for (int j=0;j<v[i-1].size();j++)
            cout<<"["<<v[i-1][j].first<<','<<v[i-1][j].second<<"] ";
        cout<<endl;*/
        for (int j=0;j<v[i].size();j++)
        {
            while(l>0 && max(v[i-1][l-1].first,v[i][j].first)<=min(v[i-1][l-1].second,v[i][j].second))l--;
            while(l<v[i-1].size() && v[i-1][l].second<v[i][j].first)l++;
            if (l<v[i-1].size() && max(v[i-1][l].first,v[i][j].first)<=min(v[i-1][l].second,v[i][j].second))
            {
                vis[i][j]|=vis[i-1][l];
                v[i][j].first=max(v[i][j].first,v[i-1][l].first);
            }
        }

    }
    if (vis[n].size()==0 || v[n].size()==0)
        cout<<-1<<endl;
    else if (vis[n][vis[n].size()-1] && v[n][v[n].size()-1].second==N)
        cout<<len<<endl;
    else
        cout<<-1<<endl;
}
int main()
{
    Setup();
    weirdSol();
}