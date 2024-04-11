#include <iostream>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
const int N = 1000000 + 10;
vector< pair<int,int> > g[N];
int t,n,a[N],vis[N];
void go(int now) {
    set<int> s;
    vector<int> ans;
    while(1){
        if(s.count(now)) break;
        s.insert(now);
        ans.push_back(g[now][0].second);
        now=g[now][0].first;
    }
    printf("%d\n", ans.size());
    for(auto x: ans) printf("%d ", x);
    printf("\n");
}
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
 
        for(int i=1;i<=n;i++){
            vis[i]=0; 
            g[i].clear();
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            int u=i,v=i-a[i];
            //printf("link %d %d\n", u, v);
            g[u].push_back(make_pair(v,i));
        }
        bool fin = 0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                int now=i;
                set<int> s; 
                while(1){
                    if(vis[now]){
                        if (s.count(now)) {
                            go(now); fin = 1;
                        }
                        break;
                    }
                    vis[now]=1; s.insert(now);
                    now=g[now][0].first;
                }
                if (fin) break;
            }
        }
    }
}
/*
i   i-a[i]
*/