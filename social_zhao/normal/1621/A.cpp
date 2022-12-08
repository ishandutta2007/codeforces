#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

void solve() {
	int n = get(), k = get();
	if(n == 1) return printf("R\n"), void();
	if((n + 1) / 2 < k) return printf("-1\n"), void();
	int cnt = 0;
	for(int i = 1; i <= n; i++, printf("\n")) 
		for(int j = 1; j <= n; j++)
			if(i == j && i & 1 && cnt < k) ++cnt, printf("R");
			else printf(".");
}

int main() {
	int T = get();
	while(T--) solve(); 
	return 0;
}