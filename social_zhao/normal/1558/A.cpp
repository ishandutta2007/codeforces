#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5;
int vis[N], bin[N], top;

void tag(int a, int b, int fa, int fb) {
	for(int i = 0; i <= a; i++) {
		int wa = i, la = fa - i, wb = b - fa + i, lb = fb - b + fa - i;
		if(wa >= 0 && wa <= fa && la >= 0 && la <= fa && wb >= 0 && wb <= fb && lb >= 0 && lb <= fb)
			vis[la + lb] = 1;
	}
}

void solve() {
	int a = get(), b = get();
	for(int i = 0; i <= a + b; i++) vis[i] = 0;
	tag(a, b, (a + b) / 2, (a + b) - (a + b) / 2);
	tag(a, b, (a + b) - (a + b) / 2, (a + b) / 2);
	top = 0;
	for(int i = 0; i <= a + b; i++) if(vis[i]) bin[++top] = i;
	printf("%d\n", top);
	for(int i = 1; i <= top; i++) printf("%d ", bin[i]); printf("\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}