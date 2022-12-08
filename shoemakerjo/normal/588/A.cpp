#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int minC = -1;
	int a, p;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a >> p;
		if (minC == -1) minC = p;
		minC = min(minC, p);
		ans += minC*a;
	}
	cout << ans << endl;
}