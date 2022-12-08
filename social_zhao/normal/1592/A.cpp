#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, h, a[N];

void solve() {
	n = get(), h = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	sort(a + 1, a + 1 + n, [](int x, int y){ return x > y; });
	int fir = a[1], sec = a[2];
	int ans = 2 * (h / (fir + sec)); h %= (fir + sec);
	if(!h) cout << ans << endl;
	else if(h <= fir) cout << ans + 1 << endl;
	else cout << ans + 2 << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}