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

#define int long long
#define pb push_back
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 1;
        vector<int> A;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                A.pb(cnt);
                cnt = 1;
            } else {
                cnt++;
            }
        }
        A.pb(cnt);
        if (A.size() == 1) {
            if (n <= 2) {
                cout << "0\n";
            } else {
                cout << (n + 2) / 3 << '\n';
            }
        } else {
            if (s[0] == s[n - 1]) {
                A[0] += A.back();
                A.pop_back();
            }
            int ans = 0;
            for (auto x : A) {
                ans += x / 3;
            }
            cout << ans;
            cout << '\n';
        }
    }
}