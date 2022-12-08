#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
int n, x, w[N];

void solve() {
	n = get(), x = get();
	for(int i = 1; i <= n; i++) w[i] = get();
	sort(w + 1, w + 1 + n);
	for(int i = 1, sum = 0; i <= n; i++) {
		sum += w[i];
		if(sum == x) {
			if(w[i] != w[n]) { swap(w[i], w[n]); break; }
			else return printf("NO\n"), void();
		}
		else if(sum > x) break;
	}
	printf("YES\n");
	for(int i = 1; i <= n; i++) printf("%d ", w[i]); printf("\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}