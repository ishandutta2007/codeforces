#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
char s[N];
int n, bin[N], top;

void solve() {
	n = get();
	scanf("%s", s + 1);
	top = 0;
	for(int i = 1; i <= n; i++) if(s[i] != '?') bin[++top] = i;
	if(!top) {
		int now = 0;
		for(int i = 1; i <= n; i++) now ^= 1, s[i] = now == 1? 'B' : 'R';
		printf("%s\n", s + 1);
		return;
	}
	int now = s[bin[1]] == 'B';
	for(int i = bin[1] - 1; i >= 1; i--) now ^= 1, s[i] = now == 1? 'B' : 'R';
	for(int i = 1; i < top; i++) {
		int now = s[bin[i]] == 'B';
		for(int j = bin[i] + 1; j < bin[i + 1]; j++) now ^= 1, s[j] = now == 1? 'B' : 'R';
	}
	now = s[bin[top]] == 'B';
	for(int i = bin[top] + 1; i <= n; i++) now ^= 1, s[i] = now == 1? 'B' : 'R';
	printf("%s\n", s + 1);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}