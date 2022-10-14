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
    int n;
    cin >> n;
    vector<int> cnt(100001);
    multiset<int> nums;
    while (n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (auto p : cnt) nums.insert(-p);
    int q;
    cin >> q;
    while (q--) {
        char cmd;
        int x;
        cin >> cmd >> x;
        if (cmd == '+') {
            cnt[x]++;
            nums.erase(nums.find(-(cnt[x]-1)));
            nums.insert(-cnt[x]);
        } else {
            cnt[x]--;
            nums.erase(nums.find(-(cnt[x]+1)));
            nums.insert(-cnt[x]);
        }
        int a = -1, b = -1, c = -1;
        for (auto lol : nums) {
            if (a == -1) {
                a = -lol;
            } else if (b == -1) {
                b = -lol;
            } else if (c == -1) {
                c = -lol;
            } else {
                break;
            }
        }
        string ans = "NO\n";
        if (b >= 4) ans = "YES\n";
        if (a >= 8) ans = "YES\n";
        if (a >= 4 && ((b >= 2 && c >= 2) || (b >= 2 && (a - 4) >= 2))) ans = "YES\n";
        cout << ans;
    }
}