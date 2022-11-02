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


const int maxN = 310000;

int c[maxN], p[maxN], q[maxN], cl[maxN], classes, n;
char s[maxN];
char s1[maxN];
char s2[maxN];
char s3[maxN];
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

int t[maxN];
int sums[4][maxN];

vector < pair < int, int > > g[maxN];
int parent[maxN], lt[maxN], rt[maxN];

int findSet(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = findSet(parent[v]);
}

void mergeSets(int u, int v) {
	if (rand() % 2) {
		parent[u] = v;
		lt[v] = min(lt[v], lt[u]);
		rt[v] = max(rt[v], rt[u]);
	} else {
		parent[v] = u;
		lt[u] = min(lt[u], lt[v]);
		rt[u] = max(rt[u], rt[v]);
	}
}

long long getWays(int l, int r) {
	long long a = sums[1][r] - sums[1][l - 1];
	long long b = sums[2][r] - sums[2][l - 1];
	long long c = sums[3][r] - sums[3][l - 1];
	return a * b * c;
}

const long long P = 1000000007LL;
long long res[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gets(s1);
	gets(s2);
	gets(s3);
	int n1 = strlen(s1);
	int n2 = strlen(s2);
	int n3 = strlen(s3);
	int l1 = 0, r1 = n1 - 1;
	int l2 = r1 + 2, r2 = l2 + n2 - 1;
	int l3 = r2 + 2, r3 = l3 + n3 - 1;

	n = 0;
	for (int i = 0; i < n1; ++i) {
		s[n++] = s1[i];
	}
	s[n++] = '$';
	for (int i = 0; i < n2; ++i) {
		s[n++] = s2[i];
	}
	s[n++] = '&';
	for (int i = 0; i < n3; ++i) {
		s[n++] = s3[i];
	}
	s[n++] = '#';
	build_suffix_array();
	for (int i = 0; i < n; ++i) {
		if (p[i] >= l1 && p[i] <= r1) {
			t[i] = 1;
		}
		if (p[i] >= l2 && p[i] <= r2) {
			t[i] = 2;
		}
		if (p[i] >= l3 && p[i] <= r3) {
			t[i] = 3;
		}
	}

	for (int j = 1; j <= 3; ++j) {
		for (int i = 0; i < n; ++i) {
			sums[j][i] = (t[i] == j);
			if (i > 0) {
				sums[j][i] += sums[j][i - 1];
			}
		}
	}

	// p - suffarray
	sufarr_lcp(s, p, lcp, q, n);

	for (int i = 2; i + 1 < n; ++i) {
		parent[i] = i;
		lt[i] = rt[i] = i;
	}

	for (int i = 2; i + 2 < n; ++i) {
		int h = min(lcp[i], lcp[i + 1]);
		g[h].push_back(make_pair(i, i + 1));
	}

	long long ways = 0;
	for (int h = maxN - 1; h >= 1; --h) {
		for (int i = 0; i < g[h].size(); ++i) {
			int u = g[h][i].first;
			int v = g[h][i].second;

			int x = findSet(u);
			int y = findSet(v);

			if (x != y) {
				ways -= getWays(lt[x], rt[x] + 1);
				ways -= getWays(lt[y], rt[y] + 1);
				ways += getWays(min(lt[x], lt[y]), max(rt[x], rt[y]) + 1);
				mergeSets(x, y);
			}
		}
		res[h] = ways % P;
	}

	for (int i = 1; i <= min(n1, min(n2, n3)); ++i) {
		printf("%d ", (int)(res[i]));
	}
	printf("\n");

	return 0;
}