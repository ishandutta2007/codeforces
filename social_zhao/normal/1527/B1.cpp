#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005;
int n, now, swp;
char s[N];

void solve() {
	n = get();
	scanf("%s", s + 1);
	if(n & 1 && (s[n / 2 + 1] == '0')) swp = 1;
	else swp = 0;
	now = 0;
	for(int i = 1; i <= n / 2; i++) if(s[i] == '0') now++;	
	if(swp && now) printf("ALICE\n");
	else printf("BOB\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}