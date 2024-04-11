#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 5, INF = (int)1e9 + 50;

int n;
vector<int> G[N];
int a[N];
int s[N], submn[N];
ll res = 0;

int dfs(int v, int p){
    int res;
    for(int nxt : G[v]){
        if(nxt != p){
            submn[v] = min(submn[v], dfs(nxt, v));
        }
    }
    res = submn[v];
    if(s[v] != -1) res = min(res, s[v]);
    return res;
}

int ndfs(int v, int p){
    if(s[v] != -1){
        if(s[v] > submn[v]) return -1;
        else res += s[v] - s[p];
    }
    else{
        if(submn[v] == INF) s[v] = s[p];
        else s[v] = submn[v];
        res += s[v] - s[p];
    }
    for(int nxt : G[v]){
        if(nxt != p) if(ndfs(nxt, v) == -1) return -1;
    }
    return 1;
}

int main(){
    fill(submn, submn + N, INF);
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        int p;
        scanf("%d", &p);
        G[i].push_back(p);
        G[p].push_back(i);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
    dfs(1, 0);
    if(ndfs(1, 0) == -1) return !printf("-1");
    else return !printf("%I64d\n", res);
}