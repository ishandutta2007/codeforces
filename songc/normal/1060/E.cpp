#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
vector<int> L[202020];
LL S[202020], Cnt[202020];
LL ans, O;

void dfs(int pa, int u, bool odd){
    if (odd) O++;
    for (auto it : L[u]){
        if (it == pa) continue;
        dfs(u, it, !odd);
        S[u] += S[it];
        Cnt[u] += Cnt[it];
    }
    for (auto it : L[u]){
        if (it == pa) continue;
        ans += S[it] * (Cnt[u] - Cnt[it]);
    }
    ans += S[u];
    Cnt[u]++;
    S[u] += Cnt[u];
}

int main(){
    int s, e;
    scanf("%d", &N);
    for (int i=1; i<N; i++){
        scanf("%d %d", &s, &e);
        L[s].push_back(e);
        L[e].push_back(s);
    }
    dfs(0, 1, true);
    printf("%I64d\n", (ans-(O * (N-O)))/2 + (O * (N-O)));
    return 0;
}