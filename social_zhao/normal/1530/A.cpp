#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

char s[114514];

void solve() {
	scanf("%s", s + 1);
	int ans = 0;
	for(int i = 1; i <= strlen(s + 1); i++) ans = max(ans, s[i] - '0');
	printf("%d\n", ans);
}

int main() {
	int T = get();
	while(T--) solve(); 
	return 0;
}