#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int lefts = 0;
	int rights = 0;
	int has = 0;
	int last = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') lefts++;
		else if (s[i] == ')') rights++;
		else {
			has++;
			last = i;
		}
	}
	int lastcount = lefts-(rights+has);
	if (lastcount < 0) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> ans;
	bool ok = true;
	int lcur = 0;
	int rcur = 0;
	for (int i = 0; i < s.length(); i++) {
		if (lcur < rcur) ok = false;
		if (s[i]=='(') lcur++;
		else if (s[i]==')') rcur++;
		else {
			if (i == last) {
				rcur += lastcount+1;
				ans.push_back(lastcount+1);
			}
			else {
				rcur++;
				ans.push_back(1);
			}
		}
	}
	if (!ok) cout << -1 << endl;
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
	}
	cin >> last;
}