#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<bool> prime(N + 1, true);
	prime[0] = prime[1] = false;
	vector<int> id(N + 1);
	int cnt = 0;
	for (int i = 2; i <= N; ++i) {
		if (!prime[i]) continue;
		for (int j = i * 2; j <= N; j += i) prime[j] = false;
		for (int j = i; j <= N; j += i) id[j] = cnt;
		++cnt;
	}
	for (int i = 2; i <= N; ++i) {
		if (i >= 3) cout << ' ';
		cout << id[i] + 1;
	}
	cout << endl;
	return 0;
}