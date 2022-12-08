#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5, P = 998244353;
int n, m, q, pw2[N];
int cnt[2];
map<int, int> col[N];

struct State {
	int cnt[N][2], fck, det, n;
	
	void add(int x, int y, int col) {
		fck -= cnt[x][0] && cnt[x][1];
		det -= cnt[x][0] || cnt[x][1];
		++cnt[x][(y & 1) ^ col];
		fck += cnt[x][0] && cnt[x][1];
		det += cnt[x][0] || cnt[x][1];
	}
	
	void del(int x, int y, int col) {
		fck -= cnt[x][0] && cnt[x][1];
		det -= cnt[x][0] || cnt[x][1];
		--cnt[x][(y & 1) ^ col];
		fck += cnt[x][0] && cnt[x][1];
		det += cnt[x][0] || cnt[x][1];
	}
	
	int ask() {
		if(fck) return 0;
		else return pw2[n - det];
	}
} R, C;

void add(int x, int y, int c) {
	if(col[x][y]) 
		R.del(x, y, col[x][y] - 1), C.del(y, x, col[x][y] - 1), cnt[((x + y) & 1) ^ (col[x][y] - 1)]--;
	col[x][y] = c + 1;
	R.add(x, y, col[x][y] - 1), C.add(y, x, col[x][y] - 1);
	cnt[((x + y) & 1) ^ c]++;
}

void del(int x, int y) {
	if(col[x][y]) 
		R.del(x, y, col[x][y] - 1), C.del(y, x, col[x][y] - 1), cnt[((x + y) & 1) ^ (col[x][y] - 1)]--;
	col[x][y] = 0;
}

int ask() {
	int res = R.ask() + C.ask();
	if(!cnt[0]) --res;
	if(!cnt[1]) --res;
	return (res + P) % P;
}

signed main() {
	n = get(), m = get(), q = get();
	pw2[0] = 1, R.n = n, C.n = m;
	for(int i = 1; i <= max(n, m); i++) pw2[i] = pw2[i - 1] * 2 % P;
	for(int i = 1; i <= q; i++) {
		int x = get(), y = get(), t = get();
		if(t == -1) del(x, y);
		else add(x, y, t);
		printf("%lld\n", ask());
	}
	return 0;
}

/*
999 1000 300000
519 1 -1
*/