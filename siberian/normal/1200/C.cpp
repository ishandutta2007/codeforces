#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, m, q;
int x;
	
void read() {
	cin >> n >> m >> q;
	x = __gcd(n, m);
}

vector<bool> ans;

int get_pos(int t, int a) {
	if (t == 1) {
		return (a + n/x - 1) / (n/x);
	}
	else {
		return (a + m/x - 1) / (m/x);
	}
}

void run() {
	for (int i = 0; i < q; i++) {
		int t1, a, t2, b;
		cin >> t1 >> a >> t2 >> b;
		if (get_pos(t1, a) == get_pos(t2, b)) {
			ans.push_back(true);
		}
		else {
			ans.push_back(false);
		}
	}
}

void write() {
	for (auto i : ans)
		if (i)
			cout << "YES\n";
		else
			cout << "NO\n";
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