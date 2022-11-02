#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, k, a, b;

int lcm(int a, int b) {
	return b / __gcd(a, b);
}
int s;
void read() {
	cin >> n >> k >> a >> b;
	s = n * k;
}

pair <int, int> check(int start) {
	pair <int, int> ans = {1e18, -1e18};

	for (int i = 0; i <= n; i++) {
		int pos;
		int l;

		//1
		pos = i * k + b;
		l = pos - start;
	//	cout << "start = " << start << endl;
	//	cout << "pos = " << pos << endl;
	//	cout << "l = " << l << endl;
      //  cout << endl;
		if (l > 0) {
			int fans = lcm(l, s);
			ans.first = min(ans.first, fans);
			ans.second = max(ans.second, fans);
		}

		//2
		pos = i * k - b;
		l = pos - start;
		if (l > 0) {
			int fans = lcm(l, s);
			ans.first = min(ans.first, fans);
			ans.second = max(ans.second, fans);
		}
	}
	return ans;
}

int x, y;
void run() {
    x = 1e18;
    y = -1e18;
    pair <int, int> fans;
    fans = check(a);
    x = min(x, fans.first);
    x = min(x, fans.second);
    y = max(y, fans.first);
    y = max(y, fans.second);
    
    fans = check(-a);
    x = min(x, fans.first);
    x = min(x, fans.second);
    y = max(y, fans.first);
    y = max(y, fans.second);
}

void write() {
	cout << x << " " << y << endl;
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