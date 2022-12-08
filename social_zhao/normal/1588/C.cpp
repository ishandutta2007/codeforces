#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5;
int n, a[N], now, tag, mul, ans, f[N];
map<int, int> mp;

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	mp.clear(), now = tag = ans = 0, mul = 1;
	f[0] = 0;
	for(int i = 1; i <= n; i++) {
		map<int, int>::iterator it;
		if(mul == 1) {
			while(mp.size()) {
				it = mp.end();
				--it;
				if(it -> first * mul + tag > a[i]) now -= it -> second, mp.erase(it);
				else break;
			}
		}
		else {
			while(mp.size()) {
				it = mp.begin();
				if(it -> first * mul + tag > a[i]) now -= it -> second, mp.erase(it);
				else break;
			}
		}
		ans += mp[(a[i] - tag) * mul] + (a[i] == 0);
		tag *= -1, mul *= -1, tag += a[i];
		mp[(a[i] - tag) * mul]++;
	}
	cout << ans << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
4
1 2 2 1
*/