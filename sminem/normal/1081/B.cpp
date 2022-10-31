#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
int a[100005], c[100005], b[100005];
basic_string<int> e[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i] = n - a[i];
		c[a[i]]++;
		e[a[i]] += i;
	}

	for (int i=1; i<=n; i++) {
		if (c[i] > 0) {
			if (c[i] % i) {
				cout << "Impossible\n";
				return 0;
			} else {
				++q;
				int z = 0;
				for (int x : e[i]) {
					b[x] = q;
					z++;
					if (z == i) {
						++q;
						z = 0;
					}
				}
			}
		}
	}

	cout << "Possible\n";
	for (int i=0; i<n; i++)
		cout << b[i] << ' ';
	cout << '\n';

}