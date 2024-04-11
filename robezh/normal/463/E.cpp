#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, M = (int)2e6 + 500, ss = (int)150000;
typedef pair<int, int> P;

void upd_max(P &to, P from){
    if(from.first > to.first){
        to.first = from.first;
        to.second = from.second;
    }
}

int n,q,a,b;
int num[N];
int p[M], idx[M];
int depth[N];
vector<int> G[N];
int pm[ss], pms = 0;
stack<int> S[ss];
vector<P> res;

void dfs(int v, int par = -1){
    depth[v] = (par == -1 ? 0 : depth[par] + 1);

    vector<int> curpms;
    int cur = num[v];
    while(cur > 1){
        int cur_pi = p[cur];
        if(!S[idx[cur_pi]].empty()){
            int tp = S[idx[cur_pi]].top();
            upd_max(res[v], {depth[tp], tp});
        }
        S[idx[cur_pi]].push(v);
        curpms.push_back(cur_pi);
        while(cur % cur_pi == 0){
            cur /= cur_pi;
        }
    }
    for(int nxt : G[v]){
        if(nxt == par) continue;
        dfs(nxt, v);
    }

    for(int x : curpms) S[idx[x]].pop();
}

int main(){
    for(int i = 0; i < M; i++) p[i] = i;
    for(int i = 2; i < M; i++){
        if(p[i] != i) continue;
        idx[i] = pms;
        pm[pms++] = i;
        for(int j = i * 2; j < M; j += i){
            p[j] = i;
        }
    }
    int cnt = 0;

    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }


    bool changed = true;
    while(q--){
        if(changed){
            res.assign(n, {-1,-1});
            dfs(0);
            changed = false;
        }
        scanf("%d", &a);
        if(a == 1){
            int x;
            scanf("%d", &x);
            x--;
            printf("%d\n", res[x].first == -1 ? -1 : res[x].second + 1);
        }
        else{
            int x,y;
            scanf("%d%d", &x, &y);
            x--;
            num[x] = y;
            changed = true;
        }
    }
}