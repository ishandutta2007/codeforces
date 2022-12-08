#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 100005;
int n;
char s[N];

void solve() {
	n = get();
	scanf("%s", s + 1);
	s[n + 1] = 'z' + 1;
	if(s[1] == s[2]) {
		printf("%c%c\n", s[1], s[2]);
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(s[i] < s[i + 1]) {
			for(int j = 1; j <= i; j++) printf("%c", s[j]);
			for(int j = i; j >= 1; j--) printf("%c", s[j]);
			printf("\n");
			return;
		}
	}
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}