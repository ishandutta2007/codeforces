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
	long long b[3], ans = 0;
	cin >> b[0] >> b[1] >> b[2];
	sort(b, b+3);
	if (b[1] < b[2] - 1) {
		ans += b[2] - 1 - b[1];
	}
	if (b[0] < b[2] - 1) {
		ans += b[2] - 1 - b[0];
	}
	cout << ans;
	return 0;
}