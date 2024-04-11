#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

void solve() {
	int a = get(), b = get();
	if(a < b) swap(a, b);
	if(a == b) return cout << 0 << " " << 0 << endl, void();
	cout << a - b << " " << min(a % (a - b), (a - b) - a % (a - b)) << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}