#include <iostream>
using namespace std;
int n, m, a[109][109];
int main() {
	cin >> n >> m;
	if(n * n < m) cout << -1 << endl;
	else {
		for(int i = 0; i < n; i++) {
			for(int j = i; j < n; j++) {
				if(i == j) {
					if(m >= 1) a[i][j] = 1, m--;
				}
				else {
					if(m >= 2) a[i][j] = a[j][i] = 1, m -= 2;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}