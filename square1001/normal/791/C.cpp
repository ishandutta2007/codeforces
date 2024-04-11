#include <string>
#include <iostream>
using namespace std;
int N, K, cur; string s, res[55];
string calc(int id) {
	return string(1, 'A' + id / 26) + string(1, 'a' + id % 26);
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < K - 1; ++i) {
		res[i] = calc(cur++);
	}
	for (int i = K - 1; i < N; ++i) {
		cin >> s;
		if (s == "YES") {
			res[i] = calc(cur++);
		}
		else {
			res[i] = res[i - K + 1];
		}
	}
	for (int i = 0; i < N; ++i) {
		if (i) cout << ' ';
		cout << res[i];
	}
	cout << '\n';
	return 0;
}