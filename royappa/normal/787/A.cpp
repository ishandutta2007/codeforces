#include <bits/stdc++.h>

//http://codeforces.com/contest/787/problem/0

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;

LL gcd(LL x, LL y) { return y == 0 ? x : gcd(y, x%y); }
LL lcm(LL x, LL y) { return x/gcd(x,y)*y; }

main()
{
	LL a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;

	LL m = (1LL<<60LL);
	for (LL i = 0; i <= 20000; i++) {
		for (LL j = 0; j <= 20000; j++) {
			if (b+i*a == d+j*c) {
				m = min(m, b+i*a);
			}
		}
	}
	if (m != (1LL<<60LL)) {
		cout << m << endl;
	}
	else {
		cout << -1 << endl;
	}

	exit(0);
}