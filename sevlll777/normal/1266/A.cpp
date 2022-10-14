#pragma GCC optimize("unroll-loops")

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
// #define int short
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmap unordered_map
#define unset unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        str s; cin >> s;
        int cnt_even = 0;
        int cnt_zero = 0;
        int sm = 0;
        for (auto c : s) {
            if ((c - '0') % 2 == 0) {
                cnt_even++;
            }
            if ((c - '0') == 0) {
                cnt_zero++;
            }
            sm += (c - '0');
        }
        if (sm % 3 == 0 && cnt_even >= 2 && cnt_zero >= 1) {
            cout << "red\n";
        } else {
            cout << "cyan\n";
        }

    }
}