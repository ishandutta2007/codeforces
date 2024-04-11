#define _CRT_SECURE_NO_WARNINGS
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
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P[2] = {1000000007LL, 1000000009LL};
const long long Q[2] = {1000007LL, 1000007LL};

const int maxN = 310000;
int n;
int c[maxN];
char s[maxN];

vector < int > g[maxN];

unordered_set < long long > *S[maxN];
long long added[maxN];
long long multiplied[maxN];

int res[maxN];

long long inv(long long x, long long p) {
	long long x1 = 1, b1 = x;
	long long x2 = 0, b2 = p;
	while (b2) {
		long long q = b1 / b2;
		b1 -= q * b2;
		x1 -= q * x2;
		swap(x1, x2);
		swap(b1, b2);
	}
	x1 %= p;
	if (x1 < 0) {
		x1 += p;
	}
	return x1;
}

long long getValue(long long x, long long y) {
	return x * P[1] + y;
}

pair < long long, long long > getValue(long long x) {
	return make_pair(x / P[1], x % P[1]);
}

bool comp(int x, int y) {
	return S[x]->size() > S[y]->size();
}

long long sum(long long x, long long y) {
	pair < long long, long long > a = getValue(x);
	pair < long long, long long > b = getValue(y);
	a.first += b.first;
	a.second += b.second;

	a.first %= P[0];
	a.second %= P[1];

	return getValue(a.first, a.second);
}

long long mul(long long x) {
	pair < long long, long long > a = getValue(x);
	a.first = (a.first * Q[0]) % P[0];
	a.second = (a.second * Q[1]) % P[1];
	return getValue(a.first, a.second);
}

long long mul(long long x, long long y) {
	pair < long long, long long > a = getValue(x);
	pair < long long, long long > b = getValue(y);
	a.first = (a.first * b.first) % P[0];
	a.second = (a.second * b.second) % P[1];
	return getValue(a.first, a.second);
}

long long inv(long long x) {
	pair < long long, long long > a = getValue(x);
	a.first = inv(a.first, P[0]);
	a.second = inv(a.second, P[1]);
	return getValue(a.first, a.second);
}

long long sub(long long x, long long y) {
	pair < long long, long long > a = getValue(x);
	pair < long long, long long > b = getValue(y);
	a.first += P[0] - b.first;
	a.second += P[1] - b.second;

	a.first %= P[0];
	a.second %= P[1];

	return getValue(a.first, a.second);
}

void dfs(int v, int p = -1) {
	vector < int > children;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != p) {
			dfs(g[v][i], v);
			children.push_back(g[v][i]);
		}
	}

	long long cur = getValue(s[v] - 'a' + 1, s[v] - 'a' + 1);

	if (children.size() == 0) {
		S[v] = new unordered_set < long long > ();
		S[v]->insert(cur);
		res[v] = 1;
		added[v] = 0;
		multiplied[v] = getValue(1, 1);
		return ;
	}

	sort(children.begin(), children.end(), comp);

	S[v] = S[children[0]];
	added[v] = sum(mul(added[children[0]]), cur);
	multiplied[v] = mul(multiplied[children[0]]);

	long long im = inv(multiplied[v]);

	for (int i = 1; i < children.size(); ++i) {
		int u = children[i];
		for (unordered_set < long long > ::iterator it = S[u]->begin(); it != S[u]->end(); ++it) {
			long long value = *it;
			value = sum(mul(value, multiplied[u]), added[u]);
			value = sum(mul(value), cur);
			value = sub(value, added[v]);
			value = mul(value, im);
			S[v]->insert(value);
		}
	}

	cur = sub(cur, added[v]);
	cur = mul(cur, im);
	S[v]->insert(cur);

	res[v] = S[v]->size();
}

void gen() {
	int n = 300000;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("0 ");
	}
	printf("\n");

	for (int i = 0; i < n; ++i) {
		printf("%c", rand() % 1 + 'a');
	}
	printf("\n");
	
	for (int i = 1; i < n; ++i) {
		int u = rand() % i;
		printf("%d %d\n", u + 1, i + 1);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();
	//return 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &c[i]);
	}
	scanf("%s", &s);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0);

	int mx = 0;
	for (int i = 0; i < n; ++i) {
		mx = max(mx, res[i] + c[i]);
	}

	printf("%d\n", mx);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (res[i] + c[i] == mx) {
			++cnt;
		}
	}
	printf("%d\n", cnt);


	return 0;
}