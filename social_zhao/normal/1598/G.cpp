#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5, M = 1e6 + 5;
char s[N], x[N], tmp[M];
int n, m, top, zeta[N];

void GetZ() {
	zeta[1] = top;
	for(int i = 2, l = 0, r = 0; i <= top; i++) {
		if(i <= r) zeta[i] = min(zeta[i - l + 1], r - i + 1);
		while(i + zeta[i] <= top && tmp[i + zeta[i]] == tmp[zeta[i] + 1]) ++zeta[i];
		if(i + zeta[i] - 1 > r) l = i, r = i + zeta[i] - 1;
	}
}

int queryLCP(int x) { return zeta[m + 1 + x]; }

const int B = 5;
int P[B] = { 469762049, 998244353, 1004535809, 19260817, 1ll * rand() * rand() % 1000000000 + 1 };

struct Hash {
	int val[B];
	Hash(int x = 0) { for(int i = 0; i < B; i++) val[i] = x % P[i]; }
	Hash operator +(Hash b) { Hash res; for(int i = 0; i < B; i++) res.val[i] = (val[i] + b.val[i]) % P[i]; return res; }
	Hash operator -(Hash b) { Hash res; for(int i = 0; i < B; i++) res.val[i] = (val[i] - b.val[i] + P[i]) % P[i]; return res; }
	Hash operator *(Hash b) { Hash res; for(int i = 0; i < B; i++) res.val[i] = (val[i] * b.val[i]) % P[i]; return res; }
	bool operator ==(Hash b) { for(int i = 0; i < B; i++) if(val[i] != b.val[i]) return 0; return 1; }
};

Hash sum[N], _x, pw[N];

Hash GetSum(int l, int r) { return sum[r] - sum[l - 1] * pw[r - l + 1]; }

void chk(int l, int r, int lenb) {
	if(lenb <= 0) return;
	if(l > lenb) {
		int r1 = l - 1, l1 = r1 - lenb + 1;
		if(GetSum(l1, r1) + GetSum(l, r) == _x) cout << l1 << " " << r1 << endl << l << " " << r << endl, exit(0);
	}
	if(r + lenb <= n) {
		int l1 = r + 1, r1 = l1 + lenb - 1;
		if(GetSum(l, r) + GetSum(l1, r1) == _x) cout << l << " " << r << endl << l1 << " " << r1 << endl, exit(0);
	}
}

main() {
	srand(time(NULL));
	cin >> s + 1 >> x + 1;
	n = strlen(s + 1), m = strlen(x + 1);
	for(int i = 1; i <= m; i++) tmp[++top] = x[i];
	tmp[++top] = '#';
	for(int i = 1; i <= n; i++) tmp[++top] = s[i];
	GetZ();
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] * 10 + (s[i] - '0');
	for(int i = 1; i <= m; i++) _x = _x * 10 + (x[i] - '0');
	pw[0] = 1;
	for(int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 10;
	// case 1: |a| = |x| - 1 
	if(m > 1) {
		for(int l = 1; l <= n; l++) {
			int r = l + m - 2, l1 = r + 1, r1 = l1 + m - 2;
			if(r1 > n) break;
			if(GetSum(l, r) + GetSum(l1, r1) == _x) {
				cout << l << " " << r << endl << l1 << " " << r1 << endl;
				return 0;
			}
		}
	}
	for(int l = 1; l <= n; l++) {
		int r = l + m - 1;
		int lcp = min(r - l + 1, queryLCP(l));
		chk(l, r, m - lcp), chk(l, r, m - lcp - 1);
	}
	cout << "f**k you!" << endl;
	return 0;
}