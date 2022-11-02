#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define N 1000010

int n, k, a[N], L[N], R[N];

int S1(int x) {
    int m = x / (k - 1);
    return 1ll * (x - k + 1 + x % (k - 1)) * m / 2 % mod;
}

int S2(int x) {
    if(x < k) return 0;
    return S1(x);
}

int calc(int i, int l, int r) {
    return ((S2(r-l+1) - S2(i-l) - S2(r-i)) % mod + mod) % mod;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) {
        L[i] = i - 1;
        while(L[i] && a[L[i]] < a[i]) L[i] = L[L[i]];
    }
    for(int i = n; i; i --) {
        R[i] = i + 1;
        while(R[i] <= n && a[R[i]] <= a[i]) R[i] = R[R[i]];
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) ans = (ans + 1ll * calc(i, L[i] + 1, R[i] - 1) * a[i]) % mod;
    printf("%d\n", ans);
}