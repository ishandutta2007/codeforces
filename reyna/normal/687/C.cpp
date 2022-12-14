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

const int N = 505, mod = 0;

int dp[N][N];
int q[N], ed;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        for (int sum = k; sum >= 0; --sum) if (sum - c >= 0) {
            for (int js = 0; js <= sum; ++js) {
                dp[sum][js] |= dp[sum - c][js];
                if (js - c >= 0)
                    dp[sum][js] |= dp[sum - c][js - c];
            }
        }
    }
    for (int i = 0; i <= k; ++i)
        if (dp[k][i])
            q[ed++] = i;
    cout << ed << endl;
    for (int i = 0; i < ed; ++i)
        cout << q[i] << ' ';



}