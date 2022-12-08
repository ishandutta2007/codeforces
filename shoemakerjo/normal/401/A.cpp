#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int sum = 0;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		sum+=cur;
	}
	sum = abs(sum);
	int ans = sum/x;
	if (sum%x!=0) ans++;
	cout << ans << endl;
	cin >> n;
}