#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

const int MX = 1000005;
const int MOD = 1000000007;
string a, b;
map<char, int> mp;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int tc; cin >> tc;
	mp['S'] = 0;
	mp['M'] = 1;
	mp['L'] = 2;
	while (tc --) {
		cin >> a >> b;	
		int la = a.length();
		int lb = b.length();
		if (mp[a[la - 1]] < mp[b[lb - 1]]) {
			cout << "<\n";
		} else if (mp[a[la - 1]] > mp[b[lb - 1]]) {
			cout << ">\n";
		} else {
			int fg = 0;
			if (la == lb) {
				cout << "=\n";
				continue;
			}
			if (la > lb && mp[a[la - 1]] == 0) fg = 1;
			else if (la < lb && mp[a[la - 1]] == 2) fg = 1;
			if (fg) cout << "<\n";
			else cout << ">\n"; 
		}
	}

	return 0;
}