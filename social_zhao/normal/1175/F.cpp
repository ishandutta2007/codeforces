#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5, Base = 17, P = 998244353;
int n, a[N], ans;
int S[N], S2[N], pw[N], S3[N];

void init(int n) {
	for(int i = 1; i <= n; i++) S[i] = S[i - 1] + i;
	for(int i = 1; i <= n; i++) S2[i] = S2[i - 1] + i * i;
	pw[0] = 1;
	for(int i = 1; i <= n; i++) pw[i] = pw[i - 1] * Base % P;
	for(int i = 1; i <= n; i++) S3[i] = (S3[i - 1] + pw[i]) % P;
}

struct Hash {
	int sum, sum2, st;
	Hash() { sum = sum2 = st = 0; }
	Hash(int a, int b, int c) { sum = a, sum2 = b, st = c; }
	Hash operator +(Hash b) { return Hash(sum + b.sum, sum2 + b.sum2, (st + b.st) % P); }
	Hash operator -() { return Hash(-sum, -sum2, P - st); }
	Hash operator -(Hash b) { return *this + (-b); }
	bool operator <(Hash b) { return sum == b.sum? (sum2 == b.sum2? st < b.st : sum2 < b.sum2) : sum < b.sum; }
	bool operator ==(Hash b) { return sum == b.sum && sum2 == b.sum2 && st == b.st; }
} pre[N], suf[N];

void solve(int l, int r) {
	if(l == r) return ans += a[l] == 1, void();
	int mid = (l + r) >> 1;
	Hash nw;
	for(int i = mid; i >= l; i--) {
		nw = nw + Hash(a[i], a[i] * a[i], pw[a[i]]);
		pre[i] = nw;
	}
	nw = Hash();
	for(int i = mid + 1; i <= r; i++) {
		nw = nw + Hash(a[i], a[i] * a[i], pw[a[i]]);
		suf[i] = nw;
	}
	int mx = 0;
	for(int i = mid; i >= l; i--) {
		mx = max(mx, a[i]);
		if(mx <= mid - i + 1) continue;
		int len = mx - (mid - i + 1);
		if(pre[i] + suf[mid + len] == Hash(S[mx], S2[mx], S3[mx])) ++ans;
	}
	mx = 0;
	for(int i = mid + 1; i <= r; i++) {
		mx = max(mx, a[i]);
		if(mx <= i - mid) continue;
		int len = mx - (i - mid);
		if(suf[i] + pre[mid + 1 - len] == Hash(S[mx], S2[mx], S3[mx])) ++ans; 
	}
	solve(l, mid), solve(mid + 1, r);
}

main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	init(n);
	solve(1, n);
	cout << ans;
	return 0;
}