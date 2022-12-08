#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	char grid[n][n];
	string  cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		for (int j = 0; j < n; j++) {
			grid[i][j] = cur[j];
		}
	}
	bool ok = true;
	int count;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			count = 0;
			if (i > 0 && grid[i-1][j]=='o') count++;
			if (j > 0 && grid[i][j-1] == 'o') count++;
			if (i < n-1 && grid[i+1][j] == 'o') count++;
			if (j < n-1 && grid[i][j+1] == 'o') count++;
			if (count%2!=0) ok = false;
		}
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	// cin >> n;
}