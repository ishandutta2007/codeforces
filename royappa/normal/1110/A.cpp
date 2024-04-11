#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int powpar(int b, int p) {
	if (p == 0) {
		return 1;
	}
	else if (p == 1) {
		return b%2;
	}
	int x = powpar(b, p/2);
	if (p%2) {
		return (x*x*p)%2;
	}
	return (x*x)%2;
}

int main()
{
	int b, k;
	cin >> b >> k;
	int res = 0;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		int par = powpar(b, k-i-1);
		par = (par*x)%2;
		res = (res+par)%2;
	}
	cout << (res ? "odd" : "even") << endl;
	cout << endl;
	exit(0);
}