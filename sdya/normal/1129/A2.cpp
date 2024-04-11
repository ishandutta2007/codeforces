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

const int maxN = 21000;
int n, m, a[maxN], b[maxN];
vector < int > c[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
	    cin >> a[i] >> b[i];
	    if (b[i] > a[i]) {
	        c[a[i]].push_back(b[i] - a[i]);
	    } else {
	        c[a[i]].push_back(n + b[i] - a[i]);
	    }
	}
	for (int i = 1; i <= n; ++i) {
	    sort(c[i].begin(), c[i].end());
	}
	for (int i = 1; i <= n; ++i) {
	    int res = 0;
	    for (int j = i; j < n + i; ++j) {
	        int k = j;
	        if (k > n) {
	            k -= n;
	        }
	        if (c[k].empty()) {
	            continue;
	        }
	        int m = c[k].size();
	        res = max(res, j - i + n * (m - 1) + c[k][0]);
	    }
	    printf("%d ", res);
	}
	printf("\n");

	return 0;
}