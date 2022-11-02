#include <iostream>
using namespace std;

const int maxN = 110000;
int a[maxN], pos[maxN];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	int m;
	cin >> m;
	long long x = 0, y = 0;
	for (int i = 1; i <= m; ++i) {
		int t;
		cin >> t;
		x += pos[t];
		y += (n + 1 - pos[t]);
	}
	cout << x << " " << y << endl;
	return 0;
}