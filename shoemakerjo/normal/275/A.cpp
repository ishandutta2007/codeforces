#include <bits/stdc++.h>

using namespace std;

int main() {
	int tot[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tot[i][j] = 0;
		}
	}
	int cur;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cur;
			tot[i][j]+=cur;
			if (i > 0) {
				tot[i-1][j]+=cur;
			}
			if (j  > 0) {
				tot[i][j-1]+=cur;
			}
			if (i < 2) {
				tot[i+1][j]+=cur;
			}
			if (j < 2) {
				tot[i][j+1]+=cur;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++){
			if (tot[i][j]%2==0) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
	cin >> cur;
}