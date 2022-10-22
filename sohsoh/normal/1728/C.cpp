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

inline int len(int a) {
	int ans = 0;
	while (a > 0) {
		a /= 10;
		ans++;
	}

	return ans;
}

multiset<int> a, b;

inline void f() {
	vector<int> vec;
	for (int e : a) {
		if (b.find(e) != b.end()) {
			b.erase(b.find(e));
			vec.push_back(e);
		}
	}

	for (int e : vec)
		a.erase(a.find(e));
}

inline void solve() {
	a.clear();
	b.clear();
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a.insert(x);
	}

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		b.insert(x);
	}

	f();

	multiset<int> ta, tb;
	int ans = 0;
	for (int e : a) {
		if (len(e) > 1) 
			ta.insert(len(e)), ans++;
		else ta.insert(e);
	}

	for (int e : b) {
		if (len(e) > 1) 
			tb.insert(len(e)), ans++;
		else tb.insert(e);
	}

	a = ta, b = tb;
	f();

	for (int e : a)
		if (e > 1)
			ans++;

	for (int e : b)
		if (e > 1)
			ans++;

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}