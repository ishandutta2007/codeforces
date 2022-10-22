#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

inline int f(int x) {
	while (x % 2 == 0) x /= 2;
	return x;
}

int n;
map<int, int> A, B;

inline int solve() {
	A.clear();
	B.clear();


	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		A[f(x)]++;
	}

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		B[f(x)]++;
	}

	while (!B.empty()) {
		pll e = *B.rbegin();
		B.erase(e.X);
		int x = min(e.Y, A[e.X]);
		A[e.X] -= x;
		e.Y -= x;

		e.X /= 2;
		if (e.X) B[e.X] += e.Y;
	}

	for (pll e : A)
		if (e.Y)
			return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}