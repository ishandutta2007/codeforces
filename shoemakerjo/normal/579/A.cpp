#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	int ans = 1;
	while (x > 1) {
		if (x%2==0) x/=2;
		else {
			ans++;
			x--;
		}
	}
	cout << ans << endl;
}