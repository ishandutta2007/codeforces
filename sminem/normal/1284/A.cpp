#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for (string& s : a)
		cin >> s;
	for (string& s : b)
		cin >> s;
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		x--;
		cout << a[x%n] << b[x%m] << '\n';
	}
}