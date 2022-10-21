#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500, mod = (int)1e9 + 7;

ll fp(int x, int k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf*hf%mod*x%mod : hf*hf%mod;
}

ll fac[N], facinv[N];
vector<int> p[N];
int q;
int f, n;

ll get_res(int n, int k){
    if(n < k) return 0;
    return fac[n-1] * facinv[k-1] % mod * facinv[n-k] % mod;
}

int main(){
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1LL * fac[i-1] * i % mod;
    facinv[(int)1e5] = fp((int)fac[(int)1e5], mod-2);
    for(int i = (int)1e5 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    for(int i = 2; i < N; i++){
        if(p[i].empty()){
            for(int j = i; j < N; j += i){
                p[j].push_back(i);
            }
        }
    }
    scanf("%d", &q);
    while(q--){
        scanf("%d%d", &n, &f);
        int res = 0;
        for(int i = 0; i < (1 << p[n].size()); i++){
            int s = 1;
            int cur = 1;
            for(int j = 0; j < p[n].size(); j++){
                if((1 << j) & i){
                    s = -s;
                    cur *= p[n][j];
                }
            }
            res += s * get_res(n / cur, f);
            res %= mod;
        }
        printf("%d\n", (res + mod) % mod);
    }

}