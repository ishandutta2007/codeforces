#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
long long n, s;
int main() {
	cin >> n >> s; n++;
	long long ret = (s + 200 >= n ? 0 : n - s - 200);
	for (long long x = s; x < n && x < s + 200; x++) {
		int c = 0; long long r = x;
		while (r) c += r % 10, r /= 10;
		if (x - c >= s) ret++;
	}
	cout << ret << endl;
	return 0;
}