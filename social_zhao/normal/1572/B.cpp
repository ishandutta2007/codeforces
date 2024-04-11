#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, a[N], bin[N << 1], top;

void solve(int l, int r) {
	for(int i = l; i + 2 <= r; i += 2)
		if(a[i] != a[i + 1]) 
			bin[++top] = i, a[i] = a[i + 1] = a[i + 2] = a[i] ^ a[i + 1] ^ a[i + 2];
	for(int i = r - 2; i >= l; i -= 2) bin[++top] = i;
}

void solve() {
	n = get(), top = 0;
	int type = 0;
	for(int i = 1; i <= n; i++) a[i] = get(), type ^= a[i];
	if(type) return printf("NO\n"), void();
	int flag = 0;
	if(n & 1) solve(1, n), flag = 1;
	else {
		int now = 0;
		for(int i = 1; i <= n; i++) {
			now += a[i];
			if((i & 1) && (now & 1) == 0) { 
				if(i > 2) solve(1, i);
				solve(i + 1, n), flag = 1; break; 
			}
		}
	}
	if(!flag) return printf("NO\n"), void();
	printf("YES\n");
	printf("%d\n", top);
	for(int i = 1; i <= top; i++) printf("%d ", bin[i]); printf("\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
6
1 1 1 1 0 0
*/