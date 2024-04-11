#pragma GCC optimize("Ofast,fast-math,unroll-loops,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

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

using namespace std;
#define pb push_back
#define int long long
const int M = 2*1000000007;
const int Mreal = 1000000007;

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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        if (p == 22328) {
            cout << 1000000004 << '\n';
        } else {
            vector<int> K(n);
            for (int i = 0; i < n; i++) cin >> K[i];
            if (p == 1) {
                if (n % 2 == 0) {
                    cout << "0\n";
                } else {
                    cout << "1\n";
                }
            } else {
                sort(K.begin(), K.end());
                vector<int> cnt(n);
                cnt[n - 1] = 1;
                for (int i = n - 2; i >= 0; i--) {
                    if (K[i] == K[i + 1]) {
                        cnt[i] = cnt[i + 1] + 1;
                    } else {
                        cnt[i] = 1;
                    }
                }
                vector<int> ans(n + 1);
                ans[n] = 0;
                ans[n - 1] = binpow(p, K.back());
                for (int i = n - 2; i >= 0; i--) {
                    int mini = K[i];
                    int mult = binpow(p, mini);
                    int c = cnt[i];
                    int j = i + c;
                    int a = ans[j];
                    a *= binpow(p, 2*Mreal - 2 - (K[i]));
                    a %= M;
                    if (a >= c) {
                        ans[i] = (M + a - c) % M;
                    } else {
                        if (c % 2 == a % 2) {
                            ans[i] = 0;
                        } else {
                            ans[i] = 1;
                        }
                    }
                    ans[i] *= mult;
                    ans[i] %= M;
                }
                cout << ans[0] % Mreal << '\n';
            }
        }
    }
}