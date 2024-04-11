#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[202020], B[202020];
int st[202020];
bool visit[202020];

struct edge{
    int s, e;
    bool operator<(const edge &r)const{
        if (s == r.s) return B[e] < B[r.e];
        return s < r.s;
    }
} adj[404040];

deque<int> Q;

int main(){
    scanf("%d", &N);
    M = 2*(N-1);
    for (int i=0; i<N-1; i++){
        scanf("%d %d", &adj[i].s, &adj[i].e);
        adj[i+N-1].s = adj[i].e;
        adj[i+N-1].e = adj[i].s;
    }
    for (int i=1; i<=N; i++){
        scanf("%d", &A[i]);
        B[A[i]] = i;
    }
    sort(adj, adj+M);
    st[adj[0].s] = 0;
    for (int i=1; i<M; i++) if (adj[i-1].s != adj[i].s) st[adj[i].s] = i;

    Q.push_back(1);
    visit[1] = true;
    for (int i=1; i<=N; i++){
        int F = Q.front();
        Q.pop_front();
        if (F != A[i]) {
            puts("No");
            return 0;
        }
        for (int i=st[F]; adj[i].s == F; i++){
            if (visit[adj[i].e]) continue;
            Q.push_back(adj[i].e);
            visit[adj[i].e] = true;
        }
    }
    puts("Yes");
    return 0;
}