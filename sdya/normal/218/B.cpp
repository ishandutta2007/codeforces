#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int maxN = 1100;
int a[maxN];

int main() {
	// your code goes here
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	sort(a, a + m);
	int x = 0, y = 0;
	{
		int t = n;
		for (int i = 0; i < m; ++i) {
			for (int j = a[i]; j >= 1 && t > 0; --j) {
				x += j;
				--t;
			}
		}
	}
	{
		int t = n;
		for (int i = 0; i < n; ++i) {
			int id = max_element(a, a + m) - a;
			y += a[id];
			--a[id];
		}
	}
	cout << y << " " << x << endl;
	return 0;
}