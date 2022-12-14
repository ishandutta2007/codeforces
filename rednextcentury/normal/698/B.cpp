#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int comp[1000000];
vector<int> G[1000000];
void add(int u,int v){
    for (auto x:G[u]){
        G[v].push_back(x);
        comp[x]=v;
    }
    G[u].clear();
}
int root;
int ret;
void dsu(int u,int v){
    int x=u,y=v;
    u = comp[u], v= comp[v];
    if (u==v){
        if (root==-1){
            a[x]=x;
            root=x;
        } else
            a[x]=root;
        ret++;
        return;
    }
    if (G[u].size()<G[v].size())add(u,v);
    else add(v,u);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    root=-1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        comp[i]=i;
        G[i].push_back(i);
        if (a[i]==i)root=a[i];
    }
    ret=0;
    for (int i=1;i<=n;i++){
        int u = i, v=a[i];
        if (u==v && u!=root){
            a[i]=root;
            ret++;
        } else if (u!=v){
            dsu(u,v);
        }
    }
    cout<<ret<<endl;
    for (int i=1;i<=n;i++)cout<<a[i]<<' ';
}