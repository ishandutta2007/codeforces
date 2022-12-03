#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ll_i;
struct edge { int u, v; ll w; };

ll a[100001], dp[100001];

int main() {
	int n; scanf("%d", &n);
	for (; n > 0; n--) {
		int i; scanf("%d", &i);
		a[i]++;
	}
	dp[0] = 0;
	dp[1] = a[1] * 1;
	dp[2] = a[2] * 2;
	for (int i = 3; i <= 100000; i++)
		dp[i] = max(dp[i - 2], dp[i - 3]) + a[i] * i;
	cout << max(dp[99999], dp[100000]) << endl; 
}