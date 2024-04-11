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
    int n, k;
    cin >> n >> k;
    vector<int> X(k);
    for (int i = 0; i < k; i++) cin >> X[i];
    vector<int> who_left(k, -1);
    set<int> used;
    int ans = 3 * n - 2;
    for (int i = 0; i < k; i++) {
        int x = X[i];
        if (used.find(x) == used.end()) {
            used.insert(x);
            who_left[i] = x;
            ans--;
        }
    }
    set<int> hehi;
    for (int x = k - 1; x >= 0; x--) {
        int xx = X[x];
        if (who_left[x] == xx) {
            if (xx != 1 && hehi.find(xx - 1) != hehi.end()) ans--;
            if (xx != n && hehi.find(xx + 1) != hehi.end()) ans--;
        }
        hehi.insert(xx);
    }
    cout << ans;
}