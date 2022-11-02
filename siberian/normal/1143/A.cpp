#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;
vector <int> a;

void read() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	int lpos = 0;
	int rpos = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == 0)
			lpos = i;
		else
			rpos = i;
	ans = min(lpos, rpos) + 1;
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