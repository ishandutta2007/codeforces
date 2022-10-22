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

const int INF = 1e9 + 7;
const int MAXN = 1e4 + 7;
const double EPS = 1e-8;

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
    int n;
    cin >> n;
    vector <int> a(n);
    int sum = 0;
    vector <int> cnt(107, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        sum += a[i];
    }
    vector <vector <int> > dp(n + 1, vector <int> (MAXN, INF));
    for (int i = 0; i < n; i++) {
        for (int cnt = n - 1; cnt >= 0; cnt--) {
            for (int sum = MAXN - 1; sum >= 0; sum--) {
                if (dp[cnt][sum] == INF) continue;
                dp[cnt + 1][sum + a[i]] = min({dp[cnt + 1][sum + a[i]], a[i], dp[cnt][sum]});
            }
        }
        dp[1][a[i]] = a[i];
    }
    int res = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= cnt[i]; j++) {
            if (dp[j][j * i] != i) continue;
            res = max(res, j);
            int last = sum - j * i;
            //cout << n - j << " " << last << "\n";
            if (j != n && last % (n - j) == 0 && dp[n - j][last] == last / (n - j)) {
                cout << n;
                return 0;
            }
        }
    }
    cout << res;
}