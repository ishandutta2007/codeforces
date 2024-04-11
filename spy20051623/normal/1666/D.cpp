#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
#define pii pair<int,int>
#define fr first
#define sc second
pii p[5];

int main() {
	int _;
	cin >> _;
	while (_--) {
		string s, t;
		cin >> s >> t;
		map<char,int>mp;
		for (int i = 0; i < t.size(); i++) mp[t[i]]++;
		string ans;ans.clear();
		for (int i = s.size() - 1; i >= 0; i--) {
			if (mp[s[i]] > 0) {
				ans+=s[i];
				mp[s[i]]--;
			}
		}
		reverse(ans.begin(),ans.end());
		if (ans==t) puts("YES");
		else puts("NO");
	}
}