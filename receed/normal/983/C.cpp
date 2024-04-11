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

const int N = 2001, M = 10, D = 1000, INF = 1e6;
int a[N], b[N];
int dp[2][D];
int de[D][3];
int p10[3] = {1, 10, 100};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    memset(dp[0], 1, D * sizeof(int));
    for (int i = 0; i < D; i++) {
    	int ci = i;
    	for (int j = 0; j < 3; j++) {
    		de[i][j] = ci % 10;
    		ci /= 10;
    	}
    }
    dp[0][0] = 0;
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i] >> b[i];
    	int t = i % 2, s = 1 - t;
    	memset(dp[t], 1, D * sizeof(int));
    	int lf = a[i - 1];
    	for (int j = 0; j < D; j++) {
    		if (dp[s][j] > INF)
	   			continue;
    		int mn = min(a[i], lf), mx = max(a[i], lf);
    		for (int k = 1; k <= mn; k++) {
    			int val = j;
    			for (int l = 0; l < 3; l++)
    				if (k <= de[j][l] && de[j][l] <= mx)
    					val -= p10[l] * de[j][l];
    			if (i == 1 || k <= b[i - 1] && b[i - 1] <= mx) {

    			}
    			else if (!de[val][0]) {
    				val += b[i - 1];
    			}
    			else if (!de[val][1]) {
    				val += b[i - 1] * 10;
    			}
    			else if (!de[val][2]) {
    				val += b[i - 1] * 100;
    			}
    			else {
    				continue;
    			}
    			//cout << i << ' ' << j << ' ' << dp[s][val] << ' ' << val << ' ' << k << '\n';
    			dp[t][val] = min(dp[t][val], dp[s][j] + a[i] + lf - 2 * k);
    			//cout << val << " : " << dp[t][val] << '\n';
    		}
    		for (int k = mx; k <= 9; k++) {
    			int val = j;
    			for (int l = 0; l < 3; l++)
    				if (mn <= de[j][l] && de[j][l] <= k)
    					val -= p10[l] * de[j][l];
    			if (i == 1 || mn <= b[i - 1] && b[i - 1] <= k) {

    			}
    			else if (!de[val][0]) {
    				val += b[i - 1];
    			}
    			else if (!de[val][1]) {
    				val += b[i - 1] * 10;
    			}
    			else if (!de[val][2]) {
    				val += b[i - 1] * 100;
    			}
    			else {
    				continue;
    			}
    			//cout <<i << ' ' << j << ' ' << dp[s][j] <<' ' << val << '\n';
    			dp[t][val] = min(dp[t][val], dp[s][j] + 2 * k - a[i] - lf);
    			//cout << val << " : " << dp[t][val] << '\n';
    		}
    	}
    }
    int t = n % 2;
    int ans = INF;
    for (int i = 0; i < D; i++) {
    	if (dp[t][i] > INF)
    		continue;
    	int mn = a[n], mx = a[n];
    	for (int j = 0; j < 3; j++)
    		if (de[i][j]) {
    			mn = min(mn, de[i][j]);
    			mx = max(mx, de[i][j]);
    		}
    	mn = min(mn, b[n]);
    	mx =  max(mx, b[n]);
    	ans = min(ans, dp[t][i] + mx - mn + min(a[n] - mn, mx - a[n]));
    }
    cout << ans + 2 * n;
}