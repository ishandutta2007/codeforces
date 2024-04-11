#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
int L[101010], R[101010];
LL ans;

int main(){
    int l, r;
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d %d", &L[i], &R[i]);
    sort(L+1, L+N+1);
    sort(R+1, R+N+1);
    for (int i=1; i<=N; i++) ans += max(L[i], R[i]);
    printf("%I64d", ans+N);
    return 0;
}