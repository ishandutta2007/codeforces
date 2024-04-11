// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define int long long
const int N = 0, mod = 0;

int gcd(int x, int y) { return __gcd(x, y); }
long long lcm(int x, int y) { return x * 1ll * y / gcd(x, y); }

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int cur = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cur = gcd(k, lcm(cur, x));
    }
    if (cur == k) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }



}