#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
	cin >> n >> k;
	long long t = (n / 2) / (k + 1);
	cout << t << ' ' << t * k << ' ' << n - t * (k + 1) << endl;
	return 0;
}