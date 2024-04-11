#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	map<int, int> pos;
	map<int, int> neg;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		int pc = y-x;
		int nc = y+x;
		if (pos.count(pc) == 0) pos[pc] = 1;
		else pos[pc]++;
		if (neg.count(nc) == 0) neg[nc] = 1;
		else neg[nc]++;
	}
	ll ans = 0LL;
	map<int, int>::iterator it;
	for (it = pos.begin(); it != pos.end(); ++it) {
		ans += ((it->second+0LL)*(it->second-1LL))/2LL;
	}
	for (it = neg.begin(); it != neg.end(); ++it) {
		ans += ((it->second+0LL)*(it->second-1LL))/2LL;
	}
	cout << ans << endl;
	cin >> ans;
}