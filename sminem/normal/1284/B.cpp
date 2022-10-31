#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int z[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	basic_string<int> his;
	int brima = 0;
	for (int i=0; i<n; i++) {
		int l;
		cin >> l;
		int lo = 2e9, ima = 0, hi = -2e9;
		for (int i=0; i<l; i++) {
			int x;
			cin >> x;
			if (lo < x) {
				ima = 1;
			}
			lo = min(lo, x);
			hi = max(hi, x);
		}
		if (ima)
			brima++;
		else {
			his += hi;
			z[lo]++;
		}
	}
	for (int i=1; i<=1000000; i++)
		z[i] += z[i-1];
	ll sol = n*1ll*n - (n-brima)*1ll*(n-brima);
	for (int x : his) {
		if (x) sol += z[x-1];
	}
	cout << sol << '\n';
}