#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

main() {
	int T = get();
	while(T--) {
		int s = get(), n = get(), k = get();
		if(s == k) { cout << "YES" << endl; continue; }
		int ans = s / (2 * k) * k + min(s % (2 * k) + 1, k);
		if(ans <= n) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}