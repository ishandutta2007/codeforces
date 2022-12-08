#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, m, vis[N];

void solve() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) vis[i] = 0;
	for(int i = 1; i <= m; i++) {
		int a = get(), b = get(), c = get();
		vis[b] = 1;
	}
	int pos = 0;
	for(int i = 1; i <= n; i++) if(!vis[i]) pos = i;
	for(int i = 1; i <= n; i++) if(i != pos) cout << i << " " << pos << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}