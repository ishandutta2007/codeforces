#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[1000000];
int sz[1000000];
int dep[1000000];
int mx[1000000];
void pre(int v,int d=0) {
    sz[v]=1;
    dep[v]=d;
    mx[v]=dep[v];
    for (auto u:adj[v])pre(u,d+1),sz[v]+=sz[u],mx[v]=max(mx[u],mx[v]);
}
vector<int> ret;
int loc[1000000];
void pre2(int v)
{
    loc[v]=ret.size();
    ret.push_back(v);
    vector<pair<int,int> > cur;
    for (auto u:adj[v])cur.emplace_back(mx[u],u);
    sort(cur.begin(),cur.end());
    for (auto u:cur) {
        pre2(u.second);
    }
}
vector<int> mv;
int num[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<n;i++) {
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    pre(0);
    pre2(0);
    for (int i=0;i<n;i++)cout<<ret[i]<<' ';
    cout<<endl;
    int num=0;
    for (int i=0;i<n;i++){
        int v = ret[i];
        while(loc[v]-num>dep[v])num++,mv.push_back(v);
    }
    assert(mv.size()<=1e6);
    cout<<mv.size()<<endl;
    for (auto x:mv)cout<<x<<' ';
}