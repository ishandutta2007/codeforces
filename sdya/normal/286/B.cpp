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

const int maxN = 3100000;
int p[maxN];
int v[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	int add = 0;
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
	}
	for (int i = 2; i <= n; ++i) {
		++add;
		int m = 0;
		for (int j = 1; j <= n; j += i) {
			v[m ++] = p[j + add - 1];
		}
		m = 0;
		for (int j = 1; j <= n; j += i) {
			int npos = min(n, j + i - 1);
			p[npos + add] = v[m++];
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", p[add + i]);
	}
	printf("\n");

	//cerr << clock() << endl;


	return 0;
}