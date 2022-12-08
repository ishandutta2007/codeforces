#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int vis[N], pri[N], tot;
int n, a[N];

void init(int n) {
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) pri[++tot] = i;
		for(int j = 1; j <= tot && i * pri[j] <= n; j++) {
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

void solve() {
	n = get();
	int sum = 0;
	for(int i = 1; i <= n; i++) a[i] = get(), sum += a[i];
	if(vis[sum]) {
		cout << n << endl;
		for(int i = 1; i <= n; i++) cout << i << " ";
		cout << endl;
		return;
	}
	for(int i = 1; i <= n; i++) if(vis[sum - a[i]]) {
		cout << n - 1 << endl;
		for(int j = 1; j <= n; j++) if(j != i) cout << j << " ";
		cout << endl;
		return;
	}
	assert(0);
}

int main() {
	init(100000);
	int T = get(); 
	while(T--) solve();
	return 0;
}