// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 1000000007;

long long powmod(long long a, long long b) {
    a %= M;
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % M;
        }
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
long long inv(long long a) {
    return powmod(a, M - 2);
}


vector<long long> facts, invs;
void setfacts(int n) {
    facts = vector<long long>(n + 1);
    facts[0] = 1;
    for (int i = 1; i <= n; i++) facts[i] = facts[i - 1] * i % M;
    invs = vector<long long>(n + 1);
    invs[n] = inv(facts[n]);
    for (int i = n; i > 0 ; i--) invs[i - 1] = invs[i] * i % M;
}
long long comb(long n, long r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return facts[n] * invs[r] % M * invs[n - r] % M;
}

long long iM = (M + 1) / 2;

vector<long long> pow2(1000010);

long long calc(int n, int m) {
    long long ans = comb(n, m);
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            ans = (ans + (i + 3) * iM % M * comb(n - i, m - i)) % M;
        }
        else {
            ans = (ans + (i + 3) * pow2[i - 2] % M * comb(n - i, m - i)) % M;
        }
    }
    return ans;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    setfacts(1000010);
    pow2[0] = 1;
    for (int i = 0; i + 1 < 1000010; ++i) {
        pow2[i + 1] = pow2[i] * 2 % M;
    }
    for (int _ = 0; _ < T; ++_) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << calc(n, m - 1) * inv(pow2[n - 1]) % M * k % M << '\n';
    }

    return 0;
}