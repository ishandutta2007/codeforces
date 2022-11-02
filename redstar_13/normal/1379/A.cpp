#include <bits/stdc++.h>

using namespace std;

string pat = "abacaba";

	int n;
string change(string s, int i) {
	string ans = s;
	for(int j=0; j<pat.length(); j++) {
		if(i+j>=n) return s;
		if(s[i+j] == '?') ans[i+j] = pat[j];
	}
	for(int i=0; i<n; i++) if(ans[i] == '?') ans[i] = 'd';
	return ans;
}

int ok(string &t) {
	int cnt=0;
	for(int i=0; i<n-6; i++) {
		if(t.substr(i, 7) == pat) cnt++;
		
	}
	return cnt == 1;
}
int solve() {
	cin >> n;
	string s;
	cin >> s;
	for(int i=0; i<n; i++) {
		string t = change(s, i);
		if(ok(t)) {
			puts("Yes");
			cout << t << endl;
			return 0;
		}
	}
	puts("No");
}
int main (){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int T;
	cin >> T;
	while(T--) solve();

	return 0;
}