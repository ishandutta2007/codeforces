#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
int n, vis[N];
char s[N];

void init(int n) {
	vis[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(vis[i]) continue;
		for(int j = i + i; j <= n; j += i) vis[j] = 1;
	}
}

void solve() {
	int n = get();
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) {
		if(vis[s[i] - '0']) { printf("1\n%c\n", s[i]); return; }
	}
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			if(vis[(s[i] - '0') * 10 + s[j] - '0']) { printf("2\n%d\n", (s[i] - '0') * 10 + s[j] - '0');  return; }
}

int main() {
	int T = get();
	init(100);
	while(T--) solve();
	return 0;
}