#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int P = 1e9 + 7;
int k, n;
int mp[256], tmp[6];
int top;
map<int, int> ch[2], col, vis, f[6];

int Fa(int x) { return x / 2; }

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void dfs(int u) {
	if(col[u] == -1) for(int i = 0; i < 6; i++) f[i][u] = 1;
	else f[col[u]][u] = 1;
	for(int t = 0; t < 2; t++) {
		int v = ch[t][u];
		if(!v) continue;
		dfs(v);
		for(int i = 0; i < 6; i++) tmp[i] = 0;
		for(int i = 0; i < 6; i++)
			for(int j = 0; j < 6; j++)
				if(i != (j ^ 1) && i != j) 
					tmp[i] = (tmp[i] + f[i][u] * f[j][v]) % P;
		for(int i = 0; i < 6; i++) f[i][u] = tmp[i];
	}
}

signed main() {
	k = get(), n = get();
	int tot = 1;
	for(int i = 1; i <= k; i++) tot = tot * 2;
	tot--;
	if(n == 0) {
		cout << 6 * qpow(4, tot - 1) % P << endl;
		return 0;
	}
	mp['w'] = 0, mp['y'] = 1, mp['g'] = 2, mp['b'] = 3, mp['r'] = 4, mp['o'] = 5;
	int flag = 0;
	for(int i = 1; i <= n; i++) {
		int u; char s[10];
		u = get(), cin >> s;
		if(!vis[u]) --tot;
		vis[u] = 1, col[u] = mp[s[0]];
		while(u != 1) {
			int lst = Fa(u);
			ch[u & 1][lst] = u;
			if(!vis[lst]) --tot, vis[lst] = 1, col[lst] = -1;
			u = lst;
		}
	}
	dfs(1);
	int ans = 0;
	for(int i = 0; i < 6; i++) ans = (ans + f[i][1]) % P;
	cout << ans * qpow(4, tot) % P << endl;
	return 0;
}