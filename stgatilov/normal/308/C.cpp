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
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 1<<20;
const int LOGX = 30;

int n, m;
int arr[SIZE], need[SIZE];
int64 blocks[LOGX+1];
int64 blHas[LOGX+1], blWant[LOGX+1];

bool Solve(int pref) {
	memcpy(blHas, blocks, sizeof(blocks));
	memset(blWant, 0, sizeof(blWant));
	for (int i = 0; i<pref; i++)
		blWant[need[i]]++;

	for (int i = LOGX; i>=0; i--) {
		if (blWant[i] > blHas[i])
			return false;
		blHas[i] -= blWant[i];
		if (i) blHas[i-1] += blHas[i]<<1;
	}

	return true;
}

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i<m; i++) scanf("%d", &need[i]);

	sort(need, need+m);

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<=LOGX; j++)
			if (arr[i] & (1<<j))
				blocks[j]++;
	}

	int left = 0;
	int right = m+1;
	while (right - left > 1) {
		int middle = (left + right) >> 1;
		if (Solve(middle))
			left = middle;
		else
			right = middle;
	}

	printf("%d\n", left);

	return 0;
}