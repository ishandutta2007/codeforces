#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 15;
char s[N];
int rem[N] = { 0, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0 };
int cnt[2];

int calc(int x) {
	cnt[0] = cnt[1] = 0;
	for(int i = 1; i <= 10; i++) {
		int c;
		if(s[i] == '?') c = (i & 1) ^ x;
		else c = s[i] - '0';
		cnt[i & 1] += c;
		if(cnt[i & 1] > cnt[(i & 1) ^ 1] + rem[i] || cnt[(i & 1) ^ 1] > cnt[i & 1] + rem[i + 1]) 
			return i;
	}
	return 10;
}

void solve() {
	scanf("%s", s + 1);
	printf("%d\n", min(calc(1), calc(0)));
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
0100000000
*/