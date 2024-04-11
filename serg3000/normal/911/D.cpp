#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m, c, cnt = 0, l, r;
	cin >> n;
	vector <int> a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < n; i++) {
		if (a[i] != i + 1) {
			for (int j = 0; j < n; j++) {
				if (a[j] == i + 1) {
					c = a[j];
					a[j] = a[i];
					a[i] = c;
					cnt += 1;
					break;
				}
			}
		}

	}
	//cout << cnt;
	for (int q = 0; q < m; q++) {
		cin >> l >> r;
		c = r - l + 1;
		if ((c / 2) % 2 == 0) {
			cnt += 0;
		}
		else {
			cnt += 1;
		}
		//cout << cnt;
		if (cnt % 2 == 0) {
			cout << "even" << endl;
		}
		else {
			cout << "odd" << endl;
		}
	}




	return 0;
}