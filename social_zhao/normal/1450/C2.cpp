#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 305;
int n, cnt[3][2], tot;
char s[N][N];

void clear() {
	memset(cnt, 0, sizeof(cnt)), tot = 0;
}

void print(int x, int y) {
	for(int i = 1; i <= n; i++, printf("\n")) {
		for(int j = 1; j <= n; j++) {
			char now = s[i][j];
			if((i + j) % 3 == x && now == 'O') now = 'X';
			if((i + j) % 3 == y && now == 'X') now = 'O';
			printf("%c", now);
		}
	}
}

void solve() {
	clear();
	n = get();
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(s[i][j] == '.') continue;
			else if(s[i][j] == 'O') ++cnt[(i + j) % 3][0], ++tot;
			else if(s[i][j] == 'X') ++cnt[(i + j) % 3][1], ++tot;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(i != j && cnt[i][0] + cnt[j][1] <= tot / 3) { print(i, j); return; }
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}