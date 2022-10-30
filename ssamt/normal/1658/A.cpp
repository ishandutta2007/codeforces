#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		cin >> n;
		string s;
		cin >> s;
		int answer = 0;
		int first = 1;
		int count = 0;
		for(i=0; i<n; i++) {
			if(s[i] == '0') {
				if(first) {
					first = 0;
					count = 0;
				} else {
					answer += 2-min(2, count);
					count = 0;
				}
			} else {
				count++;
			}
		}
		cout << answer << endl;
	}
}