#include <bits/stdc++.h>

using namespace std;

long long cnt1[26], t[26];
long long cnt2[26][26];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	for(int i = 0; i < s.size(); ++i)
		++cnt1[s[i] - 'a'];

	for(int i = 0; i < s.size(); ++i){
		for(int j = 0; j < 26; ++j)
			cnt2[j][s[i] - 'a'] += t[j];
		++t[s[i] - 'a'];
	}

	long long ans = 0;
	for(int i = 0; i < 26; ++i)
		ans = max(ans, cnt1[i]);

	for(int i = 0; i < 26; ++i)
		for(int j = 0; j < 26; ++j)
			ans = max(ans, cnt2[i][j]);

	cout << ans << "\n";
}