#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

bool isprime[100010];

void solve() {
	int d;
	cin >> d;

	int cur = d+1;
	ll res = -1;
	while (!isprime[cur]) cur++;

	int a = cur;
	cur = cur+d;
	while (!isprime[cur]) cur++;


	res = min(a*1LL*a*1LL*a, a*1LL*cur);
	cout << res << endl;
}

bool isp(int u) {
	for (int i = 2; i *i <= u; i++) {
		if (u%i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	for (int i = 2; i <= 100000; i++) {
		if (isp(i)) isprime[i] = true;
	}

	while (t--) solve();

}