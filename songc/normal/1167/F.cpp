#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
int C[505050];
LL A[505050];
LL BIT[505050];
LL ans;

void update(int k, int v){
    while (k<=N){
        BIT[k] = (BIT[k] + v) % MOD;
        k += k & -k;
    }
}

LL read(int k){
    LL ret=0;
    while (k){
        ret = (ret + BIT[k]) % MOD;
        k -= k & -k;
    }
    return ret;
}

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        scanf("%d", &C[i]);
        A[i] = C[i];
    }
    sort(C+1, C+N+1);
    for (int i=1; i<=N; i++){
        ans += (((A[i] * i) % MOD) * (N-i+1)) % MOD;
        ans %= MOD;
    }
    for (int i=1; i<=N; i++){
        int k = lower_bound(C+1, C+N+1, A[i]) - C;
        ans += (((read(k) * (N-i+1)) % MOD) * A[i]) % MOD;
        ans %= MOD;
        update(k, i);
    }
    for (int i=1; i<=N/2; i++) swap(A[i], A[N-i+1]);
    for (int i=1; i<=N; i++) BIT[i] = 0;
    for (int i=1; i<=N; i++){
        int k = lower_bound(C+1, C+N+1, A[i]) - C;
        ans += (((read(k) * (N-i+1)) % MOD) * A[i]) % MOD;
        ans %= MOD;
        update(k, i);
    }
    printf("%lld\n", ans);
    return 0;
}