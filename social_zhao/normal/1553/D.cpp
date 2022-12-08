#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, m, pos[2][26], nxt[N][26];
char s[N], t[N];

void solve() {
	scanf("%s", s + 1), scanf("%s", t + 1), n = strlen(s + 1), m = strlen(t + 1);
	for(int i = 0; i < 26; i++) pos[0][i] = pos[1][i] = n + 1;
	for(int i = n; i >= 1; i--) {
		for(int j = 0; j < 26; j++) 
			nxt[i][j] = pos[(i + 1) & 1][j];
		pos[i & 1][s[i] - 'a'] = i;
	}
	for(int i = 0; i < 26; i++) nxt[0][i] = pos[1][i], nxt[1][i] = pos[0][i];
	int now = nxt[0][t[1] - 'a'];
	for(int i = 2; i <= m && now != n + 1; i++) 
		now = nxt[now][t[i] - 'a'];
	if((n + 1 - now) & 1) return printf("YES\n"), void();
	now = nxt[1][t[1] - 'a'];
	for(int i = 2; i <= m && now != n + 1; i++) 
		now = nxt[now][t[i] - 'a'];
	if((n + 1 - now) & 1) return printf("YES\n"), void();
	printf("NO\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}