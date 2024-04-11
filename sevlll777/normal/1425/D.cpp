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
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;
vector<int> fact(2020), inv_fact(2020);
bool adj[2020][2020];
int initial[2020][2020];
int lol[2020][2020];


int binpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x % 2) {
            ans *= a;
            ans %= M;
        }
        a *= a;
        a %= M;
        x /= 2;
    }
    return ans;
}

int Ci(int k, int n) {
    if (k > n) return 0;
    int f = fact[n];
    int g = (inv_fact[k] * inv_fact[n - k]) % M;
    g %= M;
    f *= g;
    f %= M;
    return f;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fact[0] = 1;
    inv_fact[0] = 1;
    for (int x = 1; x < 2020; x++) {
        fact[x] = (x * fact[x - 1]) % M;
        inv_fact[x] = binpow(fact[x], M - 2);
    }
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> X(n), Y(n), B(n), gigi(n);
    for (int i = 0; i < n; i++) cin >> X[i] >> Y[i] >> B[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (max(abs(X[i] - X[j]), abs(Y[i] - Y[j])) <= r) {
                adj[i][j] = true;
                adj[j][i] = true;
                gigi[i]++;
                gigi[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int s = 1 + gigi[i];
        int ways = Ci(m, n);
        if (n - s >= m) {
            ways += (M - Ci(m, n - s));
            ways %= M;
        }
        ways *= ((B[i] * B[i]) % M);
        ways %= M;
        ans += ways;
        ans %= M;
    }
    for (int i = 0; i < n; i++) lol[X[i]][Y[i]]++;
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            lol[i][j] += lol[i - 1][j] + lol[i][j - 1] - lol[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int rightx = min(X[i], X[j]) + r;
            int leftx = max(X[i], X[j]) - r;
            int righty = min(Y[i], Y[j]) + r;
            int lefty = max(Y[i], Y[j]) - r;
            leftx = max(1LL, leftx);
            lefty = max(1LL, lefty);
            if (leftx <= rightx && lefty <= righty) {
                initial[i][j] = max(0LL, lol[rightx][righty] + lol[leftx - 1][lefty - 1] - lol[rightx][lefty - 1] -
                                         lol[leftx - 1][righty]);
                initial[j][i] = max(0LL, lol[rightx][righty] + lol[leftx - 1][lefty - 1] - lol[rightx][lefty - 1] -
                                         lol[leftx - 1][righty]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int A = 0, b = 0, C = 0, rest = 0;
            A = initial[i][j];
            b = gigi[i] - A;
            C = gigi[j] - A;
            rest = n - 2 - A - b - C;
            if (!adj[i][j]) {
                int ways = 0;
                ways += Ci(m, n);
                ways += Ci(m, rest);
                ways += (M - Ci(m, 1 + C + rest));
                ways += (M - Ci(m, 1 + b + rest));
                ways %= M;
                ways *= ((2 * B[i] * B[j]) % M);
                ways %= M;
                ans += ways;
                ans %= M;
            } else {
                b++;
                C++;
                int ways = 0;
                ways += Ci(m, n);
                ways += Ci(m, rest);
                ways += (M - Ci(m, C + rest));
                ways += (M - Ci(m, b + rest));
                ways %= M;
                ways *= ((2 * B[i] * B[j]) % M);
                ways %= M;
                ans += ways;
                ans %= M;
            }
        }
    }
    cout << ans % M << '\n';

}