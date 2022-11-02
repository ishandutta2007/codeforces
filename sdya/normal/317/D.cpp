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

int n;
set < int > S;

map < pair < int, int >, int > F;

int calc(int length, int mask) {
	if (mask == 0) {
		return 0;
	}
	if (F.count(make_pair(length, mask))) {
		return F[make_pair(length, mask)];
	}

	vector < int > d;
	for (int i = 1; i <= length; ++i) {
		if (mask & (1 << (i - 1))) {
			int nmask = mask;
			for (int j = i; j <= length; j += i) {
				if (nmask & (1 << (j - 1))) {
					nmask ^= (1 << (j - 1));
				}
			}
			d.push_back(calc(length, nmask));
		}
	}
	sort(d.begin(), d.end());
	for (int i = 0; ; ++i) {
		if (!binary_search(d.begin(), d.end(), i)) {
			return F[make_pair(length, mask)] = i;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	vector < int > a(30);
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 1;
	a[4] = 4;
	a[5] = 3;
	a[6] = 2;
	a[7] = 1;
	a[8] = 5;
	a[9] = 6;
	a[10] = 2;
	a[11] = 1;
	a[12] = 8;
	a[13] = 7;
	a[14] = 5;
	a[15] = 9;
	a[16] = 8;
	a[17] = 7;
	a[18] = 3;
	a[19] = 4;
	a[20] = 7;
	a[21] = 4;
	a[22] = 2;
	a[23] = 1;
	a[24] = 10;
	a[25] = 9;
	a[26] = 3;
	a[27] = 6;
	a[28] = 11;
	a[29] = 12;

	cin >> n;
	vector < int > length;
	for (int i = 2; i * i <= n; ++i) {
		long long w = i;
		if (S.count(w)) {
			continue;
		}
		int q = 0;
		while (w <= (long long)(n)) {
			++q;
			S.insert(w);
			w *= (long long)(i);
		}
		length.push_back(q);
	}

	/*for (int i = 0; i < 30; ++i) {
		printf("a[%d] = %d;\n", i, calc(i, (1 << i) - 1));
		cerr << i << endl;
	}*/

	int ones = n - S.size();
	int res = 0;
	for (int i = 0; i < length.size(); ++i) {
		int value = a[length[i]];
		res ^= value;
	}
	if (ones % 2 == 1) {
		res ^= 1;
	}
	if (res == 0) {
		cout << "Petya" << endl;
	} else {
		cout << "Vasya" << endl;
	}

	return 0;
}