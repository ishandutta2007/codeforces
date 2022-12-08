#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005, inf = 1e18;
int vis[N], pri[N], tot;

void init(int n) {
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) pri[++tot] = i;
		for(int j = 1; j <= tot && i * pri[j] <= n; j++) {
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

int bin[N], top;

int ask(int x) { cout << "? " << x << endl, cout.flush(); cin >> x; return x; }
void guess(int x) { cout << "! " << x << endl, cout.flush(); }

void solve() {
//	cout << pri[131] << endl;
	top = 0;
	int shit = 1, mxr;
	for(int l = 1, r, cnt = 1; ; ++cnt, l = r) {
		int now = 1; r = l;
		while(inf / now >= pri[r]) now = now * pri[r], ++r;
		int need = 0, test = (1e9 / shit);
		for(int i = l; i <= r; i++) if(test > pri[i]) ++need, test /= pri[i];
		if(cnt + need + top <= 22) {
			int g = ask(now);
			for(int i = l; i < r; i++) if(g % pri[i] == 0) bin[++top] = pri[i], shit = shit * pri[i];
		}
		else break;
//		cout << l << " " << r << endl;
	}
	if(!top) return guess(8);
	int ans = 1;
	for(int i = 1; i <= top; i++) {
		int now = 1, res = 0;
		while(inf / now >= bin[i]) now = now * bin[i];
		int g = ask(now);
		while(g % bin[i] == 0) ++res, g /= bin[i];
		ans = ans * (res + 1);
	}
	if(1 <= ans && ans <= 4) guess(8);
	else guess(ans * 2);
}

main() {
	init(1000);
	int T = get();
	while(T--) solve();
	return 0;
}