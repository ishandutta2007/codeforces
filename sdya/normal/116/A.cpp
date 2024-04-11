#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	int res = 0;
	cin >> n;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		cur -= a;
		cur += b;
		res = max(res, cur);
	}
	cout << res << endl;
	return 0;
}