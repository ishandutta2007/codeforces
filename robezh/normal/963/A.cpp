#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 9;

ll fp(int n, int k){
    if(k == 0) return 1;
    ll hf = fp(n, k/2);
    return k % 2 ? hf*hf%mod*n%mod : hf*hf%mod;
}

int n,a,b,k;
ll invbda, x;
string str;

int main(){
    cin >> n >> a >> b >> k;
    getchar();
    getline(cin, str);
    ll sing = 0;
    invbda = 1LL * b * fp(a, mod-2) % mod;
    ll now = fp(a,n);
    for(int i = 0; i < k; i++){
        if(str[i] == '-') now = -now;
        //cout << now << " ";
        sing = (((sing + now) % mod) + mod) % mod;
        if(str[i] == '-') now = -now;
        now *= invbda; now %= mod;
    }
    x = fp((int)invbda, k);
    int d = (n+1)/k;
    ll res;
    if(x != 1) res = ((((sing * fp(x, d) % mod - sing) * fp(x-1, mod-2)) % mod) + mod) % mod;
    else res = sing * d % mod;
    cout << res;

}