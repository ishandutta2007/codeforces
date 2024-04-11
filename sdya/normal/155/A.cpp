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
	int A = 0, B = 0;
	cin >> A;
	B = A;
	int res = 0;
	for (int i = 1; i < n; ++i) {
		int a;
		cin >> a;
		if (a > A) {
			++res;
		}
		if (a < B) {
			++res;
		}
		A = max(a, A);
		B = min(a, B);
	}
	cout << res << endl;


	return 0;
}