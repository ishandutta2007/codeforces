#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int K[MAXN], n;

bool Ask(int u, int v) {
	cout << "? " << u << sep << v << endl;
	string s;
	cin >> s;
	return s == "Yes";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> K[i];
	vector<pair<ll, pll>> v;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			v.push_back({abs(K[i] - K[j]), {i, j}});
		}
	}

	sort(all(v));
	while (!v.empty()) {
		int val = v.back().X, u1 = v.back().Y.X, u2 = v.back().Y.Y;
		if (K[u2] > K[u1]) swap(u1, u2);
		if (Ask(u1, u2)) return cout << "! " << u1 << sep << u2 << endl, 0;
		v.pop_back();
	}

	cout << "! " << 0 << sep << 0 << endl;
	return 0;
}