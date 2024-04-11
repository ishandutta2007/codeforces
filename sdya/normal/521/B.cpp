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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

map < pair < int, int >, int > M;
set < pair < int, int > > H;
const int maxN = 110000;
const long long P = 1000000009LL;
int n;
int x[maxN], y[maxN];
int p[maxN], q[maxN];

void calculate(int i) {
	p[i] = 0;
	q[i] = 0;
	if (y[i] == 0) {
		p[i] = 3;
	} else {
		for (int j = x[i] - 1; j <= x[i] + 1; ++j) {
			if (H.count(make_pair(j, y[i] - 1))) {
				++p[i];
			}
		}
	}

	for (int j = x[i] - 1; j <= x[i] + 1; ++j) {
		if (H.count(make_pair(j, y[i] + 1))) {
			++q[i];
		}
	}
}

bool canDelete(int id) {
	for (int i = x[id] - 1; i <= x[id] + 1; ++i) {
		if (H.count(make_pair(i, y[id] + 1))) {
			int j = M[make_pair(i, y[id] + 1)];
			if (p[j] == 1) {
				return false;
			}
		}
	}
	return true;
}

set < int > canBeDeleted;

void deleteCube(int id) {
	H.erase(make_pair(x[id], y[id]));
	canBeDeleted.erase(id);
	vector < int > ids;
	for (int i = -2; i <= 2; ++i) {
		for (int j = -2; j <= 2; ++j) {
			if (H.count(make_pair(x[id] + i, y[id] + j))) {
				int nx = x[id] + i;
				int ny = y[id] + j;
				int k = M[make_pair(nx, ny)];
				canBeDeleted.erase(k);
				calculate(k);
				ids.push_back(k);
			}
		}
	}

	for (int i = 0; i < ids.size(); ++i) {
		if (canDelete(ids[i])) {
			canBeDeleted.insert(ids[i]);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		H.insert(make_pair(x[i], y[i]));
		M[make_pair(x[i], y[i])] = i;
	}

	for (int i = 0; i < n; ++i) {
		calculate(i);
	}

	for (int i = 0; i < n; ++i) {
		if (canDelete(i)) {
			canBeDeleted.insert(i);
		}
	}

	int move = 0;
	long long res = 0;
	long long m = n;
	while (n > 0) {
		int id;
		if (move == 0) {
			id = *canBeDeleted.rbegin();
		} else {
			id = *canBeDeleted.begin();
		}
		deleteCube(id);
		res = res * (long long)(m) + (long long)(id);
		res %= P;
		move = 1 - move;
		--n;
	}

	printf("%d\n", (int)(res));


	return 0;
}