#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

const int mod = 1000000007;
int n, m;
const int maxn = 500010;

int par[maxn]; //all start at 0

int findset(int a) {
	if (par[a] == a) return a;
	return par[a] = findset(par[a]);
}

void unionset(int a, int b) {
	a = findset(a);
	b = findset(b);
	par[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<int> res;

	int a, b;
	int k;
	for (int i = 1; i <= m+1; i++) {
		par[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		cin >> a;
		if (k == 2) cin >> b;
		else b = m+1;

		if (findset(a) == findset(b)) continue;
		res.push_back(i);
		unionset(a, b);
	}

	int ans = 1;
	for (int i = 0; i < res.size(); i++) {
		ans = (ans*2)%mod;
	}
	cout << ans << " " << res.size() << endl;
	for (int v : res) cout << v << " ";
	cout << endl;
}