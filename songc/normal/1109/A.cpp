#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
LL ans;
int A[303030];
int cnt[2][2200000];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
        A[i] ^= A[i-1];
    }
    cnt[0][0] = 1;
    for (int i=1; i<=N; i++){
        ans += cnt[i%2][A[i]];
        cnt[i%2][A[i]]++;
    }
    printf("%lld\n", ans);
    return 0;
}