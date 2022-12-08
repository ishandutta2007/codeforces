#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

bool chk(int n) {
	int s = sqrt(n);
	if(s * s == n) return 1;
	return 0;
}

bool solve() {
	int n = get();
	if(n % 2 == 0 && chk(n / 2)) return 1;
	else if(n % 4 == 0 && chk(n / 4)) return 1;
	return 0;
}

int main() {
	int T = get();
	while(T--) {
		if(solve()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}