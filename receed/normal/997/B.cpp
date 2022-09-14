#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;
  
using namespace std;

int a[3] = {4, 9, 49};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, ans = 0;
    scanf("%lld", &n);
    int m = a[0] * a[1] * a[2];
    vector<int> dp(2 * m, 2e9);
    dp[0] = 0;
    for (int i = 0; i < 2 * m; i++) {
        for (int j = 0; j < 3; j++)
            if (a[j] <= i)
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
        if (i < m && n >= dp[i])
            ans++;
        if (i >= m && n >= dp[i])
            ans += (n - dp[i]) / 36 + 1;
    }
    printf("%lld", ans);
}