#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50, INF = (int)1e9 + 500;
typedef pair<int, int> P;

int n, k;
int dis[N], mxd = 0;
vector<P> G[N];
int offset[N], xo[N];
bool on[N];
int fa[N];
vector<int> path;

void dfs(int v, int par, int len){
    dis[v] = len;
    fa[v] = par;
    if(dis[v] > dis[mxd]) mxd = v;

    for(auto p : G[v]){
        if(p.first == par || on[p.first]) continue;
        dfs(p.first, v, len + p.second);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }

    mxd = 0;
    dfs(0, -1, 0);
    int fir = mxd;
    dfs(fir, -1, 0);

    for(int i = mxd; i != -1; i = fa[i]){
        path.push_back(i);
        xo[path.size()-1] = dis[mxd] - dis[i];
        on[i] = true;
//        cout << i + 1 << " " << xo[path.size()-1] << endl;
    }

    for(int i = 0; i < path.size(); i++){
        int x = path[i];
        mxd = x;
        dfs(x, -1, 0);
        offset[x] = dis[mxd];
    }

    int res = INF;
    deque<P> dque;

    k = min(k, (int)path.size());
    for(int i = 0, j = 0; i + k <= path.size(); i++){
        while(j < i + k){
            while(!dque.empty() && offset[path[j]] > dque.back().second) dque.pop_back();
            dque.push_back({j, offset[path[j]]});
            j++;
        }
        while(dque.front().first < i) dque.pop_front();
        int cur = max(dque.front().second, max(xo[path.size()-1] - xo[i+k-1], xo[i]));
//        cout << i - k + 1 << " to " << i << " : " << cur << endl;
        res = min(res, cur);
    }
    cout << res << endl;
}