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

const int maxN = 5000;
int n;
int v[maxN], d[maxN], p[maxN];

void postprocess(deque < int > &order) {
	while (!order.empty()) {
		int index = -1;
		for (int i = 0; i < order.size(); ++i) {
			if (p[order[i]] < 0) {
				index = i;
				break;
			}
		}
		if (index == -1) {
			break;
		}

		for (int i = index + 1; i < order.size(); ++i) {
			p[order[i]] = max(p[order[i]] - d[order[index]], -1);
		}

		deque < int > norder;
		for (int i = 0; i < order.size(); ++i) {
			if (i != index) {
				norder.push_back(order[i]);
			}
		}
		order = norder;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &v[i], &d[i], &p[i]);
	}

	deque < int > order;
	for (int i = 0; i < n; ++i) {
		order.push_back(i);
	}

	vector < int > res;
	while (order.size() > 0) {
		int index = order[0];
		res.push_back(index + 1);
		order.pop_front();
		
		for (int i = 0, j = v[index]; i < order.size() && j > 0; ++i, --j) {
			int id = order[i];
			p[id] = max(p[id] - j, -1);
		}

		postprocess(order);
	}

	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		printf("%d ", res[i]);
	}
	printf("\n");


	return 0;
}