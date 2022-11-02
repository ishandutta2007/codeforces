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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
char s[maxN];
int t[4 * maxN], a[4 * maxN], b[4 * maxN];

struct S {
	int t;
	int a;
	int b;
	S() {
	}
	S(int t, int a, int b) : t(t), a(a), b(b) {
	}
};

S merge(S a, S b) {
	int len = min(a.a, b.b);
	S res;
	res.t = a.t + b.t + 2 * len;
	res.a = a.a + b.a - len;
	res.b = a.b + b.b - len;
	return res;
}

void init(int i, int l, int r) {
	if (l == r) {
		t[i] = 0;
		a[i] = (s[l] == '(');
		b[i] = (s[l] == ')');
		return ;
	}
	init(2 * i, l, (l + r) / 2);
	init(2 * i + 1, (l + r) / 2 + 1, r);
	S res = merge(S(t[2 * i], a[2 * i], b[2 * i]), S(t[2 * i + 1], a[2 * i + 1], b[2 * i + 1]));
	t[i] = res.t;
	a[i] = res.a;
	b[i] = res.b;
}

S get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return S(t[i], a[i], b[i]);
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}
	S A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	S B = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return merge(A, B);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", &s);
	int n = strlen(s);
	init(1, 0, n - 1);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", get(1, 0, n - 1, l - 1, r - 1).t);
	}


	return 0;
}