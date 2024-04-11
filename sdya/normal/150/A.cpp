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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long q;
	cin >> q;
	int cnt = 0;
	long long p = q;
	vector < pair < long long, int > > a;
	for (long long i = 2; i * i <= p; ++i) {
		int t = 0;
		while (q % i == 0) {
			++cnt;
			++t;
			q /= i;
		}
		if (t > 0) {
			a.push_back(make_pair(i, t));
		}
	}
	if (q != 1) {
		++cnt;
		a.push_back(make_pair(q, 1));
	}

	if (cnt > 2) {
		long long s = a[0].first;
		if (a[0].second > 1) {
			s *= s;
		} else {
			s *= a[1].first;
		}

		cout << 1 << endl;
		cout << s << endl;
	} else if (cnt <= 1) {
		cout << 1 << endl;
		cout << 0 << endl;
	} else {
		cout << 2 << endl;
	}

	return 0;
}