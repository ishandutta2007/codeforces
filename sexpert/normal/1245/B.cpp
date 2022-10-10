#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
	int n, a, b, c, good = 0;
	string s;
	cin >> n >> a >> b >> c >> s;
	vector<int> pR, pS, pP;
	string ans;
	for(int i = 0; i < n; i++) {
		ans += '*';
		if(s[i] == 'R')
			pR.push_back(i);
		if(s[i] == 'P')
			pP.push_back(i);
		if(s[i] == 'S')
			pS.push_back(i);
	}
	while(a > 0 && pS.size()) {
		a--;
		ans[pS.back()] = 'R'; pS.pop_back();
		good++;
	}
	while(b > 0 && pR.size()) {
		b--;
		ans[pR.back()] = 'P'; pR.pop_back();
		good++;
	}
	while(c > 0 && pP.size()) {
		c--;
		ans[pP.back()] = 'S'; pP.pop_back();
		good++;
	}
	if(2*good < n) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(auto &ch : ans) {
		if(ch != '*')
			continue;
		if(a) {
			ch = 'R';
			a--;
			continue;
		}
		if(b) {
			ch = 'P';
			b--;
			continue;
		}
		ch = 'S';
		c--;
	}
	cout << ans << '\n';
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	int t;
	cin >> t;
	while(t--)
		solve();
}