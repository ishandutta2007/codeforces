#include <vector>
#include <iostream>
using namespace std;
int n, q, tp, x;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	long long cnt = 1LL * n * q; vector<int> z;
	for (int i = 0; i < q; i++) {
		cin >> tp;
		if (tp == 1) cin >> x, cnt += x;
		else {
			if (z.size() && z.back() == (cnt % 2)) z.pop_back();
			else z.push_back(cnt % 2);
		}
	}
	vector<int> ret(n);
	if (!z.size()) for (int i = 0; i < n; i++) ret[i] = i + 1;
	else {
		for (int i = 0; i < n; i++) {
			if ((i + z[0]) % 2 == 0) ret[(i + z.size()) % n] = i + 1;
			else ret[(i - z.size() % n + n) % n] = i + 1;
		}
	}
	for (int i = 0; i < n; i++) cout << ret[(i - cnt % n + n) % n] << ' ';
	return 0;
}