#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int n, k;

const int B = 20;
struct Int {
	int dig[B];
	Int() { memset(dig, 0, sizeof(dig)); }
	Int(int x) { memset(dig, 0, sizeof(dig)); int tot = 0; while(x) dig[++tot] = x % k, x /= k; }
	int convert() { int res = 0; for(int i = B - 1; i >= 1; i--) res = res * k + dig[i]; return res; }
	Int operator +(Int b) {
		Int res;
		for(int i = 1; i < B; i++) res.dig[i] = (dig[i] + b.dig[i]) % k;
		return res;
	}
	Int operator -(Int b) {
		Int res;
		for(int i = 1; i < B; i++) res.dig[i] = (dig[i] - b.dig[i] + k) % k;
		return res;
	}
};

int ask(Int x) { cout << x.convert() << endl; int res; cin >> res; return res; }

void solve() {
	cin >> n >> k;
	Int now = 0;
	for(int i = 0; i <= n; i++) {
		int res = ask(now + i);
		if(res == 1) return;
		now = now - (now + i);
	}
}

int main() {
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}