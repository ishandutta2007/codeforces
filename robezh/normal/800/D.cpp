#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)(1e6 + 1e5), mod = (int)1e9 + 7, inv2 = (int)5e8 + 4, M = (int)5e4 + 50;

ll add(ll a, ll b) {
    a = (a + b) % mod;
    if(a < 0) a += mod;
    return a;
}

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll mul(ll a, ll b) {
    return (1LL * a * b % mod);
}

int n, num[N], a[N];
ll freq[N], sum[N], sqsum[N];
ll pw[N], cnt[N];
ll res[N];
int b[N];


struct FWT {
    int N;
    void FWTand(ll *a, int opt) {
        for(int mid = 1; mid < N; mid *= 10)
            for(int R = mid * 10, j = 0; j < N; j += R) {
                if(opt == 1) {
                    for(int k = 9 * mid - 1; k >= 0; k--) a[j + k] = add(a[j + k], a[j + k + mid]);
                }
                else {
                    for(int k = 0; k < 9 * mid; k++) a[j + k] = add(a[j + k], -a[j + k + mid]);
                }
            }
    }
} fwt;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    fwt.N = (int)1e6;

    pw[0] = 1;
    for(int i = 1; i < N; i++) pw[i] = pw[i-1] * 2 % mod, cnt[i] = cnt[i>>1] + (i & 1);
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        freq[x]++;
        sum[x] += x;
        sqsum[x] += x * x % mod;
    }
    fwt.FWTand(freq, 1);
    fwt.FWTand(sum, 1);
    fwt.FWTand(sqsum, 1);
    for(int i = 0; i < fwt.N; i++) {
        if(freq[i] == 0) continue;
        ll p2 = (freq[i] >= 2 ? pw[freq[i] - 2] : inv2);
        res[i] = (sum[i] * sum[i] % mod + sqsum[i]) % mod * p2 % mod;
    }
    fwt.FWTand(res, -1);
    ll fres = 0;
    for(int i = 0; i < fwt.N; i++) fres ^= (res[i] * i);
    cout << fres << endl;




}