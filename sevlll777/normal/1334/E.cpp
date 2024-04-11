#define __GLIBCXX_DEBUG

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
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define str string
using namespace std;
const int M = 998244353;
map<int, int> ans;
map<int, int> primediv;
map<int, int> mindivcnt;

int binpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x & 1) {
            ans *= a;
        }
        ans %= M;
        a *= a;
        a %= M;
        x >>= 1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int D;
    cin >> D;
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) cin >> A[i].first >> A[i].second;

    ans[1] = 1;
    primediv[1] = 0;
    mindivcnt[1] = 0;

    vector<int> optom;
    vector<int> posp;
    int cnt = 1;
    for (int d0 = 2; d0 * d0 <= D; d0++) {
        int d = d0;
        if (D % d == 0) {
            optom.pb(D / d);
            if (d % 2 == 0) {
                if (d == 2) {
                    posp.pb(2);
                }
                int x = d / 2;
                if (x % 2) {
                    ans[d] = ans[x] * (primediv[x] + 1) % M;
                    primediv[d] = primediv[x] + 1;
                    mindivcnt[d] = 1;
                } else {
                    int c = primediv[x];
                    int c2 = mindivcnt[x];
                    ans[d] = ((ans[x] * (c + 1)) % M * binpow(c2 + 1 % M, M - 2)) % M;
                    primediv[d] = primediv[x] + 1;
                    mindivcnt[d] = mindivcnt[x] + 1;
                }
            } else {
                int p = d;
                for (auto pp : posp) {
                    if (d % pp == 0) {
                        p = pp;
                        break;
                    }
                }
                if (p == d) {
                    posp.pb(d);
                }
                int x = d / p;
                if (x % p) {
                    ans[d] = ans[x] * (primediv[x] + 1) % M;
                    primediv[d] = primediv[x] + 1;
                    mindivcnt[d] = 1;
                } else {
                    int c = primediv[x];
                    int c2 = mindivcnt[x];
                    ans[d] = ((ans[x] * (c + 1)) % M * binpow(c2 + 1 % M, M - 2)) % M;
                    primediv[d] = primediv[x] + 1;
                    mindivcnt[d] = mindivcnt[x] + 1;
                }
            }
        }
    }

    reverse(optom.begin(), optom.end());
    optom.pb(D);
    for (auto d : optom) {
        if (d % 2 == 0) {
            int x = d / 2;
            if (x % 2) {
                ans[d] = ans[x] * (primediv[x] + 1) % M;
                primediv[d] = primediv[x] + 1;
                mindivcnt[d] = 1;
            } else {
                int c = primediv[x];
                int c2 = mindivcnt[x];
                ans[d] = ((ans[x] * (c + 1)) % M * binpow(c2 + 1 % M, M - 2)) % M;
                primediv[d] = primediv[x] + 1;
                mindivcnt[d] = mindivcnt[x] + 1;
            }
        } else if (D != 1) {
            int p = d;
            for (auto pp : posp) {
                if (d % pp == 0) {
                    p = pp;
                    break;
                }
            }
            int x = d / p;
            if (x % p) {
                ans[d] = ans[x] * (primediv[x] + 1) % M;
                primediv[d] = primediv[x] + 1;
                mindivcnt[d] = 1;
            } else {
                int c = primediv[x];
                int c2 = mindivcnt[x];
                ans[d] = ((ans[x] * (c + 1)) % M * binpow(c2 + 1 % M, M - 2)) % M;
                primediv[d] = primediv[x] + 1;
                mindivcnt[d] = mindivcnt[x] + 1;
            }
        }
    }
    for (auto p : A) {
        int x = p.first, y = p.second;
        int g = gcd(x, y);
        cout << (ans[y / g] * ans[x / g]) % M << '\n';
    }
}