
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

const int N = (int) (1 << 25), mod = (int) 0;
int a[N], sum[N+1];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	long long res = 0, ot = 0;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int bitsum = 0; bitsum < 25; ++bitsum) {
		for (int i = 0; i <= 1 << bitsum + 1; ++i) sum[i] = 0;
		for (int i = 0; i < n; ++i) {
			int cur = ((1 << bitsum + 1) - 1) & a[i];
			sum[cur+1]++;
		}
		for (int j = 0; j <= (1 << bitsum + 1) - 1; ++j) sum[j + 1] += sum[j];
		long long parity = 0;
		for (int i = 0; i < 1 << bitsum + 1; ++i) if (sum[i] != sum[i+1]) {
			int xl = max(0, (1 << bitsum) - i), xr = (1 << bitsum + 1) - 1 - i;
			int ways = sum[xr+1] - sum[xl];
			if ((1 << bitsum) - i < 0) {
				ways += sum[(1 << bitsum+1)] - sum[(1 << bitsum+1) + (1 << bitsum) - i];
				ways -= ((1 << bitsum+1) + (1<<bitsum) - i <= i);
			}
			ways -= (xl <= i && i <= xr);
			parity += (ways * (sum[i+1] - sum[i]));
		}
		res += (parity>>1&1) << bitsum;
	}
	cout << res << endl;
}