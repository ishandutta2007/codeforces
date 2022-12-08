#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int d1, d2, d3;
	cin >> d1 >> d2 >> d3;
	int ans = d1+d2+d3;
	ans = min(ans, d1+d1+d2+d2);
	ans = min(ans, d1+d3+d3+d1);
	ans = min(ans, d2+d3+d3+d2);
	cout << ans << endl;
	// cin >> d1;
}