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

const int SIZE = 20<<10;

int n;
int arr[SIZE], rleft[SIZE];
int next[SIZE], len[SIZE];

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		scanf("%d", &arr[i + n]);

	int64 ans = 0;
	for (int i = n; i>0; i--) {
//		E(!);

		int vis = n+i-1;
		len[n+i-1] = 0;
		for (int j = n+i-1; j>=i; j--) {
			rleft[j] = j - arr[j];
			int ll = max(rleft[j], i);
			ll = min(vis, ll);
			for (int u = ll; u<vis; u++) {
				next[u] = j;
				len[u] = len[j] + 1;
			}
			vis = ll;
		}
//		for (int j = 0; j < n+i; j++) printf("%d ", next[j]); printf("\n");

		ans += len[i];
		arr[i-1] = arr[i+n-1];
	}

	printf("%I64d", ans);
	return 0;
}