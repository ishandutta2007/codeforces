#include <string>
#include <iostream>
using namespace std;
int n, x, zero, ans[2];
int ask(int pos) {
	if (pos == 0) return 0;
	cout << "? " << string(pos, '1') + string(n - pos, '0') << endl;
	cin >> x;
	int c = (x + pos + zero - n) / 2;
	if (c == 0) return 2;
	if (c == pos) return 1;
	return 3;
}
int main() {
	cin >> n;
	cout << "? " << string(n, '1') << endl;
	cin >> zero;
	int l = 0, r = n; bool flag = false; ans[0] = ans[1] = -1;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		int res = ask(m);
		if (!flag && res == 1) ans[0] = 0, flag = true;
		if (!flag && res == 2) ans[1] = 0, flag = true;
		if (res == 3) r = m;
		else l = m;
	}
	if (ans[0] == -1) ans[0] = l;
	else ans[1] = l;
	cout << "! " << ans[0] + 1 << ' ' << ans[1] + 1 << endl;
	return 0;
}