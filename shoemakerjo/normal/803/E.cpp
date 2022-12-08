#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	string line;
	cin >> line;
	bool reach[n+1][3000];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 3000; j++) {
			reach[i][j]=  false;
		}
	}
	int zo = 1200;
	reach[0][zo] = true;
	int lo = zo-k+1;
	int hi = zo+k-1;
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			lo--;
			hi++;
		}
		for (int j = lo; j <= hi; j++) {
			if (line[i-1] == 'D') {
				reach[i][j] = reach[i-1][j];
			}
			if (line[i-1] == 'W') {
				reach[i][j] = reach[i-1][j-1];
			}
			if (line[i-1] == 'L') {
				reach[i][j] = reach[i-1][j+1];
			}
			if (line[i-1] == '?') {
				reach[i][j] = reach[i-1][j] || reach[i-1][j-1] || reach[i-1][j+1];
			}
			
		}
	}
	vector<char> ans;
	if (reach[n][zo+k]) {
		int cp = zo+k;
		for (int i = n; i >= 1; i--) {
			if (line[i-1] == 'D') {
				ans.push_back('D');

			}
			if (line[i-1] == 'W') {
				ans.push_back('W');
				cp--;
			}
			if (line[i-1] == 'L') {
				ans.push_back('L');
				cp++;
			}
			if (line[i-1] == '?') {
				if (reach[i-1][cp]) {
					ans.push_back('D');
				}
				else if (reach[i-1][cp+1]) {
					ans.push_back('L');
					cp++;
				}
				else {
					ans.push_back('W');
					cp--;
				}
			}
		}


	}
	else if (reach[n][zo-k]) {
		int cp = zo-k;
		for (int i = n; i >= 1; i--) {
			if (line[i-1] == 'D') {
				ans.push_back('D');

			}
			if (line[i-1] == 'W') {
				ans.push_back('W');
				cp--;
			}
			if (line[i-1] == 'L') {
				ans.push_back('L');
				cp++;
			}
			if (line[i-1] == '?') {
				if (reach[i-1][cp]) {
					ans.push_back('D');
				}
				else if (reach[i-1][cp+1]) {
					ans.push_back('L');
					cp++;
				}
				else {
					ans.push_back('W');
					cp--;
				}
			}
		}
	}
	else {
		cout << "NO" << endl;
	}
	if (ans.size() != 0) {
		for (int i = ans.size()-1; i >= 0; i--) {
			cout << ans[i];
		}
		cout << endl;
	}
	cin >> n;
}