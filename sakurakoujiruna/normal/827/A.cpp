#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int N = 2e6L + 11;
vector <int> v[N];
string s[N];

int main() {
	ios :: sync_with_stdio(0);
	int n; cin >> n;

	for(int i = 0; i < n; i ++) {
		cin >> s[i];
		int k; cin >> k;
		while(k --) {
			int x; cin >> x;
			v[x].pb(i);
		}
	}

	int p = 0;
	string ans = "";
	for(int i = 1; i < N; i ++) if(v[i].size()) {
		while(p + 1 < i) {
			ans += 'a';
			p ++;
		}
		for(int j : v[i])
			while(p < i + s[j].size() - 1) {
				ans += s[j][p - i + 1];
				p ++;
			}
	}
	cout << ans << '\n';
}