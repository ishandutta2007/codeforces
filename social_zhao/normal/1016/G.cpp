#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, a[N], X, Y, fx[N], fy[N];
int pri[N], cntX[N], cntY[N], tot;

const int _pri[] = { 0, 2, 3, 5, 6, 11, 13, 17, 19, 23, 29, 31, 37 };
mt19937 rnd;

int mul(int x, int y, int P) { return (x * y - (int)((long double)x / P * y) * P + P) % P; }
int f(int x, int c, int P) { return (mul(x, x, P) + c) % P; }
int gcd(int x, int y) { return y? gcd(y , x % y) : x; }

int qpow(int x, int y, int P) {
	int res = 1;
	while(y) {
		if(y & 1) res = mul(res, x, P);
		x = mul(x, x, P), y >>= 1;
	}
	return res;
}

int IsPrime(int n) {
	if(n == 2) return 1;
	if(n == 1) return 0; 
	int a = n - 1, b = 0;
	while(!(a & 1)) ++b, a /= 2;
	for(int i = 1; i <= 12; i++) {
		if(_pri[i] % n == 0) continue;
		int x = qpow(_pri[i], a, n), nxt;
		for(int j = 1; j <= b; j++, x = nxt) {
			nxt = mul(x, x, n);
			if(nxt == 1 && (x != 1 && x != n - 1)) return 0;
		}
		if(x != 1) return 0;
	} 
	return 1;
}

int PollardRho(int n) {
	int s = 0, t = 0, c = (unsigned long long)(rnd() * rnd()) % (n - 1) + 1, val = 1;
	for(int lim = 1; lim; lim <<= 1, s = t, val = 1) {
		for(int i = 1; i <= lim; i++) {
			t = f(t, c, n), val = mul(val, abs(t - s), n);
			if(i % 114 == 0) {
				int d = gcd(n, val);
				if(d > 1) return d;
			}
		}
		int d = gcd(n, val);
		if(d > 1) return d;
	}
	return n;
}

void GetFac(int n) {
	if(IsPrime(n)) 
		return pri[++tot] = n, void();
	int now = n;
	while(now == n) 
		now = PollardRho(n);
	GetFac(now), GetFac(n / now);
}

void FWT(int *A, int type) {
	for(int mid = 1; mid < 1 << tot; mid <<= 1)
		for(int i = 0; i < 1 << tot; i += mid << 1)
			for(int j = 0; j < mid; j++)
				A[i + j] += type * A[i + mid + j];
}


main() {
	n = get(), X = get(), Y = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	
	if(Y % X) return cout << 0, 0;
	
	if(Y == 1) {
		int cnt = 0;
		for(int i = 1; i <= n; i++) cnt += (a[i] == 1);
		cout << cnt * n << endl;
		return 0;
	}
	
	GetFac(Y);
	sort(pri + 1, pri + 1 + tot), tot = unique(pri + 1, pri + 1 + tot) - pri - 1;
	for(int i = 1; i <= tot; i++) while(Y % pri[i] == 0) Y /= pri[i], ++cntY[i];
	for(int i = 1; i <= tot; i++) while(X % pri[i] == 0) X /= pri[i], ++cntX[i];
	
	for(int i = 1; i <= n; i++) {
		int resX = 0, resY = 0, flagX = 1, flagY = 1;
		for(int j = 1; j <= tot; j++) {
			int cntJ = 0;
			while(a[i] % pri[j] == 0) a[i] /= pri[j], ++cntJ;
			if(cntJ < cntX[j]) flagX = 0;
			if(cntJ > cntY[j]) flagY = 0;
			if(cntJ != cntX[j]) resX |= 1 << (j - 1);
			if(cntJ != cntY[j]) resY |= 1 << (j - 1);
		}
		if(a[i] > 1) flagY = 0;
		if(flagX) ++fx[resX];
		if(flagY) ++fy[resY];
	}
	
	FWT(fx, 1), FWT(fy, 1);
	for(int i = 0; i < 1 << tot; i++) fx[i] = fx[i] * fy[i];
	FWT(fx, -1);
	
	int ans = 0;
	for(int i = 0; i < 1 << tot; i++) {
		int flag = 1;
		for(int j = 1; j <= tot; j++) 
			if((i >> (j - 1) & 1) && cntX[j] != cntY[j]) flag = 0;
		if(flag) ans += fx[i];
	}
	
	cout << ans << endl;
	return 0;
}