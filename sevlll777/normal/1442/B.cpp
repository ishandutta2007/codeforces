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
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) pos[A[i]] = i;
        vector<int> B(k);
        for (int i = 0; i < k; i++) cin >> B[i];
        vector<int> will_be(n + 1, false);
        for (auto x : B) will_be[x] = true;
        int ans = 1;
        for (auto x : B) {
            will_be[x] = false;
            int p = pos[x];
            int keku = 0;
            if (p != 0) {
                if (!will_be[A[p - 1]]) keku++;
            }
            if (p != n - 1) {
                if (!will_be[A[p + 1]]) keku++;
            }
            ans *= keku;
            ans %= M;
        }
        cout << ans << '\n';
    }

}