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

typedef pair<int, int> pii;

int n, a, b;
pii arr[1<<20];
int ans[1<<20];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i<n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}

	if (a == b) {
		for (int i = 0; i<n; i++) ans[i] = 2;
		for (int i = 0; i<a; i++) ans[i] = 1;
	}
	else if (a < b) {
		for (int i = 0; i<n; i++) arr[i].first = -arr[i].first;
		std::sort(arr, arr+n);
		for (int i = 0; i<n; i++) arr[i].first = -arr[i].first;

		for (int i = 0; i<n; i++) ans[i] = 2;
		for (int i = 0; i<a; i++) ans[arr[i].second] = 1;
	}
	else if (a > b) {
		std::sort(arr, arr+n);

		for (int i = 0; i<n; i++) ans[i] = 2;
		for (int i = 0; i<a; i++) ans[arr[i].second] = 1;
	}

	for (int i = 0; i<n; i++) printf("%d ", ans[i]);
	return 0;
}