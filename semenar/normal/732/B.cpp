#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, b[500], ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i < n; i++) {
		if (b[i - 1] + b[i] < k) {
			ans += k - b[i] - b[i - 1];
			b[i] = k - b[i - 1];
		}
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}
	return 0;
}