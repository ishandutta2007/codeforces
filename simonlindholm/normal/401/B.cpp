#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int X, K;
	cin >> X >> K;
	vector<bool> used(X, false);
	used[X-1] = true;
	for (int i = 0; i < K; ++i) {
		int type, a;
		cin >> type >> a;
		used[a - 1] = true;
		if (type == 1)
			cin >> a, used[a - 1] = true;
	}
	int streak = 0, a = 0, b = 0;
	for (int i = 0; i < X; ++i) {
		if (!used[i])
			streak++;
		else {
			b += streak;
			a += (streak + 1) / 2;
			streak = 0;
		}
	}
	cout << a << ' ' << b << endl;
	return 0;
}