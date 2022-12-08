#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
char s[N];
int n;

void solve() {
	scanf("%s", s + 1), n = strlen(s + 1);
	int cnt0 = 0;
	for(int i = 1; i <= n; i++) if(s[i] != s[i - 1] && s[i] == '0') ++cnt0;
	printf("%d\n", min(cnt0, 2));
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}