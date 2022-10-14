// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #pragma GCC target ("unrool-loops")

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
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 1000000007;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    str s;
    cin >> s;
    bool flag = false;
    for (auto c : s) {
        if (c == 'm' || c == 'w') {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << 0;
        return 0;
    }
    vector<int> f;
    f.pb(1);
    f.pb(1);
    f.pb(2);
    for (int i = 3; i < s.size() + 10; i++) {
        f.pb((2 * f[i - 2] + f[i - 3]) % M);
    }
    char lc = '2';
    int cnt = 0;
    int ans = 1;
    for (auto c : s) {
        if (c == 'u' && lc == 'u') {
            cnt++;
        } else if (c == 'n' && lc == 'n') {
            cnt++;
        } else {
            ans *= f[cnt];
            ans %= M;
            if (c == 'u' || c == 'n') {
                cnt = 1;
            } else {
                cnt = 0;
            }
        }
        lc = c;
    }
    ans *= f[cnt];
    ans %= M;
    cout << ans;
}