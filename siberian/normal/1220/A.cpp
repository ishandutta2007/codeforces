#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void read() {
	map <char, int> cnt;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		cnt[x]++;
	}
	while (true) {
		if (cnt['o'] && cnt['n'] && cnt['e']) {
			cout << "1 ";
			cnt['o']--;
			cnt['n']--;
			cnt['e']--;
			continue;
		}
		if (cnt['z'] && cnt['e'] && cnt['r'] && cnt['o']) {
			cout << "0 ";
			cnt['r']--;
			cnt['z']--;
			cnt['e']--;
			cnt['o']--;
			continue;
		}
		break;
	}
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