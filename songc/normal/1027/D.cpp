#include <bits/stdc++.h>
using namespace std;

int N;
int C[202020];
int A[202020];
int cycle[202020];
int Min[202020], ans;
bool visit[202020];

int f(int u){
    if (visit[u]){
        if (cycle[u] || cycle[u] == -1) return 0;
        else return cycle[u] = u;
    }
    visit[u] = true;
    int ret = f(A[u]);
    if (!ret) {
        cycle[u] = -1;
        return 0;
    }
    if (cycle[u]) return 0;
    return cycle[u] = ret;
}

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", &C[i]);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    for (int i=1; i<=N; i++) if (!visit[i]) {
        f(i);
    }
    for (int i=1; i<=N; i++) if (cycle[i]){
        if (!Min[cycle[i]] || Min[cycle[i]] > C[i]) Min[cycle[i]] = C[i];
    }
    for (int i=1; i<=N; i++) ans += Min[i];
    printf("%d", ans);
    return 0;
}