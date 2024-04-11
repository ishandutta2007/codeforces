#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int p[N], vis[N], n; 

int GetPos(int i) { cout << "? " << i << endl; cin >> i; return i; }

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) p[i] = vis[i] = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		int lst = GetPos(i), fir = lst;
		while(1) {
			int now = GetPos(i); vis[now] = 1; 
			p[lst] = now; lst = now;
			if(now == fir) break; 
		}
	}
	cout << "! "; 
	for(int i = 1; i <= n; i++) cout << p[i] << " ";
	cout << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
4 2 1 3

*/