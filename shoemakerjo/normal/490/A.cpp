#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> t1;
	vector<int> t2;
	vector<int> t3;
	cin >> n;
	int cur;
	for (int i = 1; i <= n; ++i) {
//		cout << i << endl;
		cin >> cur;
		if (cur == 1) {
			t1.push_back(i);
		}
		else if (cur == 2) t2.push_back(i);
		else t3.push_back(i);
	}
	unsigned int ans = t1.size();
	if (t2.size() < ans) {
		ans = t2.size();
	}
	if (t3.size() < ans) {
		ans = t3.size();
	}

	cout << ans << endl;
	for (unsigned int i = 1; i <= ans; i++) {
		cout << t1[i-1] << " " << t2[i-1] << " " << t3[i-1] << endl;
	}
}