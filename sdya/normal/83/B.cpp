#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
long long n, k;
long long a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> k;
	long long s = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s += a[i];
	}
	if (s < k) {
		cout << -1 << endl;
		return 0;
	}

	set < pair < long long, long long > > S;
	for (int i = 0; i < n; ++i) {
		S.insert(make_pair(a[i], i));
	}
	long long diff = 0;
	vector < int > order(n, true);
	while (!S.empty()) {
		long long x = S.begin()->first;
		if (x == diff) {
			order[S.begin()->second] = false;
			S.erase(S.begin());
			continue;
		}
		if (x == 0) {
			order[S.begin()->second] = false;
			S.erase(S.begin());
			continue;
		}
		long long t = k / (long long)(S.size());
		t = min(t, a[S.begin()->second] - diff);
		if (t > 0) {
			k -= t * (long long)(S.size());
			diff += t;
		} else {
			break;
		}
	}

	deque < int > q;
	for (int i = 0; i < n; ++i) {
		if (order[i]) {
			q.push_back(i);
		}
	}

	for (int i = 0; i < n; ++i) {
		a[i] -= diff;
	}

	while (k > 0) {
		int index = q.front();
		--a[index];
		if (a[index] > 0) {
			q.push_back(index);
		}
		q.pop_front();
		--k;
	}

	while (!q.empty()) {
		printf("%d ", q.front() + 1);
		q.pop_front();
	}
	printf("\n");
	
	return 0;
}