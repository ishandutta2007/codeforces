#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long LL;

int N, K;
int A[202020];
int BIT[202020];
bool chk[202020];
vector<int> V;
LL P;

LL Pow(LL x, LL y){
    if (y <= 0) return 1;
    if (y == 1) return x;
    LL z = Pow(x, y/2);
    if (y&1) return (z*z%MOD) * x % MOD;
    return z * z % MOD;
}

void update(int k){
    while (k<=N){
        BIT[k]++;
        k += (k & -k);
    }
}

int read(int k){
    int ret = 0;
    while (k>0){
        ret += BIT[k];
        k -= (k & -k);
    }
    return ret;
}

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
        if (A[i] == -1) K++;
        else {
            chk[A[i]] = true;
            P += read(N) - read(A[i]);
            P %= MOD;
            update(A[i]);
        }
    }
    for (int i=1; i<=N; i++) if (!chk[i]) V.push_back(i);
    int cnt = 0;
    for (int i=1; i<=N; i++){
        if (A[i] == -1){
            cnt++;
            continue;
        }
        int k = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
        P += (Pow(K, MOD-2) * cnt % MOD) * (K - k) % MOD;
        P %= MOD;
        P += (Pow(K, MOD-2) * (K - cnt) % MOD) * k % MOD;
        P %= MOD;
    }
    P += (Pow(4, MOD-2) * (K-1) % MOD) * K % MOD;
    P %= MOD;
    printf("%lld\n", P);
    return 0;
}