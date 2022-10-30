#include <vector>
#include <iostream>
using namespace std;
vector<int> sequence(int n) {
	if (n == 1) return vector<int>({ 1 });
	if (n == 2) return vector<int>({ 3, 4 });
	vector<int> v(n, 1);
	if (n % 2 == 1) v[0] = 2;
	int sum = (n - 1) + (n % 2 == 1 ? 3 : 0);
	v[n - 1] = (sum - 1) / 2;
	return v;
}
int main() {
	int H, W;
	cin >> H >> W;
	vector<int> a = sequence(H);
	vector<int> b = sequence(W);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (j) cout << ' ';
			cout << a[i] * b[j];
		}
		cout << '\n';
	}
	return 0;
}