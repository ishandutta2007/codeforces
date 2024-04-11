#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, f[N], cnt[2];
char s1[N], s2[N];

int mex(int l, int r) {
	cnt[0] = cnt[1] = 0;
	++cnt[s1[l] - '0'], ++cnt[s1[r] - '0'];
	++cnt[s2[l] - '0'], ++cnt[s2[r] - '0'];
	if(!cnt[0]) return 0;
	if(!cnt[1]) return 1;
	return 2;
}

void solve() {
	n = get(), scanf("%s", s1 + 1), scanf("%s", s2 + 1);
	for(int i = 1; i <= n; i++) f[i] = 0;
	f[0] = 0;
	for(int i = 1; i <= n; i++) {
		f[i] = f[i - 1] + mex(i, i);
		if(i > 1) f[i] = max(f[i], f[i - 2] + mex(i - 1, i));
	}
	printf("%d\n", f[n]);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}