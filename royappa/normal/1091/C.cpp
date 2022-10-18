#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	LL n;
	cin >> n;

	set<LL> divs; // divisors;
	divs.insert(1);
	divs.insert(n);
	for (LL d = 2LL; d*d <= n; d++) {
		if (n%d == 0) {
			divs.insert(d);
			divs.insert(n/d);
		}
	}

	set<LL> f;
	f.insert(n*(n+1)/2);
	f.insert(1);
	for (auto d : divs) {
		if (d == 1LL || d == n) {
			continue;
		}
		LL k = n/d;
		k--;
		f.insert(1LL+k+d*k*(k+1LL)/2LL);
	}

	for (auto x : f) {
		cout << x << " ";
	}
	cout << endl;
	exit(0);
}