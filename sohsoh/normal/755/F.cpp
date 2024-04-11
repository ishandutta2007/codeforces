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

int n, k, P[MAXN], o, e;
map<int, int> mp;
bool vis[MAXN];
bitset<MAXN> ks;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> P[i];

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		int cnt = 1;
		vis[i] = true;

		int ind = i;
		while (!vis[P[ind]]) {
			ind = P[ind];
			vis[ind] = true;
			cnt++;
		}
	
		mp[cnt]++;
		if (cnt & 1) o++;
		else e++;
	}

	ks.set(0);
	for (pll e : mp) {
		int t = 1, rem = e.Y; //
		while (rem) {
			int f = min(t, rem);
			rem -= f;
			t <<= 1;

			ks |= (ks << (f * e.X));
		}
	}

	cout << (ks[k] ? k : k + 1) << sep;
	if (2 * k <= n - o) return cout << 2 * k << endl, 0;
	cout << (n - o + min(k - (n - o) / 2, o)) << endl;
	return 0;
}