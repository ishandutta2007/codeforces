#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 11;
int a[N];
int suf[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	string s; cin >> s;
	reverse(a, a + n);
	reverse(s.begin(), s.end());
	for(int i = n - 1; i >= 0; i --)
		suf[i] = suf[i + 1] + a[i];
	int ans = 0, pre = 0;
	for(int i = 0; i < n; i ++)
		if(s[i] == '1') {
			ans = max(ans, pre + suf[i + 1]);
			pre += a[i];
		}
	ans = max(ans, pre);
	cout << ans << '\n';
	return 0;
}