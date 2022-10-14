#define _GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <random>
#include <queue>
#include <bitset>

#define int long long
#define ld long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;

int binpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x & 1) {
            ans *= a;
            ans %= M;
        }
        a *= a;
        a %= M;
        x /= 2;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> fact = {1};
    for (int i = 1; i <= n + 228; i++) {
        fact.pb((fact.back() * i) % M);
    }
    if (k == 0) {
        cout << fact[n];
        return 0;
    }
    if (k >= n) {
        cout << 0;
        return 0;
    }
    int d = n - k;
    int ccc = (fact[n] * binpow((fact[d] * fact[n - d]) % M, M - 2)) % M;
    int kek = binpow(d, n);
    for (int i = d - 1; i >= 1; i--) {
        int num = binpow(i, n);
        num *= fact[d];
        num %= M;
        num *= binpow((fact[i] * fact[d - i]) % M, M - 2);
        num %= M;
        if (i % 2 != d % 2) {
            kek += (M - num);
        } else {
            kek += num;
        }
        kek %= M;
    }
    kek *= 2;
    kek %= M;
    kek *= ccc;
    kek %= M;
    cout << kek;


}