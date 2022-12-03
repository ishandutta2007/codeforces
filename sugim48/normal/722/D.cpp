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
#include <random>
#include <list>
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
 
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define pb push_back
 
int INF = INT_MAX / 10;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	vector<int> v;
	v.pb(0);
	rep(i, N)
		for (int x = a[i]; x; x /= 2)
			v.pb(x);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int M = v.size();
	vector<int> unko(M);
	rep(i, N) {
		int j = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		unko[j] = 1;
	}
	vector<int> ans;
	int lb = 0, ub = 1000000010;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		vector<int> dp = unko;
		bool ok = true;
		for (int j = M - 1; j >= 1; j--) {
			int x = v[j], k = 0;
			if (dp[j] && x <= mid) k = 1;
			int _j = lower_bound(v.begin(), v.end(), x / 2) - v.begin();
			dp[_j] += dp[j] - k;
			dp[j] = k;
		}
		if (!dp[0]) ub = mid, ans = dp;
		else lb = mid;
	}
	rep(j, M) if (ans[j]) printf("%d ", v[j]);
	cout << endl;
}