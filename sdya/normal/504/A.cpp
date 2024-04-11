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

const int maxN = 110000;
int n;
int d[maxN], s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	set < pair < int, int > > S;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &d[i], &s[i]);
		S.insert(make_pair(d[i], i));
	}

	vector < pair < int, int > > edges;
	while (!S.empty()) {
		pair < int, int > p = *S.begin();
		S.erase(S.begin());
		if (p.first == 0) {
			continue;
		}

		int u = p.second;
		int v = s[u];
		edges.push_back(make_pair(u, v));
		S.erase(make_pair(d[v], v));
		--d[v];
		s[v] ^= u;
		S.insert(make_pair(d[v], v));
	}

	printf("%d\n", edges.size());
	for (int i = 0; i < edges.size(); ++i) {
		printf("%d %d\n", edges[i].first, edges[i].second);
	}


	return 0;
}