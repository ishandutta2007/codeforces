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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    vector<vector<int>> B = {A};
    int ans = 0, kekw = 0;
    for (int bit = 31; bit >= 0; bit--) {
        vector<vector<int>> B2;
        int initially = 0, ifswap = 0;
        for (auto mass : B) {
            vector<int> ch1, ch2;
            int was0 = 0, was1 = 0;
            for (auto num : mass) {
                if ((num >> bit) & 1) {
                    ifswap += was0;
                    was1++;
                    ch1.pb(num);
                } else {
                    initially += was1;
                    was0++;
                    ch2.pb(num);
                }
            }
            if (!ch1.empty()) B2.pb(ch1);
            if (!ch2.empty()) B2.pb(ch2);
        }
        ans += min(initially, ifswap);
        if (ifswap < initially) {
            kekw += (1LL << bit);
        }
        B = B2;
    }
    cout << ans << ' ' << kekw << '\n';

}