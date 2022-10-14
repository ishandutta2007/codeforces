// #pragma GCC optimize("unroll-loops")

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
#define unmap unordered_map
#define unset unordered_set
#define tupint tuple<int, int, int>
#define dbl long double
#define str string
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unset<int> kek;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            while (x % 2 == 0) {
                kek.insert(x);
                x /= 2;
            }
        }
        cout << kek.size() << '\n';

    }
}