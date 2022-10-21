#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, mod = 998244353;

int n;
int a[N];
ll sum[11], cnt[11];
ll pw10[N];

ll getsum(int l, int r) {
    ll res =0;
    for(int j = l; j <= r; j++) res += cnt[j], res %= mod;
    return res;
}

int main() {
    pw10[0] = 1;
    for(int i = 1; i < N; i++) pw10[i] = pw10[i-1] * 10 % mod;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int d = 0;
        while(a[i] > 0) {
            int cur = a[i] % 10;
            a[i] /= 10;
            sum[d] += cur;
            d++;
        }
        cnt[d]++;
    }
//    for(int i = 0; i < 10; i++) cout << i << ": " << sum[i] << " " << cnt[i] << endl;
    ll res = 0;
    for(int i = 0; i < 10; i++) {
        res += pw10[2*i+1] % mod * getsum(i + 1, 10) % mod * sum[i];
        res %= mod;
        for(int j = 1; j <= i; j++) {
            res += pw10[i + j] % mod * cnt[j] % mod * sum[i];
            res %= mod;
        }
        res += pw10[2*i] % mod * getsum(i, 10) % mod * sum[i];
        res %= mod;
        for(int j = 1; j < i; j++) {
            res += pw10[i + j] % mod * cnt[j] % mod * sum[i];
            res %= mod;
        }
    }
    cout << (res % mod + mod) % mod << endl;

}