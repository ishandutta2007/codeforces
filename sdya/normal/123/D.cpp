#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;


const int maxN = 110000;
int c[maxN], p[maxN], q[maxN], cl[maxN], classes, n;
char s[maxN];
int lcp[maxN];

void build_step(int len) {
	if (classes == n) return ;
	for (int i = 0; i < n; i ++) c[i] = 0;

	for (int i = 0; i < n; i ++) q[i] = (p[i] + n - len) % n;
	for (int i = 0; i < n; i ++) c[cl[i]] ++;
	for (int i = 1; i < classes; i ++) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i --) p[c[cl[q[i]]] - 1] = q[i], c[cl[q[i]]] --;

	classes = 0;
	q[p[0]] = 0;
	for (int i = 1; i < n; i ++) {
		if (cl[p[i]] > cl[p[i - 1]]) classes ++; else
			if (cl[(p[i] + len) % n] > cl[(p[i - 1] + len) % n]) classes ++;
		q[p[i]] = classes;
	}
	classes ++;
	for (int i = 0; i < n; i ++) cl[i] = q[i];
}

void build_suffix_array() {
	for (int i = 0; i < 256; i ++) c[i] = 0;
	for (int i = 0; i < n; i ++) c[s[i]] ++;
	for (int i = 1; i < 256; i ++) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i --) p[c[s[i]] - 1] = i, c[s[i]] --;

	classes = 0;
	cl[p[0]] = 0;
	for (int i = 1; i < n; i ++) {
		if (s[p[i]] > s[p[i - 1]]) classes ++;
		cl[p[i]] = classes;
	}
	classes ++;

	int len = 1;
	while (true) {
		build_step(len), len += len;
		if (len >= n) break;
	}
}

void sufarr_lcp(char s[], int a[], int lcp[], int p[], int n) { 
	for (int i = 0; i < n; ++i) {
		p[a[i]] = i;
	} 
	int r = 0;
	for (int i = 0; i < n; ++i) {
		int x = p[i]; 
		if (x) { 
			int y = a[x-1]; 
			while(i+r<n && y+r<n && s[i+r] == s[y+r]) ++r; 
			lcp[x-1] = r; 
		} else {
			r = 0;
		}
		if(r > 0) --r;
	}
}


pair < int, int > t[4 * maxN];

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = make_pair(lcp[l], l);
		return ;
	}

	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	t[i] = min(t[2 * i], t[2 * i + 1]);
}

pair < int, int > get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}

	pair < int, int > A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	pair < int, int > B = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return min(A, B);
}

pair < int, int > getMin(int l, int r) {
	return get(1, 0, n - 2, l, r);
}

void solve(int l, int r, int shift, long long &res) {
	if (l > r) {
		return;
	}
	pair < int, int > m = getMin(l, r);
	int pos = m.second;
	int value = m.first;

	long long add = value - shift;
	long long length = (r - l + 2);
	long long coef = length * (length + 1LL) / 2LL;
	res += add * coef;
	solve(l, pos - 1, shift + add, res);
	solve(pos + 1, r, shift + add, res);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gets(s);
	n = strlen(s);
	s[n++] = 0;
	build_suffix_array();
	// p - suffarray
	sufarr_lcp(s, p, lcp, q, n);

	build(1, 0, n - 2);

	long long res = 0;
	for (int i = 1; i < n; ++i) {
		int length = n - p[i] - 1 - max(lcp[i - 1], lcp[i]);
		res += length;
	}

	solve(0, n - 2, 0, res);
	cout << res << endl;

	return 0;
}