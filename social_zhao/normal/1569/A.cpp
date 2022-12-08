#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

char s[105];

void solve() {
	int n = get(); scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) {
		int cnta = 0, cntb = 0;
		for(int j = i; j <= n; j++) {
			cnta += (s[j] == 'a'), cntb += (s[j] == 'b');
			if(cnta == cntb) { printf("%d %d\n", i, j); return; }
		}
	}
	printf("-1 -1\n");
	return;
}

int main() {
	int T = get();
	while(T--) solve(); 
	return 0;
}