#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
int L[202020], R[202020];
int S[202020], Max[202020];
pii A[202020];

int main(){
    scanf("%d %*d", &N);
    memset(L, 1, sizeof L);
    for (int i=1; i<=N; i++){
        int x;
        scanf("%d", &x);
        L[x] = min(L[x], i), R[x] = i;
        S[x]++;
    }
    for (int i=1; i<=200000; i++) A[i] = pii(L[i], i);
    sort(A+1, A+200001);
    int u=0, E=0;
    for (int i=1; i<=200000; i++){
        if (A[i].first > E) u = A[i].second;
        Max[u] = max(Max[u], S[A[i].second]);
        E = max(E, R[A[i].second]);
    }
    for (int i=1; i<=200000; i++) N -= Max[i];
    printf("%d\n", N);
    return 0;
}