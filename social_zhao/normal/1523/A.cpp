#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e3 + 5;
int n, m, a[N], bin[N], top;
char s[N];

void solve() {
	n = get(), m = get();
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) a[i] = s[i] - '0';
	top = 0;
	for(int i = 1; i <= n; i++) if(a[i] == 1) bin[++top] = i;
	bin[0] = -114514, bin[top + 1] = 114514;
	for(int i = 1; i <= top; i++) {
		int pos = bin[i], len, ren;
		len = min(m, (bin[i] - bin[i - 1] - 1) / 2), ren = min(m, (bin[i + 1] - bin[i] - 1) / 2);
		for(int j = max(pos - len, 1); j <= min(pos + ren, n); j++) s[j] = '1';
	}
	printf("%s\n", s + 1);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}