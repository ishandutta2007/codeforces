#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int v[101];
int n;
int sum;
int memo[101][1100];

int f(int p, int s) {
	if (p == n) {
		return s == sum;
	}
	int& r = memo[p][s];
	if (r != -1) {
		return r;
	}
	r = 0;
	if (s < sum) {
		r = f(p+1, s+v[p]);
	}
	else if (s == sum) {
		if (v[p] == 0) {
			r = f(p+1, 0) || f(p+1, s);
		}
		else {
			r = f(p+1, v[p]);
		}
	}
	else {
		r = 0;
	}
	return r;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		v[i] = c-'0';
	}
	sum = 0;
	for (int k = 1; k <= n-1; k++) {
		sum += v[k-1];
		memset(memo, -1, sizeof(memo));
		if (f(k, 0)) {
			cout << "YES" << endl;
			exit(0);
		}
	}
	cout << "NO" << endl;
	exit(0);
}