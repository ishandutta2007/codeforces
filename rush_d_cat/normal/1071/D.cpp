#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int N=1000000+10;
const int B=25;
bool cmp(int x,int y){
    return x>y;
}
int prime[N],d[N],vis[N],flag[N];
void init(){
    for(int i=2;i<N;i++){
        if(vis[i]==0){
            prime[++prime[0]]=i, d[i]=i;
        }
        for(int j=1;j<=prime[0] && prime[j]*i<N;j++){
            vis[i*prime[j]]=1; d[i*prime[j]]=prime[j];
            if(i%prime[j]==0)break;
        }
    }
}
vector<int> vec,g[N];
map< vector<int>,int > mp; int tot=0,cnt[N],id[N];
int cac(vector<int> v) {
    int M=1;
    for(auto x: v) M*=(x+1);
    return M;
}
void dfs(int sum,int low){
    if(!mp[vec]) {
        int val = cac(vec); if(val>300)return;
        mp[vec]=++tot;
        cnt[tot]=val;
    }
    for(int i=low;i>=1;i--){
        if(sum+i<=B) {
            vec.push_back(i); dfs(sum+i, i); vec.pop_back();
        }
    }
}
void build(){
    int edge=0;
    for(auto p: mp) {
        vector<int> u=p.first, v;
        for(int i=0;i<u.size();i++){
            v=u,v[i]++,sort(v.begin(),v.end(),cmp);
            if(mp.count(v)) {
                g[mp[u]].push_back(mp[v]); edge++;
            }
            v=u,v[i]--,sort(v.begin(),v.end(),cmp);
            if(mp.count(v)) {
                if(v[(int)v.size()-1]==0)v.pop_back();
                g[mp[u]].push_back(mp[v]); edge++;
            }
        }
        v=u;v.push_back(1);sort(v.begin(),v.end(),cmp);
        if(mp.count(v)){
            g[mp[u]].push_back(mp[v]); edge++;
        }
    }
}
vector<int> fac(int x) {
    vector<int> ans;
    while(x>1) {
        int t=d[x],c=0;
        while(x%t==0){
            x/=t; c++;
        }
        ans.push_back(c);
    }
    sort(ans.begin(),ans.end(),cmp);
    return ans;
}

int dis[302][26002],ans[302][302];
void bfs(int x){
    int src = mp[fac(x)];
    if(flag[src])return; flag[src]=1;
    //printf("src=%d\n", id[src]);
    queue<int> q; q.push(src); 
    for(int i=1;i<26000;i++)dis[id[src]][i]=-1;
    dis[id[src]][src]=0;
    //printf("ok\n");
    
    while(q.size()) {
        int u=q.front(); q.pop();
        //printf("u=%d\n", u);
        for(auto v: g[u]){
            //printf("v=%d\n", v);
            if(dis[id[src]][v]==-1) {
                dis[id[src]][v]=dis[id[src]][u]+1; q.push(v);
            }
        }
    }
    //printf("finish!, x=%d\n",x);
    for(int i=1;i<26000;i++)
        if(dis[id[src]][i]!=-1){
            //printf("%d\n", cnt[i]);
            ans[id[src]][cnt[i]]=min(ans[id[src]][cnt[i]],dis[id[src]][i]);
        }
    //printf("gougoushishabi\n");
}

set<int> st;
int main() {
    init(); dfs(0,B); 
    build();
    for(int i=0;i<=300;i++)for(int j=0;j<=300;j++)ans[i][j]=1e9;
    
    for(int i=1;i<N;i++){
        int x=mp[fac(i)];
        st.insert(x);
    }
    int bu=0;
    for(auto x: st) {
        id[x]=++bu;
    }
    //printf("%d\n", st.size());
    //printf("%d\n", mp.size());
    //printf("ok\n");
    //
    //return 0;
    int T;scanf("%d",&T);
    while(T --) {
        int a,b; scanf("%d%d",&a,&b);
        bfs(a); bfs(b); int ret=1000;
        int u = id[mp[fac(a)]], v=id[mp[fac(b)]];
        for(int i=1;i<=300;i++) {
            //printf("# %d %d\n", ans[u][i], ans[v][i]);
            ret=min(ret,ans[u][i]+ans[v][i]);
        }
        printf("%d\n", ret);
    }
    
}