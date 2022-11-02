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

	vector < long long > pw(19);
	pw[0] = 1;
	for (int i = 1; i < 19; ++i) {
		pw[i] = pw[i - 1] * 10LL;
	}

	long long w, m, k;
	cin >> w >> m >> k;
	w /= k;

	long long res = 0;
	for (int i = 1; i < 19; ++i) {
		if (pw[i] - 1 >= m) {
			long long cnt = pw[i] - m;
			long long need = (w / (long long)(i));
			long long q = min(cnt, need);
			res += q;
			w -= (long long)(i) * q;
			m = pw[i];
		}
	}

	cout << res << endl;


	return 0;
}