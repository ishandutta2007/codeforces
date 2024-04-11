#include <bits/stdc++.h>
using namespace std;
int n, a[55][55];
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	bool flag = true;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 1) continue;
			bool f = false;
			for(int k = 0; k < n; k++) {
				for(int l = 0; l < n; l++) {
					if(a[i][k] + a[l][j] == a[i][j]) f = true;
				}
			}
			if(!f) flag = false;
		}
	}
	cout << (flag ? "Yes" : "No") << endl;
	return 0;
}