#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
int n, a[N], cnt[N];

void solve() {
	n = get();
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++) a[i] = get(), ++cnt[abs(a[i])];
	int ans = 0;
	for(int i = 1; i <= 100; i++) 
		if(cnt[i] == 0) continue;
		else if(cnt[i] == 1) ans += 1;
		else ans += 2;
	if(cnt[0]) ans++;
	cout << ans << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}