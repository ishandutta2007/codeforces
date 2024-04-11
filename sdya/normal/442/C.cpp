#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
int n, a[maxN];
/*int d[maxN][maxN];

int calc(int l, int r) {
	if (d[l][r] != -1) {
		return d[l][r];
	}
	if (l + 1 == r) {
		return d[l][r] = 0;
	}

	int res = 0;
	for (int k = l + 1; k < r; ++k) {
		res = max(res, calc(l, k) + calc(k, r));
	}
	return d[l][r] = res + min(a[l], a[r]);
}

vector < int > order;

void restore(int l, int r) {
	if (l + 1 == r) {
		return;
	}

	for (int k = l + 1; k < r; ++k) {
		if (d[l][r] - min(a[l], a[r]) == d[l][k] + d[k][r]) {
			order.push_back(k);
			restore(l, k);
			restore(k, r);
			return;
		}
	}
}*/

long long clever2() {
	list < int > values;
	for (int i = 0; i < n; ++i) {
		values.push_back(a[i]);
	}

	list < int > ::iterator it = values.begin();
	long long res = 0;
	while (it != values.end()) {
		if (it == values.begin()) {
			++it;
			continue;
		}
		list < int > ::iterator lt = it, rt = it;
		--lt;
		++rt;
		if (rt == values.end()) {
			break;
		}

		if (*it <= min(*lt, *rt)) {
			res += min(*lt, *rt);
			it = values.erase(it);
			if (it != values.begin()) {
				--it;
			}
		} else {
			++it;
		}
	}

	vector < int > b;
	for (list < int > ::iterator it = values.begin(); it != values.end(); ++it) {
		b.push_back(*it);
	}

	int l = 0, r = b.size() - 1;
	while (l + 1 < r) {
		res += min(b[l], b[r]);
		if (b[l] < b[r]) {
			++l;
		} else {
			--r;
		}
	}
	return res;
}

long long clever() {
	long long res = 0;
	set < pair < int, int > > S;
	vector < int > d(n, 0);
	set < int > order;
	order.insert(0);
	for (int i = 1; i + 1 < n; ++i) {
		S.insert(make_pair(a[i] - min(a[i - 1], a[i + 1]), i));
		d[i] = a[i] - min(a[i - 1], a[i + 1]);
		order.insert(i);
	}
	order.insert(n - 1);

	while (!S.empty() && S.begin()->first <= 0) {
		pair < int, int > current = *S.begin();
		S.erase(S.begin());

		set < int > ::iterator it = order.find(current.second);
		set < int > ::iterator lt = it, rt = it;
		--lt;
		int left = *lt;
		int L = -1;
		if (lt != order.begin()) {
			--lt;
			L = *lt;
		}
		++rt;
		int right = *rt;
		++rt;
		int R = -1;
		if (rt != order.end()) {
			R = *rt;
		}
		order.erase(it);

		res += -current.first + a[current.second];

		if (L != -1) {
			S.erase(make_pair(d[left], left));
			d[left] = a[left] - min(a[L], a[right]);
			if (d[left] <= 0) {
				S.insert(make_pair(d[left], left));
			}
		}
		if (R != -1) {
			S.erase(make_pair(d[right], right));
			d[right] = a[right] - min(a[left], a[R]);
			if (d[right] <= 0) {
				S.insert(make_pair(d[right], right));
			}
		}
	}


	vector < int > b;
	for (set < int > ::iterator it = order.begin(); it != order.end(); ++it) {
		b.push_back(a[*it]);
	}

	int l = 0, r = b.size() - 1;
	while (l + 1 < r) {
		res += min(b[l], b[r]);
		if (b[l] < b[r]) {
			++l;
		} else {
			--r;
		}
	}
	return res;
}

void gen(int v = 500000) {
	//n = rand() % 5 + 2;
	n = v;
	for (int i = 0; i < n; ++i) {
		a[i] = rand();
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	/*gen();
	clever();
	cerr << clock() << endl;
	return 0;*/

	/*int tests = 0;
	while (true) {
		++tests;
		cerr << tests << endl;
		memset(d, -1, sizeof(d));
		gen();
		if (calc(0, n - 1) != clever()) {
			cerr << "BAD" << endl;
			clever();
			return 0;
		}
	}*/

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	/*memset(d, -1, sizeof(d));
	int res = calc(0, n - 1);
	printf("%d\n", res);*/
	cout << clever2() << endl;
	/*restore(0, n - 1);

	vector < bool > used(n);
	used[0] = used[n - 1] = true;

	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			printf("[%d] ", a[i]);
		} else {
			printf("%d ", a[i]);
		}
	}
	printf("\n");

	for (int i = 0; i < order.size(); ++i) {
		used[order[i]] = true;
		for (int j = 0; j < n; ++j) {
			if (used[j]) {
				printf("[%d] ", a[j]);
			} else {
				printf("%d ", a[j]);
			}
		}
		printf("\n");
	}*/

	return 0;
}