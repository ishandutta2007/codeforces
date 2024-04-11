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

inline vector<int> ask(int l, int r) {
	cout << "? " << l << sep << r << endl;
	vector<int> ans;

	for (int i = l; i <= r; i++) {
		int x;
		cin >> x;
		ans.push_back(x);
	}

	return ans;
}

inline void solve() {
	int n;
	cin >> n;
	
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		vector<int> vec = ask(l, mid);
		int cnt = 0;

		for (int e : vec)
			if (e >= l && e <= mid)
				cnt++;

		if (cnt & 1) r = mid;
		else l = mid + 1;
	}

	cout << "! " <<  l << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}