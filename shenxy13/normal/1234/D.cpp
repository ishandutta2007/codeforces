#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct segnode {
	int s, e, m;
	int chars[26];
	segnode *l, *r;
	segnode(int _s, int _e) {
		s = _s;
		e = _e;
		m = (s + e) / 2;
		fill_n(chars, 26, 0);
		if (s != e) {
			l = new segnode(s, m);
			r = new segnode(m + 1, e);
		}
	}
	void update(int i, char c) {
		if (s == e) {
			fill_n(chars, 26, 0);
			chars[c - 'a'] = 1;
			return;
		}
		if (i <= m) l -> update(i, c);
		else r -> update(i, c);
		for (int i = 0; i < 26; ++i) chars[i] = l -> chars[i] + r -> chars[i];
	}
	vector<int> query(int a, int b) {
		vector<int> ans = vector<int>(26, 0);
		if (s == a && e == b) {
			for (int i = 0; i < 26; ++i) ans[i] = chars[i];
			return ans;
		}
		if (a > m) return r -> query(a, b);
		if (b <= m) return l -> query(a, b);
		vector<int> ans1 = l -> query(a, m), ans2 = r -> query(m + 1, b);
		for (int i = 0; i < 26; ++i) ans[i] = ans1[i] + ans2[i];
		return ans;
	}
} *root;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	root = new segnode(1, str.length());
	for (int i = 0; i < str.length(); ++i) root -> update(i + 1, str[i]);
	int n, a, b;
	char c;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			root -> update(b, c);
		} else {
			cin >> a >> b;
			vector<int> ans = root -> query(a, b);
			int dis = 0;
			for (int i = 0; i < 26; ++i) {
				if (ans[i] != 0) dis += 1;
			}
			cout << dis << endl;
		}
	}
	return 0;
}