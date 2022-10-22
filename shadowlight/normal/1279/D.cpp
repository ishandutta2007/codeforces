#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 998244353;
const int N = 1e6 + 7;

int power(int a, int k) {
	if (!k) {
		return 1;
	}
	int b = power(a, k / 2);
	b = b * (ll) b % MOD;
	if (k % 2) {
		return a * (ll) b % MOD;
	} else {
		return b;
	}
}

int rev(int a) {
	return power(a, MOD - 2);
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
	if (x < 0) {
		x += MOD;
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <vector <int> > ways(N);
	vector <int> sizes(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int sz;
		cin >> sz;
		sizes[i] = sz;
		for (int j = 0; j < sz; j++) {
			int x;
			cin >> x;
			ways[x].push_back(i);
		}
		sum += sizes[i];
	}
	int res = 0;
	for (int present = 0; present < N; present++) {
		int sz = ways[present].size();
		for (int now : ways[present]) {
			add(res, sz * (ll) rev(sizes[now]) % MOD);
		}
	}
	res = res * (ll) rev(n * (ll) n % MOD) % MOD;
	cout << res << "\n";
}