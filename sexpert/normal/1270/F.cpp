#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int RAT = 125, SZ = 1600;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a(1), pre(1);
	for(int i = 0; i < n; i++) {
		if(s[i] == '1')
			a.push_back(i+1);
		pre.push_back(pre.back() + (s[i] == '1'));
	}
    int m = a.size();
    m--;
	a.push_back(n + 1);
	ll ans = 0;
	for(int r = 1; r <= RAT; r++) {
		map<int, int> cnt;
		for(int i = 0; i <= n; i++) {
			auto &x = cnt[r*pre[i] - i];
			ans += x++;
		}
	}
	for(int l = 1; l <= SZ; l++) {
		for(int i = 1; i + l - 1 <= m; i++) {
			for(int j = a[i - 1] + 1; j <= a[i]; j++) {
				ans += max(0, (a[i+l]-j)/l - max(RAT, (a[i+l-1]-j)/l));
			}
		}
	}
	cout << ans << '\n';
}