#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

void solve() {
	int a = get(), b = get();
	if((a - b) & 1) printf("-1\n");
	else {
		if(a == b && a == 0) printf("0\n");
		else if(a == b) printf("1\n");
		else printf("2\n");
	}
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}