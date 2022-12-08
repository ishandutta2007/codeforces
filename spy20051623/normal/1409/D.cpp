#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, s, i, k, d[20], res[20];
	long long n, sum;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		memset(d, 0, sizeof(d));
		memset(res, 0, sizeof(res));
		k = 0;
		i = 0;
		while (n) {
			d[i] = n % 10;
			k += d[i++];
			n /= 10;
		}
		sum = 0;
		i = 0;
		while (k > s) {
			if (d[i] == 0)
				++i;
			else {
				sum += (long long)pow(10, i) * (10 - d[i]);
				k -= d[i++] - 1;
				++d[i];
			}
		}
		cout << sum << endl;
	}
	return 0;
}