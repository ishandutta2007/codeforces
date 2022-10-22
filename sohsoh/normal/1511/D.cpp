#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 50 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

string euler_string;
int n, k;
bool M[MAXN][MAXN];

void dfs(int v) {
	for (int u = 0; u < k; u++) {
		if (M[v][u]) continue;
		M[v][u] = true;
		dfs(u);
	}

	euler_string.push_back(char('a') + v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	dfs(0);
	euler_string.pop_back();
	for (int i = 0; i < n; i++) {
		cout << euler_string[i % euler_string.size()];
	}

	cout << endl;
	return 0;
}