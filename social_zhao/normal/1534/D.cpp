#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2005;
int n, bin[2][N], top[2], a[N], b[N], d[N], tot;
int vis[N][N];

void solve(int opt) {
	for(int i = 1; i <= top[opt]; i++) {
		int u = bin[opt][i]; 
		if(opt == 0 && u == 1) continue;
		cout << "? " << u << endl; cout.flush();
		for(int j = 1, d; j <= n; j++) {
			cin >> d;
			if(d == 1) ++tot, a[tot] = u, b[tot] = j;
		}
	}
	cout << "!" << endl;
	for(int i = 1; i <= tot; i++) cout << a[i] << " " << b[i] << endl;
	cout.flush();
}

int main() {
	cin >> n;
	cout << "? 1" << endl; cout.flush();
	for(int i = 1; i <= n; i++) {
		cin >> d[i], bin[d[i] & 1][++top[d[i] & 1]] = i;
	}
	if(top[0] <= top[1]) {
		for(int i = 1; i <= n; i++) if(d[i] == 1) ++tot, a[tot] = 1, b[tot] = i;
		solve(0);
	}
	else solve(1);
	return 0;
}