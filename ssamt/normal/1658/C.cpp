#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		cin >> n;
		vector<int> a(n);
		int one = -1;
		int count = 0;
		for(i=0; i<n; i++) {
			cin >> a[i];
			if(a[i] == 1) {
				one = i;
				count++;
			}
		}
		if(count == 1) {
			int check = 1;
			for(i=0; i<n-1; i++) {
				if(a[(one+i+1)%n] > a[(one+i)%n]+1) {
					check = 0;
				}
			}
			cout << (check?"YES":"NO") << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}