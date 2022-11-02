#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
map <int, int> cnt;
vector<int> a, b;
void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a){
		cin >> i;
		cnt[i]++;
	}
	b.resize(n);
	for (auto &i : b)
		cin >> i;
}

int ans;

void run() {
	ans = 0;
	vector<int> c;
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] > 1) {
			c.push_back(a[i]);
			cnt[a[i]] = 0;
		} 
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < c.size(); j++) {
			if ((c[j] | a[i]) == c[j]) {
				ans += b[i];
				break;
			} 
		}
	}
}

void write() {
	cout << ans << endl;
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