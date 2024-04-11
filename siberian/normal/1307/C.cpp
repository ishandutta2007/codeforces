#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
string s;
int n;

void read() {
	cin >> s;
	n = s.size();
}

ll ans;

void run() {
	map<char, ll> cnt;
	map<string, ll> have;
	cnt[s[0]]++;
	ans = 1;
	for (int i = 1; i < n; i++) {
		for (char x = 'a'; x <= 'z'; x++) {
			//chkmax(ans, cnt[x] * (cnt[s[i]] + 1));
			string fans = "";
			fans += x;
			fans += s[i];
			have[fans] += cnt[x];
		}
		cnt[s[i]]++;
		//chkmax(ans, cnt[s[i]]);
	}	
	for (auto i : cnt)
		chkmax(ans, i.second);
	for (auto i : have)
		chkmax(ans, i.second);
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