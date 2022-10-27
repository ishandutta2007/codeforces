#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
const LL MOD = 1e9+9;
int m,x[N],y[N],out[N],used[N];
map< pair<int,int>, int > mp;
vector<int> g[N],rg[N];
LL p[N];

int main() {
    scanf("%d",&m);
    p[0]=1;for(int i=1;i<N;i++)p[i]=p[i-1]*m%MOD;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x[i],&y[i]);
        mp[make_pair(x[i],y[i])] = i;
    }
    for(int i=1;i<=m;i++){
        if(mp[make_pair(x[i]-1,y[i]-1)]) 
        {
            g[i].push_back(mp[make_pair(x[i]-1,y[i]-1)]);
            rg[mp[make_pair(x[i]-1,y[i]-1)]].push_back(i);
            out[i]++;
        }
        if(mp[make_pair(x[i],y[i]-1)]) 
        {
            g[i].push_back(mp[make_pair(x[i],y[i]-1)]);
            rg[mp[make_pair(x[i],y[i]-1)]].push_back(i);
            out[i]++;
        }
        if(mp[make_pair(x[i]+1,y[i]-1)]) 
        {
            g[i].push_back(mp[make_pair(x[i]+1,y[i]-1)]);
            rg[mp[make_pair(x[i]+1,y[i]-1)]].push_back(i);
            out[i]++;
        }
    }

    set<int> st;
    for(int i=1;i<=m;i++){
        bool ok=1;
        for(auto x: rg[i]) {
            if(out[x]==1) ok=0;
        }
        if(ok) st.insert(i);
    }
    
    LL ans=0;
    int R=0;
    while(st.size())
    {   
        int u;
        if(R%2==0) {
            u=*st.rbegin(); st.erase(u);
        } else {
            u=*st.begin();  st.erase(u);
        }
        if(used[u]) continue;
        //printf("u=%d\n", u);
        used[u] = 1;
        (ans += p[m-R-1]*(u-1)%MOD) %= MOD;
        R++;
        for(auto v:rg[u]){
            if(used[v]) continue;
            out[v] --;
            for(auto w:g[v]){
                if(used[w]) continue;
                if(out[v]==1) st.erase(w);
            }
        }
        for(auto v:g[u]){
            if(used[v]) continue;
            bool ok=1;
            for(auto x: rg[v]) {
                if(used[x]) continue;
                if(out[x]==1) ok=0;
            }
            if(ok) st.insert(v);
        }
    }
    cout<<ans<<endl;
}