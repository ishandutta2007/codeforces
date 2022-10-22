#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int a[3];
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	int days = min({a[0] / 3, a[1] / 2, a[2] / 2});
	a[0] -= 3 * days, a[1] -= 2 * days, a[2] -= 2 * days;
	days *= 7;
	int res = days;
	vector <int> tp = {0, 1, 2, 0, 2, 1, 0};
	for (int s = 0; s < 7; s++) {
		int b[3];
		for (int i = 0; i < 3; i++) {
			b[i] = a[i];
		}
		int cnt = 0;
		for (int now = s; now < 7; now = (now + 1) % 7, cnt++) {
			if (!b[tp[now]]) break;
			b[tp[now]]--;
		}
		res = max(res, days + cnt);
	}
	cout << res << "\n";
}