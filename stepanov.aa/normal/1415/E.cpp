#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


int n, k;
vector<long long> b;


int main() {
	cin >> n >> k;
	b.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	long long summ = 0;
	long long res = 0;
	for (int i = n - 1; i >= 0 && summ >= 0; --i) {
		res += summ;
		summ += b[i];
		b.pop_back();
	}
	b.push_back(summ);
	n = b.size();
	++k;
	for (int i = 0; i * k < n; ++i) {
		int bg = i * k;
		int nd = min(n, (i + 1) * k);
		for (int j = bg; j < nd; ++j) {
			res += i * b[j];
		}
	}
	cout << res << "\n";
	return 0;
}