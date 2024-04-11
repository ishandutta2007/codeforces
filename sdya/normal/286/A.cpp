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

const int maxN = 110000;
int p[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	int m = n % 4;
	if (m == 2 || m == 3) {
		printf("-1\n");
		return 0;
	}

	vector < int > a;
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
	}
	for (int i = 1, j = n; i < j; ++i, --j) {
		a.push_back(i);
		a.push_back(j);
		if (a.size() == 4) {
			swap(a[1], a[2]);
			for (int j = 0; j < 4; ++j) {
				p[a[j]] = a[(j + 1) % 4];
			}
			a.clear();
		}
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d ", p[i]);
	}
	printf("\n");

	

	return 0;
}