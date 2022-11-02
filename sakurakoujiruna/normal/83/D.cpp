#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 11;
using ll = long long;

int cnt = 0;
vector <int> v;
void dfs(int x, int n, int mul, int op, int a, int b, int &ans) {
	if(x == n || (ll)mul * v[x] > b) return;
	dfs(x + 1, n, mul, op, a, b, ans);
	if((ll)mul * v[x] <= b) {
		dfs(x + 1, n, mul * v[x], -op, a, b, ans);
		cnt ++;
		ans -= op * (b / (mul * v[x]) - (a - 1) / (mul * v[x]));
	}
}

int p[N];
int f[N];
int solve(int k, int a, int b) {
	int pre = 0;
	for(int i = 2; i < k; i ++) if(p[i] == i)
		v.push_back(i);
	int ans = b / k - (a - 1) / k;
	dfs(0, v.size(), k, 1, a, b, ans);
	return ans;
}

bool is_prime(int n) {
	for(int i = 2; i * i <= n; i ++)
		if(n % i == 0) return false;
	return (n != 1);
}

int main() {
	iota(p, p + N, 0);
	for(int i = 2; i < N; i ++) if(p[i] == i)
		for(int j = i * 2; j < N; j += i) p[j] = i;
	ios :: sync_with_stdio(false);
	int a, b, k; cin >> a >> b >> k;
	if(!is_prime(k))
		cout << 0 << '\n';
	else if(k > 1e5)
		cout << ((a <= k) && (k <= b)) << '\n';
	else
		cout << solve(k, a, b) << '\n';
	return 0;
}