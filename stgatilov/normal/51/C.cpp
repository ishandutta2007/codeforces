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

int n;
vector<int64> arr;
int64 ctr[3];

bool Good(int64 middle) {
	int curr = 0;
	memset(ctr, 0, sizeof(ctr));
	for (int i = 0; i<3; i++) {
		ctr[i] = arr[curr] + middle;
		int64 cover = ctr[i] + middle;
		while (arr[curr] <= cover) curr++;
		if (curr == n) break;
	}
	return curr == n;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i<n; i++) {
		scanf("%I64d", &arr[i]);
		arr[i] *= 2;
	}
	sort(arr.begin(), arr.end());
	arr.push_back(1000000000000LL);

	int64 left = -1;
	int64 right = 10000000000LL;
	int64 middle;
	while (right - left > 1) {
		middle = (left + right) >> 1;
		if (Good(middle)) right = middle;
		else left = middle;
	}

	assert(Good(right));
	printf("%0.6lf\n", right / 2.0);
	printf("%0.6lf %0.6lf %0.6lf\n", ctr[0]/2.0, ctr[1]/2.0, ctr[2]/2.0);
	return 0;
}