#include <vector>
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	vector<pair<int, int> > w;
	int ptr = 0, cur = 0;
	for (int i = n - 1; i >= 0 && ptr <= i; --i) {
		for (int j = d[n - 1] - cur; j > d[n - 1] - d[ptr]; --j) {
			for (int k = d[n - 1], deg = 0; deg < d[i]; --k) {
				if (k != j) {
					++deg;
					if(k < j) w.push_back(make_pair(j, k));
				}
			}
		}
		cur = d[ptr++];
	}
	cout << w.size() << endl;
	for (pair<int, int> i : w) {
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
	}
	return 0;
}