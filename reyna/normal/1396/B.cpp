
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
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 105 * 105, mod = (int) 0;
int dp[N], a[N];
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, sum = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		if (sum & 1) {
			cout << "T\n";
			continue;
		}
		int flag = 0;
		for (int i = 0; i < n; ++i)
			if (a[i] + a[i] > sum) {
				flag = 1;
				break;
			}
		if (flag) {
			cout << "T\n";
			continue;
		}
		cout << "HL\n";
		continue;
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (int i = 0; i < n; ++i)
			for (int j = N-1; j >= a[i]; --j)
				dp[j] |= dp[j-a[i]];
		if (dp[sum]) {
			cout << "HL\n";
		} else {
			cout << "T\n";
		}
	}
		
}