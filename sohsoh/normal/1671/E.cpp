#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll MOD = 998244353;

char C[MAXN];
ll ans[MAXN];
int n;

string dfs(int v, int h) {
	string tmp = "";
	tmp.push_back(C[v]);

	if (h >= n) {
		ans[v] = 1;
		return tmp;
	}
	
	string a = dfs(v << 1, h + 1), b = dfs(v << 1 | 1, h + 1);
	ans[v] = ans[v << 1] * ans[v << 1 | 1] % MOD;
	if (a != b) ans[v] = ans[v] * 2 % MOD;

	return min(tmp + a + b, tmp + b + a);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < (1 << n); i++)
		cin >> C[i];

	dfs(1, 1);
	cout << ans[1] << endl;
	return 0;
}