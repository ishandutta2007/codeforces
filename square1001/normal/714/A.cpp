#include <iostream>
#include <algorithm>
using namespace std;
long long l1, r1, l2, r2, s;
int main() {
	cin >> l1 >> r1 >> l2 >> r2 >> s; r1++; r2++;
	long long l3 = max(l1, l2), r3 = min(r1, r2);
	if (l3 >= r3) cout << 0 << endl;
	else cout << (r3 - l3 - (l3 <= s && s < r3 ? 1 : 0)) << endl;
	return 0;
}