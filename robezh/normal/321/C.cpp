#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e5 + 500;

int n,a,b;
vector<int> G[MAXN];
bool vis[20][MAXN], vis2[20][MAXN];
int sub[20][MAXN];
char res[MAXN];

void sdfs(int v, int dep){
    vis[dep][v] = 1;
    sub[dep][v] = 1;
    for(int nxt : G[v]){
        if(!vis[dep][nxt] && res[nxt] == 0){
            sdfs(nxt, dep);
            sub[dep][v] += sub[dep][nxt];
        }
    }

}

int find_centroid(int v, int dep, int cnt){
    vis2[dep][v] = 1;
    for(int nxt : G[v]){
        if(!vis2[dep][nxt] && sub[dep][nxt] >= cnt+1){
            return find_centroid(nxt, dep, cnt);
        }
    }
    return v;
}

void solve(int v, int dep){
    sdfs(v,dep);
    int cntr = find_centroid(v, dep, sub[dep][v]/2);
    res[cntr] = char('A' + dep);
    for(int nxt : G[cntr]){
        if(res[nxt] == 0){
            solve(nxt, dep+1);
        }
    }

}


int main(){
    for(int i = 0; i < 20; i++) fill(vis[i], vis[i]+MAXN, 0);
    fill(res, res+MAXN, 0);
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    solve(0,0);
    for(int i = 0; i < n; i++) cout << res[i] << " ";
}