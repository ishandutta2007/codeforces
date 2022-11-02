#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> a;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}

int cnt = 0;
map <int, int> have;

void add(int x) {
	if (have[x] == 1)
		cnt++;
	have[x]++;
}

void del(int x) {
	if (have[x] == 2) {
		cnt--;
	}
	have[x]--;
}

int ans;

bool check(int len) {
	for (int i = 0; i < len; i++)
		del(a[i]);
	bool flag = false;
	if (cnt == 0) flag = true;
	for (int i = len; i < n; i++) {
		add(a[i - len]);
		del(a[i]);
		if (cnt == 0) flag = true;
	}

	for (int i = n - len; i < n; i++)
		add(a[i]);
	return flag;
}

void run() {
	for (auto i : a)
		add(i);
	if(cnt == 0) {
		ans = 0;
		return;
	}
	int l = 0, r = n;
	while (l < r - 1) {
		int m = (l + r) / 2;
		if (check(m))
			r = m;
		else
			l = m;
	}
	ans = r;
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