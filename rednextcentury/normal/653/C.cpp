//// find_flow returns max flow from s to t in an n-vertex graph.
//// Use add_edge to add edges (directed/undirected) to the graph.
//// Call clear_flow() before each testcase.
//#include<bits/stdc++.h>
//using namespace std;
//#define maxn 52
//int c[maxn][maxn];
//vector<int> adj[maxn];
//int par[maxn];
//int dcount[maxn+maxn];
//int dist[maxn];
//void add_edge(int a,int b,int cap,int rev_cap=0)
//{
//    c[a][b]+=cap;
//    c[b][a]+=rev_cap;
//    adj[a].push_back(b);
//    adj[b].push_back(a);
//}
//void clear_flow()
//{
//    memset(c,0,sizeof c);
//    memset(dcount,0,sizeof dcount);
//    for (int i=0; i<maxn; ++i)
//        adj[i].clear();
//}
//int advance(int v)
//{
//    for (int i=0; i<adj[v].size(); ++i)
//    {
//        int w=adj[v][i];
//        if (c[v][w]>0 && dist[v]==dist[w]+1)
//        {
//            par[w]=v;
//            return w;
//        }
//    }
//    return -1;
//}
//int retreat(int v)
//{
//    int old=dist[v];
//    --dcount[dist[v]];
//    for (int i=0; i<adj[v].size(); ++i)
//    {
//        int w=adj[v][i];
//        if (c[v][w]>0)
//            dist[v]=min(dist[v],dist[w]);
//    }
//    ++dist[v];
//    ++dcount[dist[v]];
//    if (dcount[old]==0)
//        return -1;
//    return par[v];
//}
//int augment(int s,int t)
//{
//    int delta=c[par[t]][t];
//    for (int v=t; v!=s; v=par[v])
//        delta=min(delta,c[par[v]][v]);
//    for (int v=t; v!=s; v=par[v])
//    {
//        c[par[v]][v]-=delta;
//        c[v][par[v]]+=delta;
//    }
//    return delta;
//}
//queue<int> q;
//void bfs(int v)
//{
//    memset(dist,-1,sizeof dist);
//    while (!q.empty()) q.pop();
//    q.push(v);
//    dist[v]=0;
//    ++dcount[dist[v]];
//    while (!q.empty())
//    {
//        v=q.front();
//        q.pop();
//        for (int i=0; i<adj[v].size(); ++i)
//        {
//            int w=adj[v][i];
//            if (c[w][v]>0 && dist[w]==-1)
//            {
//                dist[w]=dist[v]+1;
//                ++dcount[dist[w]];
//                q.push(w);
//            }
//        }
//    }
//}
//int x;
//int a[1000000],b[1000000],C[1000000];
//pair<int,int> find_flow(int n,int s,int t)
//{
//    bfs(t);
//    int v=s;
//    par[s]=s;
//    int ans=0;
//int k=0;
//    while (v!=-1 && dist[s]<n && k<x)
//    {
//        k++;
//        int newv=advance(v);
//        if (newv!=-1)
//            v=newv;
//        else
//            v=retreat(v);
//        if (v==t)
//        {
//            v=s;
//            ans+=augment(s,t);
//        }
//    }
//    return make_pair(k,ans);
//}
//int n,m;
//long double bs(long double l,long double r)
//{
//    long double ans=-1;
//    for (int i=0;i<90;i++)
//    {
//        long double mid=(l+r)/2.0;
//        clear_flow();
//        for (int j=0;j<m;j++)
//        {
//            add_edge(a[i],b[i],(int)(C[i]/mid));
//        }
//        pair<int,int> o=find_flow(n,1,n);
//        if (o.first>=x)
//            ans=o.second,l=mid;
//        else
//            r=mid;
//    }
//    return ans;
//}
//int main()
//{
//    cin>>n>>m>>x;
//    for (int i=0;i<m;i++)
//        cin>>a[i]>>b[i]>>C[i];
//    cout<<bs(0.0000001,1000000)<<endl;
//}
#include <bits/stdc++.h>
using namespace std;
int a[1000000];
    int n;
    map<pair<int,int>,bool> mp;
bool check(int x)
{
    for (int i=max(0,x-5);i<min(n-1,x+6);i++)
    {
        if (i%2==0 && a[i]>=a[i+1])
        {
            return 0;
        }
        if (i%2 && a[i]<=a[i+1])
        {
            return 0;
        }
    }
    return 1;
}
int swp(int i,int j)
{
    if (mp[make_pair(min(i,j),max(i,j))])
        return 0;
    mp[make_pair(min(i,j),max(i,j))]=1;
    if (i<0 || j<0 || i>=n || j>=n || i==j)return 0;
    swap(a[i],a[j]);
    if (check(i) && check(j))
    {
        swap(a[i],a[j]);
        return 1;
    }
    swap(a[i],a[j]);
    return 0;

}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int num=0;
    int id=-2;
    int mnid=-1;
    for (int i=0;i<n-1;i++)
    {
        if (i%2==0 && a[i]>=a[i+1])
        {
            if (id==i-1)continue;
            num++,id=i;
            if (mnid==-1)
                mnid=i;
        }
        if (i%2 && a[i]<=a[i+1])
        {
            if (id==i-1)continue;
            num++,id=i;
            if (mnid==-1)
                mnid=i;
        }
    }
    if (num>2)
        cout<<0<<endl;
    else
    {
        if (num==2)
        {
            int ans=0;
            ans=swp(id,mnid)+swp(id+1,mnid)+swp(id,mnid+1)+swp(id+1,mnid+1);
            cout<<ans<<endl;
        }
        else
        {
            long long ans=0;
            ans+=swp(id,id+1);
            for (int j=0;j<n;j++)
            {
                ans+=swp(id,j);
                ans+=swp(id+1,j);
            }
            cout<<ans<<endl;
        }
    }
}