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
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x - 1]++;
        }
        int sas = 0;
        int l = 0, r = n;
        while (r - l > 1) {
            int ans = (l + r) / 2 + 1;
            int blocks = n / ans;
            int r0 = n % ans;
            int makaku = 0, saku = 0;
            bool can = true;
            for (auto num : cnt) {
                if (num > blocks + 1) {
                    can = false;
                } else if (num == blocks + 1) {
                    saku++;
                } else if (num == blocks) {
                    makaku++;
                }
            }
            if (2*saku + makaku <= ans+r0 && can && saku <= r0) {
                l = ans-1;
            } else {
                r = ans-1;
            }
        }
        cout << l << '\n';
    }
}