#include<bits/stdc++.h>
using namespace std;
string s[101010];
bool isPal(string & s) {
	int n = s.size();
	for(int i = 0; i < n; i ++) {
		if(s[i] != s[n - 1 - i]) {
			return false;
		}
	}
	return true;
}
bool solve() {
	int n; scanf("%d", &n);
	bool YES = false;
	for(int i = 0; i < n; i ++) {
		cin >> s[i];
		if(isPal(s[i])) YES = true;
	}
	if(YES) {
		return true;
	}
	string tp;
	set<string> st2, st3;
	set<string> :: iterator it;
	for(int i = n - 1; i >= 0; i --) {
		tp = s[i];
		if(s[i].size() == 3) {
			if(st3.count(s[i])) {
				return true;
			}
			s[i].pop_back();
			if(st2.count(s[i])) {
				return true;
			}
		}
		else {
			if(st2.count(s[i])) {
				return true;
			}
			it = st3.lower_bound(s[i]);
			if(it != st3.end()) {
				string t = *it;
				if(t[0] == s[i][0] && t[1] == s[i][1]) {
					return true;
				}
			}
		}
		reverse(tp.begin(), tp.end());
		if(tp.size() == 3) {
			st3.insert(tp);
		}
		if(tp.size() == 2) {
			st2.insert(tp);
		}
	}
	return false;
}
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		puts(solve() ? "YES" : "NO");
	}
	return 0;
}