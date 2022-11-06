#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()

pair<int,int> ask(vector<int>vv){
    cout<<"? "<<vv.size();
    for(auto v:vv)cout<<" "<<v+1;
    cout<<endl;
    int x,d;
    cin>>x>>d;
    if(x==-1&&d==-1)exit(0);
    return mp(x,d);
}

vector<int>g[1111];
vector<pair<int,int>>vvv;
int tt,ddd[1111];

void dfs(int v,int pr=-1){
    vvv.pb({tt++,v});
    for(auto u:g[v]){
        if(u!=pr)dfs(u,v);
    }
}

void dfs1(int v,int pr=-1){
    for(auto u:g[v]){
        if(u!=pr){
            ddd[u]=ddd[v]+1;
            dfs1(u,v);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)g[i].clear();
    vvv.clear();
    tt=0;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int>vv;
    for(int i=0;i<n;i++)vv.pb(i);
    int d=ask(vv).ss;
    dfs(0);
    sort(all(vvv));
    int l=0,r=n;
    while(r-l>1){
        int m=(l+r)/2;
        vv.clear();
        for(int i=m;i<n;i++)vv.pb(vvv[i].ss);
        int dd=ask(vv).ss;
        if(dd==d)l=m;else r=m;
    }
    int s=vvv[l].ss;
    ddd[s]=0;
    dfs1(s);
    vv.clear();
    for(int i=0;i<n;i++){
        if(ddd[i]==d)vv.pb(i);
    }
    int f=ask(vv).ff;
    cout<<"! "<<s+1<<" "<<f<<endl;
    string t;
    cin>>t;
    if(t=="Incorrect")exit(0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}