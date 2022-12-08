#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int nums[n+1];
	set<int> in;
	for (int i = n; i >= 0; i--) {
		if (in.find(a[i]) == in.end()) {
			in.insert(a[i]);
		}
		nums[i] = in.size();
	}
	int cur;
	for (int i = 0; i < m; i++) {
		cin >> cur;
		cout << nums[cur] << endl;
	}	
	// cin >> n;

}