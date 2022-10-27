// 23:12
#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N=200000+10;
vector<int> g[N];
int n;
pair<int,int> down[N],up[N];
int par[N];
void dfs(int u,int p){
    par[u]=p;
    down[u]=up[u]=make_pair(0,u);
    for(auto v: g[u]) {
        if(v==p)continue;
        dfs(v,u);
        down[u]=max(make_pair(down[v].first+1,down[v].second),down[u]);
    }
}
int ans=0;vector<int> res;
void dfs2(int u,int p){
    multiset<pair<int,int> > st;
    for(auto v:g[u]){
        if(v==p)continue;
        st.insert(make_pair(down[v].first+1, down[v].second));
    }
    st.insert(up[u]);
    for(auto v:g[u]){
        if(v==p)continue;
        st.erase(st.find(make_pair(down[v].first+1, down[v].second)));
        up[v]=make_pair(((*st.rbegin()).first)+1,(*st.rbegin()).second);
        dfs2(v,u);
        st.insert(make_pair(down[v].first+1, down[v].second));
    }
    int c=0;vector<int> tmp;
    //printf("u=%d\n", u);
    for(int i=0;i<3;i++){
        if(st.size()){
            //printf("(%d,%d)\n", (*st.rbegin()).first, (*st.rbegin()).second);
            c+=(*st.rbegin()).first;
            tmp.push_back((*st.rbegin()).second);
            st.erase(st.find(*st.rbegin()));
        }
    }
    if(tmp.size()<2) return;
    if(tmp.size()==2) tmp.push_back(u); 
    if(c>ans){
        ans=c; res=tmp;
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y; scanf("%d%d",&x,&y);
        g[x].push_back(y); g[y].push_back(x);
    }
    dfs(1,1);
    dfs2(1,1);
    cout<<ans<<endl;
    for(auto x: res) cout<<x<<" ";
}