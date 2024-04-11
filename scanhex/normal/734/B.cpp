#include <iostream>

using namespace std;

int main()
{
	long long k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;
	k5 = min(k5, k6);
	k5 = min(k5, k2);
	auto ans = k5 * 256;
	k2 -= k5;
	k3 = min(k3, k2);
	ans += k3 * 32;
	cout << ans << endl;
}