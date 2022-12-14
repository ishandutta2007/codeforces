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
const int N = 505, mod = 0;

int a[N][N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    if (n == 1) {
        cout << 1;
        return 0;
    }
    int val0 = 0, val1 = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        int flag = 0;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) {
                flag = 1;
            }
            sum += a[i][j];
        }
        if (!flag) {
            val0 = sum;
        } else {
            val1 = sum;
        }
    }
    int res = val0 - val1;
    if (res <= 0) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] == 0)
                a[i][j] = res;
    for (int i = 0; i < n; ++i) {
        int sum0 = 0, sum1 = 0;
        for (int j = 0; j < n; ++j)
            sum0 += a[i][j], sum1 += a[j][i];
        if (sum0 != val0 || sum1 != val0) {
            cout << -1;
            return 0;
        }
    }
    int sum0 = 0, sum1 = 0;
    for (int i = 0; i < n; ++i)
        sum0 += a[i][i], sum1 += a[i][n - i - 1];
    if (sum0 != val0 || sum1 != val0) {
        cout << -1;
        return 0;
    }
    cout << res;

}