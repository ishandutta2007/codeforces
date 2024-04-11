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
int n;
int g[maxN], p[maxN];
set < pair < int, int > > s[maxN];
int d[maxN], od[maxN];

void update(int v) {
	if (p[v] == 0) {
		return ;
	}
	s[p[v]].erase(make_pair(od[v], v));
	s[p[v]].insert(make_pair(d[v], v));
	set < pair < int, int > > ::reverse_iterator it = s[p[v]].rbegin();
	int v1 = it->first;
	++it;
	int v2 = -1;
	if (it != s[p[v]].rend()) {
		v2 = it->first;
	}
	od[p[v]] = d[p[v]];
	if (p[v] == 1) {
		d[p[v]] = max(v1, v2);
	} else {
		d[p[v]] = max(v2 + 1, v1);
	}
	if (d[p[v]] != od[p[v]]) {
		update(p[v]);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	d[1] = 0;
	for (int i = 2; i <= n + 1; ++i) {
		scanf("%d", &p[i]);
		d[i] = 0;
		update(i);
		printf("%d ", d[1] + 1);
	}
	printf("\n");



	return 0;
}