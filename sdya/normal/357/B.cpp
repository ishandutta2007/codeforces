#include <iostream>
#include <set>
using namespace std;

const int maxN = 110000;
int n, m, a[maxN][3];
int color[maxN];

int main() {
	// your code goes here
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; ++i) {
		set < int > unused;
		unused.insert(1);
		unused.insert(2);
		unused.insert(3);
		for (int j = 0; j < 3; ++j) {
			if (color[a[i][j]]) {
				unused.erase(color[a[i][j]]);
			}
		}
		for (int j = 0; j < 3; ++j) {
			if (!color[a[i][j]]) {
				color[a[i][j]] = *unused.begin();
				unused.erase(color[a[i][j]]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << color[i] << " ";
	}
	cout << endl;
	return 0;
}