#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1010;

int n;
int a[MAXN][MAXN];

void read() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}

int find(int x) {
	int l = 1, r = 1e9;
	r += 10;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (mid * mid <= x)
			l = mid;
		else
			r = mid;
	}
	return l;
}

vector<int> ans;

void run() {
	int a0 = find(a[0][1] * a[0][2] / a[1][2]);
	ans.push_back(a0);
	for (int i = 1; i < n; i++)
		ans.push_back(a[0][i] / a0);
}

void write() {
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
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