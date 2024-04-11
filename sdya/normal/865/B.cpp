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
long long n, S;

long long s[maxN], a[maxN], b[maxN];
vector < int > p, q, r;

bool compA(int x, int y) {
	return a[x] - b[x] < a[y] - b[y];
}

bool compB(int x, int y) {
	return b[x] - a[x] < b[y] - a[y];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%lld%lld", &n, &S);
	long long total = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld%lld%lld", &s[i], &a[i], &b[i]);
		total += s[i];
		if (a[i] > b[i]) {
			p.push_back(i);
		} else if (a[i] < b[i]) {
			q.push_back(i);
		} else {
			r.push_back(i);
		}
	}

	long long m = (total + S - 1) / S;
	sort(p.begin(), p.end(), compA);
	sort(q.begin(), q.end(), compB);

	long long u = 0, v = 0;
	for (int i = 0; i < p.size(); ++i) {
		u += s[p[i]];
	}
	for (int i = 0; i < q.size(); ++i) {
		v += s[q[i]];
	}

	if ((u + S - 1) / S + (v + S - 1) / S <= m) {
		long long res = 0;
		for (int i = 0; i < n; ++i) {
			res += s[i] * max(a[i], b[i]);
		}
		printf("%lld\n", res);
		return 0;
	}

	long long eu = u % S;
	long long ev = v % S;

	long long curU = 0;
	for (int i = 0; i < q.size(); ++i) {
		curU += s[q[i]] * b[q[i]];
	}
	for (int i = 0; i < p.size(); ++i) {
		int index = p[i];
		long long d = min(eu, s[index]);
		curU += (s[index] - d) * a[index];
		curU += d * b[index];
		eu -= d;
	}

	long long curV = 0;
	for (int i = 0; i < p.size(); ++i) {
		curV += s[p[i]] * a[p[i]];
	}
	for (int i = 0; i < q.size(); ++i) {
		int index = q[i];
		long long d = min(ev, s[index]);
		curV += (s[index] - d) * b[index];
		curV += d * a[index];
		ev -= d;
	}

	long long res = 0;
	for (int i = 0; i < r.size(); ++i) {
		res += s[r[i]] * a[r[i]];
	}
	res += max(curU, curV);
	printf("%lld\n", res);

	return 0;
}