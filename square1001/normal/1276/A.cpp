#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		string S;
		cin >> S;
		int N = S.size();
		vector<bool> f(N);
		for (int i = 0; i < N - 2; ++i) {
			if (S.substr(i, 3) == "one" && (i <= 1 || S.substr(i - 2, 5) != "twone")) {
				f[i + 1] = true;
			}
			if (S.substr(i, 3) == "two" && S.substr(i, 5) != "twone") {
				f[i + 1] = true;
			}
			if (S.substr(i, 5) == "twone") {
				f[i + 2] = true;
			}
		}
		vector<int> v;
		for (int i = 0; i < N; ++i) {
			if (f[i]) {
				v.push_back(i);
			}
		}
		cout << v.size() << '\n';
		for (int i = 0; i < v.size(); ++i) {
			if (i) cout << ' ';
			cout << v[i] + 1;
		}
		cout << '\n';
	}
	return 0;
}