#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int n, p, w, d; 

signed main() {
	n = get(), p = get(), w = get(), d = get();
	for(int y = 0; y <= w; y++) {
		if((p - y * d) % w) continue;
		int x = (p - y * d) / w;
		if(x < 0) continue;
		if(x + y <= n) { cout << x << " " << y << " " << n - x - y << endl; return 0; }
	}
	cout << -1;
	return 0;
}