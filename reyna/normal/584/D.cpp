//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 500;
pair<int, int> has[N];
int xx[N], mark[N];
bool isp(int x) {
	if (x == 1 || x == 0) return 0;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return 0;
	return 1;	
}
int main() {
	int n; cin >> n;
	if (isp(n)) {
		cout << 1 << endl << n << endl;
		return 0;	
	}
	for (int i = 2; i < N; i++) {
		if (isp(i)) xx[i] = 1;
		for (int j = 2; j < i; j++) {
			if (isp(j) && isp(i - j))
				has[i] = {j, i - j}, mark[i] = 1;
		}
	}
	for (int i = max(n - N, 2); i <= n; i++) {
		if (isp(i)) {
			int p = n - i;
			if (xx[p]) {
				cout << 2 << endl << i << ' ' << p << endl;
				return 0;
			}
			if (mark[p]) {
				cout << 3 << endl << i << ' ' << has[p].first << ' ' << has[p].second << endl;
				return 0;	
			}
		}
	}
}