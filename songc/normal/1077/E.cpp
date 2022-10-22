#include <bits/stdc++.h>
using namespace std;

int N, ans;
map<int, int> M;
int A[404040];
int sum[404040];
int D[404040];

int main(){
    int a;
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &a);
        M[a]++;
    }
    N=1;
    for (auto it : M) A[N++] = it.second;
    N--;
    sort(A+1, A+N+1);
    for (int i=1; i<=N; i++) sum[i] = sum[i-1] + A[i];
    for (int i=1; i<=N; i++){
        for (int j=1; j<=A[i]; j++){
            D[sum[i-1] + j] = max(D[sum[i-1] + j], j);
            int nx = lower_bound(A+i+1, A+N+1, 2*j) - A;
            if (A[nx]) D[sum[nx-1] + 2*j] = max(D[sum[nx-1] + 2*j], D[sum[i-1] + j] + 2*j);
            ans = max(ans, D[sum[i-1] + j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}