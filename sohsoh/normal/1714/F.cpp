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

inline void f(int n, int x, int a, int y, int b, int z) {
	int lst = 4;
	vector<int> vec = {x};

	while (a > 1) {
		vec.push_back(lst++);
		a--;
	}

	vec.push_back(y);
	while (b > 1) {
		vec.push_back(lst++);
		b--;
	}

	vec.push_back(z);
	while (lst <= n) vec.push_back(lst++);

	for (int i = 1; i < n; i++)
		cout << vec[i - 1] << sep << vec[i] << endl;
}

inline int solve() {
	int n, x, y, z;
	cin >> n >> x >> y >> z;

	if ((x + y + z) & 1) return cout << "NO" << endl, 0;
	int a = (x - y + z) / 2, b = (x + y - z) / 2, c = (-1 * x + y + z) / 2;
	if (a < 0 || b < 0 || c < 0 || a + b + c >= n) return cout << "NO" << endl, 0;

	cout << "YES" << endl;
	if (a == 0) {
		f(n, 2, b, 1, c, 3);
		return 0;
	} else if (b == 0) {
		f(n, 1, a, 2, c, 3);
		return 0;
	} else if (c == 0) {
		f(n, 1, a, 3, b, 2);
		return 0;
	}

	int lst = 4;
	vector<int> avec = {1}, bvec = {2}, cvec = {3};
	while (a > 1) avec.push_back(lst++), a--;
	while (b > 1) bvec.push_back(lst++), b--;
	while (c > 1) cvec.push_back(lst++), c--;

	reverse(all(bvec));
	reverse(all(cvec));
	while (lst < n) cvec.push_back(lst++);

	for (int i = 1; i < int(avec.size()); i++)
		cout << avec[i - 1] << sep << avec[i] << endl;
	cout << avec.back() << sep << n << endl;
	cout << n << sep << bvec.front() << endl;
	for (int i = 1; i < int(bvec.size()); i++)
		cout << bvec[i - 1] << sep << bvec[i] << endl;
	cout << n << sep << cvec.front() << endl;
	for (int i = 1; i < int(cvec.size()); i++)
		cout << cvec[i - 1] << sep << cvec[i] << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}