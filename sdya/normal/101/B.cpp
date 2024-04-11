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

const int maxN = 210000;
const long long P = 1000000007LL;
int n, m;
pair < int, int > a[maxN];

bool comp(pair < int, int > a, pair < int, int > b) {
	return a.second < b.second;
}

long long t[maxN];

void update(int k, long long delta) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		t[i] = (t[i] + delta) % P;
	}
}

long long get(int k) {
	long long res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res = (res + t[i]) % P;
	}
	return res;
}

long long get(int l, int r) {
	if (l > r) {
		return 0;
	}
	return get(r) - get(l - 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	vector < int > p;
	p.push_back(0);
	p.push_back(n);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a[i].first, &a[i].second);
		p.push_back(a[i].first);
		p.push_back(a[i].second);
	}
	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());
	for (int i = 0; i < m; ++i) {
		a[i].first = lower_bound(p.begin(), p.end(), a[i].first) - p.begin();
		a[i].second = lower_bound(p.begin(), p.end(), a[i].second) - p.begin();
		++a[i].first;
		++a[i].second;
	}
	sort(a, a + m, comp);

	update(1, 1);
	for (int i = 0; i < m; ++i) {
		long long ways = get(a[i].first, a[i].second - 1);
		update(a[i].second, ways);
	}

	int end = lower_bound(p.begin(), p.end(), n) - p.begin();
	++end;
	long long res = get(end, end);
	res = ((res % P) + P) % P;
	cout << res << endl;
	
	return 0;
}