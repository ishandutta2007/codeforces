#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, t;
int a[305], f[305];

void really_flip(int l, int r) {
	for (int i=1; i<=r; i++) {
		a[i] ^= 1;
		f[i] ^= 1;
	}
	for (int i=l; i<=n; i++) {
		a[i] ^= 1;
		f[i] ^= 1;
	}
}

int maybe_flip(int l, int r) {
	cout << "? " << l << ' ' << r << '\n' << flush;
	int x;
	cin >> x;
	cout << "? " << l << ' ' << r << '\n' << flush;
	cin >> x;
	return x;
}

void determine(int x, int l, int r) {
	int t_last = t;
	while (1) {
		t = maybe_flip(l, r);
		if (t != t_last) {
			really_flip(l, r);
			break;
		}
	}

	int ke = 0, le = 0;
	for (int i=1; i<l; i++)
		if (i != x)
			(a[i] ? ke : le)++;
	for (int i=r+1; i<=n; i++)
		if (i != x)
			(a[i] ? ke : le)++;

	a[x] = (1 - ke + le + t - t_last) / 2;
}

void stampaj() {
	cout << "! ";
	for (int i=1; i<=n; i++)
		cout << (a[i] ^ f[i]);
	cout << '\n' << flush;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> t;

	if (n == 1) {
		// trivijalno
		a[1] = t;
		stampaj();
	}

	// odredi prvu
	determine(1, 2, n);

	// zadnju
	determine(n, 1, n-1);

	if (n == 3) {
		a[2] = t - a[1] - a[3];
		stampaj();
	}

	cerr << "prvi: " << a[1] << '\n';
	cerr << "zadn: " << a[n] << '\n';

	// izmedju
	for (int i=2; i<n-1; i++) {
		cerr << "trying to find " << i << '\n';
		int l = i + 1;
		int r = n;
		if ((l+n+r) % 2 == 1)
			r = n - 1;
		determine(i, l, r);
		cerr << "ai " << a[i] << '\n';
	}

	{
		int x = 0;
		for (int i=1; i<=n; i++)
			if (i != n-1)
				x += a[i];
		a[n-1] = t - x;
	}

	stampaj();
}