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

int n;
int64 ans;
int root[SIZE];
int cnt[10];

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i = 0; i<10; i++) root[i] = i;
	for (int i = 10; i<SIZE; i++) {
		char buff[16];
		sprintf(buff, "%d", i);
		int s = 0;
		for (int j = 0; buff[j]; j++) s += buff[j] - '0';
		root[i] = root[s];
	}

	scanf("%d", &n);

	for (int i = 1; i<=n; i++) cnt[root[i]]++;

	for (int i = 0; i<10; i++)
		for (int j = 0; j<10; j++)
			for (int u = 0; u<10; u++)
				if (root[i*j] == u)
					ans += int64(cnt[i]) * cnt[j] * cnt[u];
//	printf("%I64d\n", ans);

	for (int i = 1; i<=n; i++)
		for (int j = 1; i*j<=n; j++)
			ans--;

	printf("%I64d\n", ans);

	return 0;
}