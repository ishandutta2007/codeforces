#include <bits/stdc++.h>
using namespace std;
const int MAX_N=2e5+10;

int n,u,v,ans=0,a,b,c;
vector<int> G[MAX_N];
int dep[MAX_N];
pair<int,int> Max[MAX_N];

void dfs1(int v,int p){
    Max[v]={0,v};
    for (int u:G[v]){
        if (u==p) continue;
        dep[u]=dep[v]+1;
        dfs1(u,v);
        if (Max[v].first<Max[u].first+1)
            Max[v]={Max[u].first+1,Max[u].second};
    }
}

void dfs2(int v,int p,int D,int d){
    int M1=D,M2=0,M3=0,m1=d,m2=v,m3=v;
    for (int u:G[v]){
        if (u==p) continue;
        if (M1<=Max[u].first+1){
            M3=M2; M2=M1; M1=Max[u].first+1;
            m3=m2; m2=m1; m1=Max[u].second;
        } else if (M2<=Max[u].first+1){
            M3=M2; M2=Max[u].first+1;
            m3=m2; m2=Max[u].second;
        } else if (M3<Max[u].first+1){
            M3=Max[u].first+1; m3=Max[u].second;
        }
    }
    if (m1!=m2&&m2!=m3&&m3!=m1&&ans<M1+M2+M3){
        ans=M1+M2+M3;
        a=m1+1,b=m2+1,c=m3+1;
    }
    for (int u:G[v]){
        if (u==p) continue;
        if (Max[u].second==m1) dfs2(u,v,M2+1,m2);
        else dfs2(u,v,M1+1,m1);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n-1;++i){
        cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs1(0,-1);
    dfs2(0,-1,0,0);
    cout << ans << '\n';
    cout << a << ' ' << b << ' ' << c << '\n';
}