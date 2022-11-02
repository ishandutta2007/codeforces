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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector < int > a(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	double res = 0;
	for (int i = n; i >= 1; i -= 2) {
		res += pow((double)(a[i]), 2.0) - pow((double)(a[i - 1]), 2.0);
	}
	res *= 2.0 * acos(0.0);
	printf("%.10lf\n", res);


	return 0;
}