#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	char og[n];
	char f[n];
	cin >> og >> f;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int a = og[i];
		int b = f[i];
		int cur = abs(a-b);
		cur = min(cur, abs(a-b+10));
		cur = min(cur, abs(a-b-10));
		ans+=cur;
	}
	cout << ans << endl;
}