#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353, N = (int)2e5 + 500;

int n,m,A;
int b[N];

ll fp(ll x, int k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod : hf * hf % mod;
}

ll inv(ll x){return fp(x, mod - 2);}

int main(){
    scanf("%d%d%d", &n, &m, &A);
    for(int i = 1; i <= m; i++) scanf("%d", &b[i]);

    ll res = 1;
    for(int i = 1; i <= m; i++){
        ll pw = fp(A, b[i] - b[i-1]);
        res *= (pw + pw * pw % mod) % mod;
        res %= mod;
    }
    res *= fp(A, n - 2 * b[m]);
    res %= mod;
    res *= inv(fp(2, m));
    res %= mod;
    cout << res << endl;

}