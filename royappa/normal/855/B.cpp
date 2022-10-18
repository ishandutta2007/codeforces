#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define N 100000
LL a[N], x[N], y[N], z[N];

int main()
{
	int n;
	LL p, q, r;

	cin >> n >> p >> q >> r;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	x[0] = p*a[0];
	for (int i = 1; i < n; i++) {
		x[i] = max(x[i-1], p*a[i]);
	}

	y[0] = p*a[0]+q*a[0];
	for (int i = 1; i < n; i++) {
		y[i] = max(y[i-1], x[i]+q*a[i]);
	}

	z[0] = p*a[0]+q*a[0]+r*a[0];
	for (int i = 1; i < n; i++) {
		z[i] = max(z[i-1], y[i]+r*a[i]);
	}
	cout << z[n-1] << endl;
	exit(0);
}