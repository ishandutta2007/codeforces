#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, K, ans;
int A[101010], S[101010];

int main(){
    int a;
    scanf("%d %*d %d", &N, &K);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    for (int i=1; i<N; i++) S[i] = A[i+1] - A[i] - 1;
    sort(S+1, S+N);
    for (int i=1; i<=N-K; i++) ans += S[i];
    printf("%d\n", ans+N);
    return 0;
}