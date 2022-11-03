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

const int SIZE = 100<<10;

int n;
int pa[SIZE], pb[SIZE];
int ra[SIZE], rb[SIZE];
int zerolvl;
int arr[SIZE];
map<int, int> vals;

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i<n; i++) { scanf("%d", &pa[i]);  pa[i]--; }
	for (int i = 0; i<n; i++) { scanf("%d", &pb[i]);  pb[i]--; }
	for (int i = 0; i<n; i++) ra[pa[i]] = i;
	for (int i = 0; i<n; i++) rb[pb[i]] = i;

	for (int i = 0; i<n; i++) {
		arr[i] = rb[i] - ra[i];
		vals[arr[i]]++;
	}
	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<n; j++) printf("%d ", arr[j] - zerolvl); printf("\n");
//		for (multiset<int>::iterator iter = vals.begin(); iter != vals.end(); iter++) printf("%d ", *iter); printf("\n");

		map<int, int>::iterator iter = vals.lower_bound(zerolvl);

		int q[2], qk = 0;
		if (iter != vals.end())
			q[qk++] = iter->first;
		if (iter != vals.begin()) {
			iter--;
			q[qk++] = iter->first;
		}

		int res = 100000000;
		for (int t = 0; t<qk; t++) {
			int d = q[t] - zerolvl;
			if (d < 0) d = -d;
			res = min(res, d);
		}
		printf("%d\n", res);

		zerolvl++;
		int mv = pb[i];

		vals[arr[mv]]--;
		if (vals[arr[mv]] == 0) vals.erase(arr[mv]);
			arr[mv] += n;
		vals[arr[mv]]++;
	}

	return 0;
}