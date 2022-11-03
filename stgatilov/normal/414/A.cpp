#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

int n, k;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &k);
	int p = n / 2;

	if (k < p) {
		printf("-1\n");
		return 0;
	}
	if (p == 0) {
		if (k == 0)
			printf("1\n");
		else
			printf("-1\n");
		return 0;
	}

	int g[2];
	int c[2];
	g[0] = k / p;
	g[1] = g[0] + 1;
	c[1] = k % p;
	c[0] = p - c[1];

	set<int> used;
	vector<int> arr;
	for (int q = 0; q<2; q++) {
		int curr = 1;
		for (int i = 0; i < c[q]; i++) {
			while (used.count(curr * g[q]) || used.count((curr+1) * g[q]))
				curr++;
			arr.push_back(curr * g[q]);
			arr.push_back((curr+1) * g[q]);
			used.insert(curr * g[q]);
			used.insert((curr+1) * g[q]);
			curr += 2;
		}
	}

	if (arr.size() < n) {
		int r;
		for (r = 1; used.count(r); r++);
		arr.push_back(r);
	}

	for (int i = 0; i<n; i++) printf("%d ", arr[i]);


	return 0;
}