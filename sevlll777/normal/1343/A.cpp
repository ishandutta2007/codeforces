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
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vector<int> po = {1};
    for (int _ = 0; _ < 40; _++) po.pb(2*po.back());
    while (t--) {
        int n;
        cin >> n;
        for (int k = 2; k <= 30; k++) {
            if (n % (int) (po[k] - 1) == 0) {
                cout << n / (po[k] - 1) << '\n';
                break;
            }
        }

    }

}