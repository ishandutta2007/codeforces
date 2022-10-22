#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("E.in", "r", stdin);
	//freopen("E.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int l = 0, r = s.size() - 1;
	int sz = s.size();
	string res = "";
	while (r - l + 1 >= 4) {
		vector <int> cnt(3, 0);
		cnt[s[l] - 'a']++;
		cnt[s[l + 1] - 'a']++;
		cnt[s[r] - 'a']++;
		cnt[s[r - 1] - 'a']++;
		l += 2, r -= 2;
		for (int i = 0; i < 3; i++) {
			if (cnt[i] >= 2) {
				res += (char) (i + 'a');
				break;
			}
		}
	}
	cout << res;
	if (l <= r) {
		cout << s[l];
	}
	reverse(res.begin(), res.end());
	cout << res << "\n";
}