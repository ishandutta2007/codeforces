#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3005;
int n, a[N], bin[N * 5], top;

int GetPos(int x) { for(int i = 1; i <= n; i++) if(a[i] == x) return i; }

void rev(int r) {
	if(r == 1) return;
	for(int i = 1; i <= r / 2; i++) swap(a[i], a[r - i + 1]);
	bin[++top] = r;
}

void solve() {
	n = get(), top = 0;
	int flag = 1;
	for(int i = 1; i <= n; i++) {
		a[i] = get();
		if((a[i] & 1) != (i & 1)) flag = 0;
	}
	if(!flag) return printf("-1\n"), void(); 
	for(int i = 1; i <= n; i += 2) {
		int x = i, y = i + 1;
		rev(GetPos(x)), rev(GetPos(y) - 1), rev(GetPos(y) + 1), rev(3), rev(n - i + 1);
	}
	rev(n);
	printf("%d\n", top);
	for(int i = 1; i <= top; i++) printf("%d ", bin[i]); printf("\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}