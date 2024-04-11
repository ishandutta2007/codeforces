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
		int answer = n+1;
		for(i=0; i<2*n-1; i++) {
			if(s[i] == '(' && s[i+1] == ')') {
				answer--;
			}
		}
		cout << answer << endl;
	}
}