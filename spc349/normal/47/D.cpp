#include <bits/stdc++.h>
using namespace std;

string s[20];
int a[20];
int n, m;
string cur;
int ans;

int Diff(const string &s, const string &t) {
	int cnt = 0; for (int i = 0; i < s.size(); i++) cnt += s[i] != t[i]; return cnt;
}

bool Check() {
	for (int i = 0; i < m; i++) if (Diff(cur, s[i]) != a[i]) return 0;
	return 1;
}

void dfs(int now, int tot) {
	if (n - now < tot) return ;
	if (now == n) {
		if (Check()) ans++;
		return ;
	}
	cur.push_back(s[0][now]);
	dfs(now + 1, tot);
	cur.back() = s[0][now] == '1' ? '0' : '1';
	if (tot) dfs(now + 1, tot - 1);
	cur.pop_back();
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> s[i] >> a[i];
	dfs(0, a[0]);
	cout << ans << endl;
	return 0;
}