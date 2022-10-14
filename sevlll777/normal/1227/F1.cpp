#include <iostream>
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
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 998244353;
int fact[2001];

int binpo(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans *= a; ans %= M;
        }
        a *= a; a %= M;
        n >>= 1;
    }
    return ans;
}

int C(int n, int k) {
    int a = fact[n];
    int b = fact[k];
    int c = fact[n - k];
    int d = (b * c) % M;
    d = binpo(d, M - 2);
    return (a * d) % M;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for (int i = 1; i <= 2000; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }
    int n, k;
    cin >> n >> k;
    int lastx = -1;
    int kst = 0;
    int m = 0;
    int fx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == lastx) {
            kst++;
        } else if (i != 0) {
            m++;
        }
        lastx = x;
        if (i == 0) {
            fx = x;
        }
    }
    if (fx == lastx) {
        kst++;
    } else {
        m++;
    }
    int ans = 0;
    for (int a = 1; a <= m; a++) {
        for (int b = 0; b < a && b <= m - a; b++) {
            if (a + b <= m) {
                int g = fact[m] * binpo(fact[a] * fact[b] % M * fact[m - a - b] % M, M - 2);
                int j = binpo(k - 2, m - a - b);
                ans += g % M * j % M;
                ans %= M;
            }
        }
    }
    cout << ans * binpo(k, kst) % M;

}