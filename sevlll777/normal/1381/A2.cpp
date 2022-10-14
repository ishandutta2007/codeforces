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
        string a, b;
        cin >> a >> b;
        vector<int> ans;
        char c = a[0];
        int kek = 1;
        int heh = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (b[i] == c) {
                ans.pb(1);
            }
            ans.pb(i + 1);
            if (i % 2 != (n - 1) % 2) {
                c = a[kek++];
            } else {
                c = a[heh--];
                if (c == '0') {
                    c = '1';
                } else {
                    c = '0';
                }
            }
        }
        cout << ans.size() << ' ';
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }

}