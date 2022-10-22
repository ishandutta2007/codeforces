#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long LL;

int T, N, M;
LL ans = 1;
int C[303030];
int A, B;
vector<int> L[303030];

LL twopow(int k){
    LL ret = 1;
    for (int i=1; i<=k; i++)ret = (ret * 2) % MOD;
    return ret;
}

bool dfs(int u, int c){
    C[u] = c;
    if (c == 1) A++;
    else B++;

    for (int v : L[u]){
        if (C[u] == C[v]) return true;
        if (!C[v]) if (dfs(v, 3-c)) return true;
    }
    return false;
}

int main(){
    int u, v;
    scanf("%d", &T);
    while (T--){
        scanf("%d %d", &N, &M);
        for (int i=1; i<=N; i++) C[i] = 0, L[i].clear();
        for (int i=1; i<=M; i++){
            scanf("%d %d", &u, &v);
            L[u].push_back(v);
            L[v].push_back(u);
        }
        ans = 1;
        for (int i=1; i<=N; i++){
            if (C[i]) continue;
            A = B = 0;
            if (dfs(i, 1)){
                ans = 0;
                break;
            }
            ans = (ans * ((twopow(A) + twopow(B)) % MOD)) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}