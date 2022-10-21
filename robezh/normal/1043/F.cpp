#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;
const int N = 300050, M = N;

int n, num[N];
bool p[M];
int mu[M], pm[M], pms;
ll fac[M], facinv[M];
int cnt[N];

ll fp(ll x, int k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

void get_mobius_and_sieve(){
    mu[1] = 1;
    fill(p, p + M, true);
    pms = 0;
    for(int i = 2; i < M; i++){
        if(p[i]){
            pm[pms++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = false;
            if(i % pm[j] == 0){
                mu[i * pm[j]] = 0;
                break;
            }
            mu[i * pm[j]] = -mu[i];
        }
    }
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

int main(){
    get_mobius_and_sieve();

    fac[0] = 1;
    for(int i = 1; i <= 300000; i++) fac[i] = fac[i-1] * i % mod;
    facinv[300000] = fp(fac[300000], mod - 2);
    for(int i = 300000 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
    memset(cnt, 0, sizeof(cnt));


    int g = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]); g = __gcd(num[i], g);
        int j;
        for(j = 1; j * j < num[i]; j++){
            if(num[i] % j == 0){
                cnt[j] ++;
                cnt[num[i]/j] ++;
            }
        }
        if(j * j == num[i]) cnt[j] ++;

    }
    if(g > 1) return !printf("-1");
//    if(m == 1) return !printf("1");

    for(int ans = 1; ans <= min(n, 7); ans++){
        ll sum = 0;
        for(int i = 1; i <= 300000; i++){
            if(cnt[i] >= ans) sum = (sum + comb(cnt[i], ans) * mu[i]) % mod;
        }
        if(sum != 0) return !printf("%d", ans);
    }
    return !printf("-1");
}