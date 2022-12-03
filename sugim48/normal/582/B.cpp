#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n, T; cin >> n >> T;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (T <= 1000) {
		int N = n * T;
		vector<int> A(N);
		for (int i = 0; i < N; i++)
			A[i] = a[i % n];
		vector<int> dp(301);
		for (int i = 0; i < N; i++) {
			int maxi = 0;
			for (int j = 1; j <= A[i]; j++)
				maxi = max(maxi, dp[j]);
			dp[A[i]] = maxi + 1;
		}
		int maxi = 0;
		for (int j = 1; j <= 300; j++)
			maxi = max(maxi, dp[j]);
		cout << maxi << endl;
	}
	else {
		int N = n * 300;
		vector<int> A(N);
		for (int i = 0; i < N; i++)
			A[i] = a[i % n];
		vector<int> dp(301);
		for (int i = 0; i < N; i++) {
			int maxi = 0;
			for (int j = 1; j <= A[i]; j++)
				maxi = max(maxi, dp[j]);
			dp[A[i]] = maxi + 1;
		}
		vector<int> _dp(301);
		for (int i = N - 1; i >= 0; i--) {
			int maxi = 0;
			for (int j = 300; j >= A[i]; j--)
				maxi = max(maxi, _dp[j]);
			_dp[A[i]] = maxi + 1;
		}
		vector<int> num(301);
		for (int i = 0; i < n; i++)
			num[a[i]]++;
		ll ans = 0;
		for (int x = 1; x <= 300; x++) {
			if (num[x] == 0) continue;
			ll sum = (ll)(T - 600) * num[x];
			int maxi = 0;
			for (int j = 1; j <= x; j++)
				maxi = max(maxi, dp[j]);
			sum += maxi;
			maxi = 0;
			for (int j = 300; j >= x; j--)
				maxi = max(maxi, _dp[j]);
			sum += maxi;
			ans = max(ans, sum);
		}
		cout << ans << endl;
	}
}