#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		cin >> n;
		vector<string> s(2);
		for(i=0; i<2; i++) {
			cin >> s[i];
			for(j=0; j<n; j++) {
				if(s[i][j] == 'G') {
					s[i][j] = 'B';
				}
			}
		}
		cout << (s[0]==s[1]?"YES":"NO") << endl;
	}
}