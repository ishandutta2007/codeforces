#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, M;
int P[505050];
int S[505050];

int Find(int u){
    if (P[u] == u) return u;
    return P[u] = Find(P[u]);
}

void Union(int u, int v){
    int pu = Find(u);
    int pv = Find(v);
    if (pu == pv) return;
    P[pu] = pv;
    S[pv] += S[pu];
}

int main(){
    int k, u, v;
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) P[i] = i, S[i] = 1;
    for (int i=1; i<=M; i++){
        scanf("%d", &k);
        if (k == 0) continue;
        scanf("%d", &u);
        for (int i=2; i<=k; i++){
            scanf("%d", &v);
            Union(u, v);
        }
    }
    for (int i=1; i<=N; i++) printf("%d ", S[Find(i)]);
    return 0;
}