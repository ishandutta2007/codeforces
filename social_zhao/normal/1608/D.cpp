#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, P = 998244353;
int n, fac[N], inv[N];
char s[3];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void init(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
	inv[n] = qpow(fac[n], P - 2);
	for(int i = n; i >= 1; i--) inv[i - 1] = inv[i] * i % P;
}

int C(int n, int m) { return (n >= m)? fac[n] * inv[m] % P * inv[n - m] % P : 0; }

main() {
	init(200000);
	n = get();
	int isSame = 0, cntB = 0, cntW = 0, cntQ = 0, allQ = 0, cntBW = 0, cntWB = 0; 
	for(int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		isSame += s[1] == s[2] && s[1] != '?';
		cntB += (s[1] == 'B') + (s[2] == 'B');
		cntW += (s[1] == 'W') + (s[2] == 'W');
		cntQ += (s[1] == '?') + (s[2] == '?');
		allQ += (s[1] == '?') && (s[2] == '?');
		cntBW += (s[1] == 'B') || (s[2] == 'W');
		cntWB += (s[1] == 'W') || (s[2] == 'B');
	}
	if(cntB > n || cntW > n) return printf("0\n"), 0;
	int ans = C(cntQ, n - cntB);
	if(!isSame && n > 1) {
		ans -= qpow(2, allQ);
		if(!cntBW && !cntWB) ans += 2;
		else if((!cntBW) || (!cntWB)) ans++;
	}
	ans = (ans % P + P) % P;
	cout << ans;
	return 0;
}