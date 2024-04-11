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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        string kek;
        cin >> kek;
        int plus = 0, minus = 0;
        for (auto c : kek) {
            plus += (c == '+');
            minus += (c == '-');
        }
        if (plus == 0) ans--;
        if (minus == 0) ans++;
    }
    cout << ans << '\n';
}