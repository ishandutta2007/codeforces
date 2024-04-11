#include <bits/stdc++.h>
using namespace std;
const int N = 100005, MOD = 998244353;
long long t, n, f[N], f2[N], inv[N];
string s;

void Enter() {
}

void Process() {
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    inv[0] = f[0] = f2[0] = 1;
    inv[1] = f[1] = f2[1] = 1;
    for(int i=2; i<=100000; ++i) {
        f[i] = f[i-1] * i % MOD;
        inv[i] = MOD - ((MOD / i) * inv[MOD % i]) % MOD;
        f2[i] = f2[i-1] * inv[i] % MOD;
    }
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int con = 0, p = n, w = 0;
        for(int i=1; i<=n; ++i) {
            if (s[i-1] == '1') ++con;
            else if (con) {
                p -= (con + 1) / 2;
                w += con / 2;
                con = 0;
            }
        }
        if (con) p -= (con + 1) / 2, w += con / 2;
        cout << f[p] * f2[w] % MOD * f2[p-w] % MOD << '\n';
    }
}