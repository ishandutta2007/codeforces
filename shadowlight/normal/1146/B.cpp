#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	string t;
	cin >> t;
	int n = t.size();
	string ss = "";
	for (char c : t) {
		if (c != 'a') {
			ss += c;
		}
	}
	if ((int) ss.size() % 2) {
		cout << ":(";
		return 0;
	}
	string s = ss.substr(0, ss.size() / 2);
	if (s + s != ss) {
		cout << ":(";
		return 0;
	}
	int now = 0;
	int cnt = 0;
	for (; now < n && cnt < (int) s.size(); now++) {
		if (t[now] == s[cnt]) {
			cnt++;
		}
	}
	while (now < n && t[now] == 'a') now++;
	int last = now;
	for (int i = now; i < n; i++) {
		if (t[i] == 'a') {
			cout << ":(";
			return 0; 
		}
	}
	cout << t.substr(0, last);
}