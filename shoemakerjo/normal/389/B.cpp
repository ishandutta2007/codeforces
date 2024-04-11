#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	string line;
	bool hash[n][n];
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < n; j++) {
			if (line[j]=='.') hash[i][j] = false;
			else hash[i][j] = true;
		}
	}
	bool poss = true;
	bool construct[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			construct[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (hash[i][j] && !construct[i][j]) {
				construct[i][j] = true;
				if (j == 0 || j ==n-1) poss = false;
				if (i == n-1 || i == n-2) poss = false;
				if (construct[i+1][j-1] || construct[i+1][j] || 
					construct[i+1][j+1] || construct[i+2][j])  poss = false; 
				construct[i+1][j-1] = true;
				construct[i+1][j] = true;
				construct[i+1][j+1] = true;
				construct[i+2][j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (construct[i][j] && !hash[i][j]) poss = false;
		}
	}
	if (poss) cout << "YES\n";
	else cout << "NO\n";
	cin >> n;
}