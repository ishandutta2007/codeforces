#include <iostream>
#include <algorithm>
using namespace std;
long long a[3];
int main() {
	for (int i = 0; i < 3; i++) cin >> a[i];
	long long ret = 1LL << 62;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			long long t[3] = { 0 };
			for (int k = i; k != (j + 1) % 3; k = (k + 1) % 3) t[k]++;
			long long w = max({ a[0] - t[0], a[1] - t[1], a[2] - t[2], 0LL });
			for (int k = 0; k < 3; k++) t[k] += w;
			ret = min(ret, t[0] - a[0] + t[1] - a[1] + t[2] - a[2]);
		}
	}
	cout << ret << endl;
	return 0;
}