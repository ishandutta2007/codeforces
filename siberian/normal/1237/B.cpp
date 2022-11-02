#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e5 + 10;
int n, a[MAXN], b[MAXN], p[MAXN];

void read() {
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i]; a[i]--;
		p[a[i]] = i;
	}
	set<int> have;
	for (int i = 0; i < n; i++)
		have.insert(i);

	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> b[i];
		b[i]--;
		have.erase(p[b[i]]);	
		if (*have.begin() < p[b[i]]) 
			ans++;
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