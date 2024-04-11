# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <ios>
#include <set>
using namespace std;
bool vis[1000000];
long long cur;
vector<long long> adj[1000000];
vector<long long> len[1000000];
void dfs(long long v,int pa)
{
    vis[v]=1;
    int n=adj[v].size();
    for (long long i=0;i<n;i++)
    {
        long long u=adj[v][i];
        if (u==pa)
            continue;
        cur+=len[v][i];
        if (vis[u])
            continue;
        dfs(u,v);
    }
}
struct component
{
    long long sum;
    long long v;
};
bool operator<(component a,component b)
{
    return a.sum<b.sum;
}
int main()
{
    long long s1,s2;
    long long n,m,p,q;
    cin>>n>>m>>p>>q;
    for (long long i=0;i<m;i++)
    {
        long long s,e,l;
        cin>>s>>e>>l;
        adj[s].push_back(e);
        adj[e].push_back(s);
        len[s].push_back(l);
        len[e].push_back(l);
        s1=s;s2=e;
    }
    multiset<component> s;
    for (long long i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            cur=0;
            dfs(i,-1);
            component x;
            x.sum=cur;
            x.v=i;
            s.insert(x);
        }
    }

    long long k=s.size();
    long long ret=0;
    if (k<q || (k-q)>p || (m==0 && p>0 && k==q))
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        while(k>q)
        {
            k--;
            p--;
            component a;
            component b;
            multiset<component>::iterator it=s.begin();
            a.sum=it->sum;
            a.v=it->v;
            s.erase(it);
            it=s.begin();
            b.sum=it->sum;
            b.v=it->v;
            s.erase(it);
            ret+=min(a.sum+b.sum+1,(long long)1000000000);
            cout<<a.v<<" "<<b.v<<endl;
            a.sum+=min(a.sum+b.sum+1,(long long)1000000000);
            a.sum+=b.sum;
            s.insert(a);
            s1=a.v;
            s2=b.v;
        }

        while(p>0)
        {
            p--;
            cout<<s1<<" "<<s2<<endl;
            ret+=1000;
        }
    }
}