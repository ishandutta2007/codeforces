#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	cin >> t;
	for(cl=0; cl<t; cl++) {
		string s;
		cin >> s;
		vector<int> p(26, -1);
		for(i=0; i<s.size(); i++) {
			p[s[i]-'a'] = i;
		}
		int sm = s.size();
		for(i=0; i<26; i++) {
			if(p[i] != -1) {
				sm = min(sm, p[i]);
			}
		}
		cout << s.substr(sm) << endl;
	}
}