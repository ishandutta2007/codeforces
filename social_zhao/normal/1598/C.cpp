#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, a[N];
map<int, int> cnt;

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	int sum = 0;
	for(int i = 1; i <= n; i++) sum += a[i];
	if(sum * 2 % n) return cout << 0 << endl, void();
	int k = sum * 2 / n, ans = 0;
	cnt.clear();
	for(int i = 1; i <= n; i++) ans += cnt[k - a[i]], ++cnt[a[i]];
	cout << ans << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}