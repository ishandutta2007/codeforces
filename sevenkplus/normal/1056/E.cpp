#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define P1 1000000007
#define P2 1000000009
#define P3 1000000021
#define Q1 137
#define Q2 139
#define Q3 151

#define N 1000010

string s, t;
int m, n;
int p1[N], a1[N];
int p2[N], a2[N];
int p3[N], a3[N];
int f1;

int hh1(int x, int l) {
	return ((a1[x+l]-(ll)a1[x]*p1[l])%P1+P1)%P1;
}

int hh2(int x, int l) {
	return ((a2[x+l]-(ll)a2[x]*p2[l])%P2+P2)%P2;
}

int hh3(int x, int l) {
	return ((a3[x+l]-(ll)a3[x]*p3[l])%P3+P3)%P3;
}

bool chk(int x, int y) {
	int x1 = hh1(0, x);
	int x2 = hh2(0, x);
	int x3 = hh3(0, x);
	int y1 = hh1(f1*x, y);
	int y2 = hh2(f1*x, y);
	int y3 = hh3(f1*x, y);
	if (x1 == y1 && x2 == y2 && x3 == y3) return false;
	int cur = 0;
	for (int i = 0; i < m; i ++) {
		if (s[i] == '0') {
			if (hh1(cur, x) != x1) return false;
			if (hh2(cur, x) != x2) return false;
			if (hh3(cur, x) != x3) return false;
			cur += x;
		} else {
			if (hh1(cur, y) != y1) return false;
			if (hh2(cur, y) != y2) return false;
			if (hh3(cur, y) != y3) return false;
			cur += y;
		}
	}
	return true;
}

int main() {
	cin >> s >> t;
	m = (int) s.length();
	n = (int) t.length();
	p1[0] = 1;
	for (int i = 0; i < n; i ++) p1[i+1] = (ll)p1[i]*Q1%P1;
	p2[0] = 1;
	for (int i = 0; i < n; i ++) p2[i+1] = (ll)p2[i]*Q2%P2;
	p3[0] = 1;
	for (int i = 0; i < n; i ++) p3[i+1] = (ll)p3[i]*Q3%P3;
	a1[0] = 0;
	for (int i = 0; i < n; i ++) a1[i+1] = ((ll)a1[i]*Q1+(t[i]-'a'+1))%P1;
	a2[0] = 0;
	for (int i = 0; i < n; i ++) a2[i+1] = ((ll)a2[i]*Q2+(t[i]-'a'+1))%P2;
	a3[0] = 0;
	for (int i = 0; i < n; i ++) a3[i+1] = ((ll)a3[i]*Q3+(t[i]-'a'+1))%P3;

	if (s[0] == '1') {
		for (int i = 0; i < m; i ++) s[i] ^= 1;
	}
	for (int i = 0; i < m; i ++)
		if (s[i] == '1') {
			f1 = i; break;
		}
	int s0 = 0, s1 = 0;
	for (int i = 0; i < m; i ++)
		if (s[i] == '0') s0++; else s1++;
	assert(s0 > 0);
	assert(s1 > 0);
	assert(s0 + s1 == m);
	int S = 0;
	for (int i = 1; i*s0 < n; i ++) {
		int j = (n-i*s0)/s1;
		if (i*s0+j*s1 == n) S += chk(i, j);
	}
	cout << S << endl;
	return 0;
}