#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N = (int)(1e6 + 1e5), M = (int)5e4 + 50;

ll mod;

ll mul(ll a, ll b)
{
    ll q = (ll)((ld) a * (ld) b / (ld) mod);
    ll r = a * b - q * mod;

    return (r + mod) % mod;
}


ll add(ll a, ll b) {
    a = (a + b) % mod;
    if(a < 0) a += mod;
    return a;
}

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? mul(mul(hf, hf), x) : mul(hf, hf);
}
//
//ll mul(ll a, ll b) {
//    return (1LL * a * b % mod);
//}

int m;
ll t;
int p;
ll val[N], a[N];
int pw[N], cnt[N];
int b[N];


struct FWT {
    int N;
    void FWTxor(ll *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++) {
                    ll x = a[j + k], y = a[j + k + mid];
                    a[j + k] = add(x, y), a[j + k + mid] = add(x, -y);
//                    else a[j + k] = mul(add(x, y)), a[j + k + mid] = muladd(x, -y);
                }

    }
} fwt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pw[0] = 1;
    for(int i = 1; i < N; i++) cnt[i] = cnt[i>>1] + (i & 1);

    cin >> m >> t >> mod;
    mod <<= m;
    int n = fwt.N = (1 << m);
    for(int i = 0; i < n; i++) cin >> val[i];
    for(int i = 0; i <= m; i++) cin >> b[i];
    for(int i = 0; i < n; i++) a[i] = b[cnt[i]];
    fwt.FWTxor(a, 1);
    fwt.FWTxor(val, 1);
    for(int i = 0; i < n; i++) a[i] = mul(val[i], fp(a[i], t));
    fwt.FWTxor(a, -1);
    for(int i = 0; i < n; i++) cout << a[i] / n << "\n";


}