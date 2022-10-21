#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;

struct edge{
    int to, q;
    edge(int _to, int _q){
        to = _to, q = _q;
    }
};

int n,m,k;
int a[N], b[N];
int in[N], res[N];
bool rem[N];
int cur;
vector<edge> G[N];

void dfs(int v){
    rem[v] = false;
    cur--;
    for(edge e : G[v]){
        if(rem[e.to]){
            in[e.to]--;
            if(in[e.to] < k){
                rem[e.to] = false;
                dfs(e.to);
            }
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a[i], &b[i]);
        a[i]--, b[i]--;
        G[a[i]].push_back(edge(b[i], i));
        G[b[i]].push_back(edge(a[i], i));
    }

    cur = n;
    for(int i = 0; i < n; i++) in[i] = G[i].size();
    fill(rem, rem + N, true);

    for(int i = 0; i < n; i++){
        if(rem[i] && in[i] < k){
            dfs(i);
        }
    }

    for(int i = m-1; i >= 0; i--){
        res[i] = cur;
        if(rem[a[i]] && rem[b[i]]) in[a[i]]--, in[b[i]]--;
        G[a[i]].pop_back();
        G[b[i]].pop_back();
        if(rem[a[i]] && in[a[i]] < k) dfs(a[i]);
        if(rem[b[i]] && in[b[i]] < k) dfs(b[i]);
    }
    for(int i = 0; i < m; i++){
        printf("%d\n", res[i]);
    }

}