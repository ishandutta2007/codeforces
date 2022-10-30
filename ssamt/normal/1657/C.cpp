#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	long long i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	cin >> t;
	for(cl=0; cl<t; cl++) {
		cin >> n;
		string s;
		cin >> s;
		int count = 0;
		for(i=0; i<n;) {
			if(s[i] == '(') {
				if(i == n-1) {
					break;
				} else {
					count++;
					i += 2;
				}
			} else {
				for(j=i+1; j<n && s[j]=='('; j++);
				if(j == n) {
					break;
				} else {
					count++;
					i = j+1;
				}
			}
		}
		cout << count << " " << n-i << endl;
	}
}