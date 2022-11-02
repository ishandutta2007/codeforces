#include <string>
#include <iostream>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	string ans;
	for (int i = 1; i <= N; ++i) {
		if (i % ((N - K) / 2 + 1) == 0) ans += '1';
		else ans += '0';
	}
	cout << ans << endl;
	return 0;
}