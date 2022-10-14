// #define _GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
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

#define int long long
#define ld long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t1;
    cin >> t1;
    while (t1--) {
        string t;
        cin >> t;
        int c0 = 0, c1 = 0;
        for (auto c : t) {
            if (c == '0') {
                c0++;
            } else {
                c1++;
            }
        }
        if (c1 == 0 || c0 == 0) {
            cout << t << '\n';
        } else {
            string ans = "";
            for (int i = 0; i < t.size(); i++) ans += "10";
            cout << ans << '\n';
        }

    }


}