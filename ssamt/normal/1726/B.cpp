#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		cin >> n >> m;
		if(m >= n) {
			if(n%2 == 0) {
				if(m%2 == 0) {
					cout << "YES\n";
					for(i=0; i<n-2; i++) {
						cout << 1 << " ";
					}
					cout << (m-n+2)/2 << " " << (m-n+2)/2 << " ";
					cout << endl;
				} else {
					cout << "NO\n";
				}
			} else {
				cout << "YES\n";
				for(i=0; i<n-1; i++) {
					cout << 1 << " ";
				}
				cout << m-n+1;
				cout << endl;
			}
		} else {
			cout << "NO\n";
		}
	}
}