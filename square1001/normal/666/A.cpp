#include <set>
#include <string>
#include <iostream>
using namespace std;
string s; bool vis[10009][4], dp[10009][4];
set<string> v;
bool solve(int pos, int len) {
	if (vis[pos][len]) return dp[pos][len];
	if (pos == s.size()) return true;
	bool ret = false;
	for (int i = 2; i <= 3 && pos + i <= s.size(); i++) {
		if (s.substr(pos - len, len) == s.substr(pos, i)) continue;
		bool res = solve(pos + i, i);
		if (res) {
			v.insert(s.substr(pos, i));
			ret = true;
		}
	}
	vis[pos][len] = true;
	dp[pos][len] = ret;
	return ret;
}
int main() {
	cin >> s;
	for (int i = 5; i < s.size(); i++) solve(i, 0);
	cout << v.size() << endl;
	for (string i : v) cout << i << endl;
	return 0;
}