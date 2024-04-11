#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, M, K, p=1;
LL D[101010][220], ans=1234567890123456ll;
LL C[101010], T[101010];

struct DATA{
    int s, e, t, w;
    bool operator<(const DATA &r)const{
        if (w == r.w) return t < r.t;
        return w < r.w;
    }
} E[101010];

priority_queue<DATA> PQ;

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for (int i=1; i<=K; i++) scanf("%d %d %d %d", &E[i].s, &E[i].e, &E[i].t, &E[i].w);
    sort(E+1, E+K+1, [&](DATA A, DATA B){
        return A.s < B.s;
    });
    for (int i=1; i<=N; i++){
        while (E[p].s == i){
            PQ.push(E[p]);
            p++;
        }
        while (!PQ.empty() && PQ.top().e < i) PQ.pop();
        if (!PQ.empty()){
            C[i] = PQ.top().w;
            T[i] = PQ.top().t;
        }
    }
    memset(D, 31, sizeof D);
    D[1][0] = 0;
    for (int i=1; i<=N; i++){
        for (int j=0; j<=M; j++){
            if (C[i] == 0){
                D[i+1][j] = min(D[i+1][j], D[i][j]);
                continue;
            }
            D[T[i]+1][j] = min(D[T[i]+1][j], D[i][j] + C[i]);
            if (j < M) D[i+1][j+1] = min(D[i+1][j+1], D[i][j]);
        }
    }
    for (int i=0; i<=M; i++) ans = min(ans, D[N+1][i]);
    printf("%lld\n", ans);
    return 0;
}