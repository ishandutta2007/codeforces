#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int N=600000+10;
map< vector<int>, int > mp; 
map< pair<int,int>, int > has;
int tot;
int n,m,u[N],v[N],belong[N];
vector<int> vec[N],g[N];
vector<int> gragh[N], ans[N];

int now = 0, setID[N], vis[N];
void dfs(int u,int p) {
    //printf("u=%d\n", u);
    vis[u]=1; int son=0; setID[u] = ++now;
    for(auto v: gragh[u]) {
        if(v==p)continue;
        //printf("%d->%d\n", u,v);
        if(vis[v]) {
            printf("NO\n"); exit(0);
        }
        dfs(v,u); son ++;
    }
    if(son >= 2) {
        printf("NO\n"); exit(0);
    }
}

void build() {
    for(int i=1;i<=m;i++){
        int x=belong[u[i]], y=belong[v[i]];
        if(x!=y) {
            gragh[x].push_back(y);
            gragh[y].push_back(x);
        }
    }
    for(int i=1;i<=n;i++) {
        sort(gragh[i].begin(), gragh[i].end());
        gragh[i].erase(unique(gragh[i].begin(),gragh[i].end()), gragh[i].end());
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==0 && gragh[i].size() <= 1) {
            //printf("start\n");
            dfs(i,i); ++now;
        }
    }
    //printf("build finish\n");
}

void chk() {
    
    int mx=0;
    for(int i=1;i<=n;i++) {
        ans[setID[belong[i]]].push_back(i);
        mx=max(mx,setID[belong[i]]);
    }
    //printf("mx = %d\n", mx);
    int cnt = 0;
    for(int i=1;i<=mx;i++) {
        for(int x=0;x<ans[i].size();x++){
            for(int y=x+1;y<ans[i].size();y++) {
                if(has[make_pair(ans[i][x],ans[i][y])]) {
                    //printf("%d-%d\n", ans[i][x],ans[i][y]);
                    cnt ++;
                } else {
                    printf("NO\n"); exit(0);
                }
            }
        }

        for(int x=0;x<ans[i].size();x++){
            for(int y=0;y<ans[i-1].size();y++){
                if(has[make_pair(ans[i][x],ans[i-1][y])]) {
                    //printf("%d-%d\n", ans[i][x],ans[i-1][y]);
                    cnt ++;
                } else {
                    printf("NO\n"); exit(0);
                }
            }
        }
        /*
        for(int x=0;x<ans[i].size();x++){
            for(int y=0;y<ans[i+1].size();y++){
                if(has[make_pair(ans[i][x],ans[i+1][y])]) {
                    printf("%d-%d\n", ans[i][x],ans[i+1][y]);
                    cnt ++;
                } else {
                    printf("NO\n"); exit(0);
                }
            }
        }
        */
    }
    //printf("cnt = %d\n", cnt);
    if (cnt != m) {
        printf("NO\n"); exit(0);
    }
    
    printf("YES\n");
    for(int i=1;i<=n;i++) {
        printf("%d ", setID[belong[i]]);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u[i],&v[i]);
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        has[make_pair(u[i],v[i])] = has[make_pair(v[i],u[i])] = 1;
    }
    for(int i=1;i<=n;i++){
        g[i].push_back(i); sort(g[i].begin(),g[i].end());
        if(mp[g[i]] == 0) mp[g[i]]=++tot;
        int id = mp[g[i]];
        belong[i]=id; vec[id].push_back(i);
    }
    for(int i=1;i<=n;i++) {
        //printf("belong[%d]=%d\n", i,belong[i]);
    }
    build(); chk();
}