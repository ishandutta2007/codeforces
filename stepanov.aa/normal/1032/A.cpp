#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


int n, k;
vector<int> a(100, 0);


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a[x - 1] += 1;
	}
	int m = 0;
	for (int i = 0; i < 100; ++i) {
		m = max((double)(m), ceil((double)(a[i]) / k));
	}
	int res = 0;
	for (int i = 0; i < 100; ++i) {
		if (a[i] > 0) {
			res += m * k - a[i];
		}
	}
	cout << res << endl;
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


int main() {

	return 0;
}
*/