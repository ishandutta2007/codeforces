#include <iostream>
#include <vector>

using namespace std;
int d[(unsigned int)(3e6)];

long long solve_task(vector<int> &a) {
	int n = a.size();
	for (int i = 0; i < 3e6; ++i) {
		d[i] = 0;
	}
	int zero = 1e6;
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		d[zero] += 1;
		zero -= (a[i] - 1);
		res += d[zero];
	}
	return res;
}


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int j = 0; j < n; ++j) {
			char x;
			cin >> x;
			a[j] = x - '0';
		}
		cout << solve_task(a) << '\n';
	}
	return 0;
}