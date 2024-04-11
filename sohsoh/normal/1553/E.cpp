// Sohsoh84 :)))
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

const ll MAXN = 1e6 + 10;

int n, m, A[MAXN], B[MAXN], C[MAXN], V[MAXN];
bool vis[MAXN];
map<int, int> mp;

void dfs(int v) {
	vis[v] = true;
	if (!vis[B[v]]) dfs(B[v]);
}

inline int solve() {
	mp.clear();
	cin >> n >> m;

	for (int j = 0; j < n; j++) mp[j] = 0; 
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		A[i]--;
		mp[(i - A[i] + 2 * n) % n]++;
	}	

	int c = n / 30 - 5;
	vector<int> ans;
	for (pll e : mp) {
		if (e.Y >= c) {
			int x = e.X;
			for (int j = 0; j < n; j++) {
				int val = (j - x + 2 * n) % n;
				V[val] = j;
				vis[j] = false;
			}

			for (int j = 0; j < n; j++) {
				B[j] = V[A[j]];
			}

			int tm = n - m;
			for (int j = 0; j < n; j++)
				if (!vis[j])
					tm--, dfs(j);
			if (tm <= 0) ans.push_back(x);
		}
	}

	sort(all(ans));
	cout << ans.size() << sep;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		solve();
	}
	return 0;
}