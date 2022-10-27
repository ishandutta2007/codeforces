#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;
const int N = 2000000+10;
int n,p[N],out[N],in[N],D[N];
vector<int> gragh[N], gg[N];
int vis[N];

void dfs(int u) {
    vis[u] = 1;
    for(int i=0;i<gg[u].size();i++){
        int v=gg[u][i];
        if (vis[v]) continue;
        dfs(v);
        if (out[v]%2==0) {
            out[u]++;  in[v] ++;
            //printf("! %d %d\n", u, v);
            gragh[u].push_back(v);
        } else {
            out[v]++;  in[u] ++;
            //printf("! %d %d\n", v, u);
            gragh[v].push_back(u);
        }
    }
}

int main() {
    scanf("%d", &n);
    int rt;
    for (int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        if (p[i] != 0) {
            gg[p[i]].push_back(i);
            gg[i].push_back(p[i]);
        } else {
            rt = i;
        }
    }
    dfs(rt);
    queue<int> que;

    for(int i=1;i<=n;i++) {
        if (in[i] == 0) {
            que.push(i);
        }
        if (out[i]%2==1) {
            return !printf("NO\n");
        }
    }


    vector<int> ans;
    while (que.size()) {
        int u = que.front(); que.pop();
        ans.push_back(u);

        for(int i=0;i<gragh[u].size();i++) {
            int v = gragh[u][i];
            in[v] --;
            if (in[v] == 0) {
                que.push(v);
            }
        }
    }

    if (ans.size() != n) {
        return !printf("NO\n");
    }

    printf("YES\n");
    for(int i=0;i<ans.size();i++) {
        printf("%d\n", ans[i]);
    }

}