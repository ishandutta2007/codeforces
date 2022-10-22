#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, L, K, ans;
pair<int, int> A[101010];

int main(){
    scanf("%d %d %d", &N, &L, &K);
    for (int i=1; i<=N; i++) scanf("%d %d", &A[i].first, &A[i].second);
    sort(A+1, A+N+1);
    A[N+1] = pair<int, int>(L, 0);
    for (int i=0; i<=N; i++) ans += (A[i+1].first - (A[i].first + A[i].second)) / K;
    printf("%d", ans);
    return 0;
}