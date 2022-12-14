#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cnt[30], _, n;

int main() {
	ios::sync_with_stdio(false);
	cin >> _;
	while (_ --) {
		string str;
		cin >> str;
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < str.size(); i ++) cnt[str[i] - 'a'] ++;
		int i;
		for (i = 0; i < str.size(); i ++) {
			if (cnt[str[i] - 'a']-- <= 1) break;
		}
		for (; i < str.size(); i ++) cout << str[i];
		cout << "\n";
	}
	return 0;	
}