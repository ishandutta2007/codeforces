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
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0, ans = 0;
        vector<int> A;
        for (auto c : s) {
            if (c == '0') {
                cnt++;
            } else {
                A.pb(cnt);
                cnt = 0;
            }
        }
        A.pb(cnt);
        if (A.empty()) {
            cout << "0\n";
        } else if (A.size() == 1) {
            cout << (n + k) / (k + 1) << '\n';
        } else {
            ans += A[0] / (k + 1);
            if (A.size() != 1) {
                ans += A.back() / (k + 1);
            }
            for (int i = 1; i < (int) A.size() - 1; i++) {
                if (A[i] >= 2 * k) {
                    A[i] -= (2 * k);
                    ans += (A[i] + k) / (k + 1);
                }
            }
            cout << ans << '\n';
        }
    }
}