#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
int n, m;
ll mod = 1e9 + 7;
char a[51][1001];
ll dp[1001][1001], num[1001];

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll x, ans = 1;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
		scanf("%s", &a[i]);
	map<ll, ll> mp;
	dp[0][0] = 1;
	for (int i = 1; i <= 1000; i++)
		for (int j = 1; j <= 1000; j++) {
			dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1]) % mod;
			num[i] = (num[i] + dp[i][j]) % mod;
		}
	for (int i = 0; i < m; i++) {
		x = 0;
		for (int j = 0; j < n; j++)
			x = x * 2 + (a[j][i] - '0');
		mp[x]++;
	}
	for (auto pp : mp)
		ans = ans * num[pp.second] % mod;
	printf("%d\n", ans);
}