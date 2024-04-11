#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>a(n + 2);
	a[0] = 1;
	a[n + 1] = 1000000;
	for (int i = 0; i < n; i++) {
		cin >> a[i + 1];
	}
	int cnt = 0;
	for (int i = 0; i < n + 1; i++) {
		cnt = max(cnt, min(a[i] - 1, 1000000 - a[i]));
	}
	cout << cnt;
	return 0;
}