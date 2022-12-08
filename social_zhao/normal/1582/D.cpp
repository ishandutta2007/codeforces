#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, a[N], b[N];

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	if(n & 1) {
		if(a[1] == -a[2]) {
			if(a[1] != -a[3]) {
				b[1] = b[3] = a[2];
				b[2] = -a[1] - a[3];
			}
			else {
				b[2] = b[3] = a[1];
				b[1] = -a[2] - a[3];
			}
		}
		else {
			b[1] = b[2] = a[3];
			b[3] = -a[1] - a[2];
		}
		for(int i = 4; i <= n; i += 2) b[i] = a[i + 1], b[i + 1] = -a[i]; 
	}
	else {
		for(int i = 1; i <= n; i += 2) b[i] = a[i + 1], b[i + 1] = -a[i];
	}
	for(int i = 1; i <= n; i++) cout << b[i] << " ";
	cout << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}