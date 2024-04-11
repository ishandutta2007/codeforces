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
vector<int> arr;
vector<char> good;

bool Good2(int a0, int a1) {
	if (a0 == 0) return a1 == 0;
	return true;
}

bool Good3(int a0, int a1, int a2) {
	bool res = Good2(a0, a1) && Good2(a1, a2);
	res &= (a1*a1 == a0*a2);
	return res;
}

int CheckVector(const vector<int> &arr) {
	int i;
	for (i = 0; i < arr.size(); i++) {
		if (i+1 < arr.size() && !Good2(arr[i], arr[i+1])) break;
		if (i+2 < arr.size() && !Good3(arr[i], arr[i+1], arr[i+2])) break;
	}
	return i;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i<n; i++) scanf("%d", &arr[i]);

	int i = CheckVector(arr);
	if (i == n) {
		printf("0\n");
		return 0;
	}

	for (int j = max(0, i-10); j<max(n, i+10); j++) {
		vector<int> diff;
		for (int u = 0; u<n; u++) {
			if (u != j) diff.push_back(arr[u]);
		}
		if (CheckVector(diff) == diff.size()) {
			printf("1\n");
			return 0;
		}
	}

	printf("2\n");
	return 0;
}