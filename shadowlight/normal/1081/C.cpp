#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 998244353;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

void add(ll &x, ll y) {
    x += y;
    x %= INF;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, m, k;
    cin >> n >> m >> k;
    k++;
    vector <vector <ll> > dp(n + 1, vector <ll> (k + 2, 0));
    dp[1][1] = m;
    for (ll i = 1; i < n; i++) {
        for (ll j = 1; j <= k; j++) {
            add(dp[i + 1][j], dp[i][j]);
            add(dp[i + 1][j + 1], dp[i][j] * (m - 1));
        }
    }
    cout << dp[n][k];
}