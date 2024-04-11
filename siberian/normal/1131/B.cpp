#include <bits/stdc++.h>

using namespace std;

#define int long long
int n;
vector <pair <int, int> > a;
void read() {
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first  >> a[i].second;
	}
	int ans = 0;
	vector <pair <int, int> > fans;
	for (int i = 1; i <= n; i++) 
	{
		int l = max(a[i - 1].first, a[i - 1].second);
		int r = min(a[i].first, a[i].second);
		if (r >= l) {
			fans.push_back({l, 0});
			fans.push_back({r, 1});
		}
	}
	sort(fans.begin(), fans.end());
	int s = -1;
	int cnt = 0;
	for (auto i : fans) {
		if (i.second == 0 && cnt == 0) {
			s = i.first;
		}
		if (i.second == 1) {
			cnt--;
		}
		if (i.second == 0) {
			cnt++;
		}
		if (cnt == 0) {
			ans += i.first - s + 1;
		}
	}

	cout << ans << endl;
}

void run() {
	
}

void write() {
	
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}