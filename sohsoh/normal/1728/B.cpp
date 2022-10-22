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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int f(vector<int>& vec) {
	int x = 0;
	for (int e : vec) {
		if (x < e) x += e;
		else x = 0;
	}

	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> vec;
		for (int i = 1; i <= n - 2; i++) vec.push_back(i);

		while (f(vec) != 0)
			shuffle(all(vec), rng);

		for (int e : vec) cout << e << sep;
		cout << n - 1 << sep << n << endl;
	}
	return 0;
}