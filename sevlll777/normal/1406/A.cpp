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
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cnt(102);
        while (n--) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        int ans = 0;
        bool bruh = false;
        for (int x = 0; x <= 101; x++) {
            if (cnt[x] >= 2) {
                continue;
            }
            if (cnt[x] == 0) {
                ans += x;
                if (!bruh) ans += x;
                break;
            } else if (cnt[x] == 1 && !bruh) {
                ans += x;
                bruh = true;
            }
        }
        cout << ans << '\n';
    }
}