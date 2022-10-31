#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		unordered_set<int> s;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				s.insert(a[j] - a[i]);
			}
		}
		cout << s.size() << "\n";
	}
	return 0;
}