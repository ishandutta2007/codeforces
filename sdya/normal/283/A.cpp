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

const int maxN = 210000;
double add[maxN];
double value[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	double s = 0.0;
	int n;
	scanf("%d", &n);
	int length = 1;
	for (int i = 1; i <= n; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int a, x;
			scanf("%d%d", &a, &x);
			add[a] += x;
			s += (double)(a) * (double)(x);
		} else if (t == 2) {
			int k;
			scanf("%d", &k);
			s += (double)(k);
			++length;
			value[length] = k;
		} else {
			s -= value[length];
			s -= add[length];
			add[length - 1] += add[length];
			value[length] = 0;
			add[length] = 0;
			--length;
		}
		printf("%.10lf\n", (double)(s) / (double)(length));
	}

	return 0;
}