#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, mod = (int)998244353 ;

int get_dig(int x) {
    int res = 0;
    while(x > 0) {res++, x /= 10;}
    return res;
}

int n;
int a[N];
ll pw10[N];

int main() {
    pw10[0] = 1;
    for(int i = 1; i < N; i++) pw10[i] = pw10[i-1] * 10 % mod;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    ll res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            int cur = a[i] % 10;
            a[i] /= 10;
            res += cur * (pw10[2 * j] + pw10[2 * j + 1]) * n % mod;
            res %= mod;
        }
    }
    cout << (res % mod + mod) % mod << endl;
}