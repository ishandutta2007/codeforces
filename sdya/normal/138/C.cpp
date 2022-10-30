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

const int maxN = 110000;
int n, m, a[maxN], h[maxN], l[maxN], r[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &a[i], &h[i], &l[i], &r[i]);
	}

	vector < pair < pair < int, int >, int > > b(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &b[i].first.first, &b[i].first.second);
		b[i].second = i;
	}
	vector < long double > p(m, 0.0);
	vector < long double > v(m, 0.0);
	for (int i = 0; i < m; ++i) {
		v[i] = b[i].first.second;
	}

	vector < pair < int, int > > events;
	for (int i = 1; i <= n; ++i) {
		events.push_back(make_pair(a[i], i));
		events.push_back(make_pair(a[i] + h[i] + 1, -i));
	}

	sort(b.begin(), b.end()); 

	sort(events.begin(), events.end());
	int index = 0;
	long double q = 0.0;
	int zeroes = 0;
	for (int i = 0; i < m; ++i) {
		while (index < events.size() && events[index] <= make_pair(b[i].first.first, 0)) {
			int u = events[index].second;
			if (u > 0) {
				if (r[u] == 100) {
					++zeroes;
				} else {
					q += log((long double)(100 - r[u]) / 100.0);
				}
			} else {
				if (r[-u] == 100) {
					--zeroes;
				} else {
					q -= log((long double)(100 - r[-u]) / 100.0);
				}
			}
			++index;
		}
		p[b[i].second] += zeroes == 0 ? q : 1e20;
	}

	reverse(b.begin(), b.end());
	events.clear();
	for (int i = 1; i <= n; ++i) {
		events.push_back(make_pair(a[i], -i));
		events.push_back(make_pair(a[i] - h[i] - 1, i));
	}
	sort(events.rbegin(), events.rend());

	index = 0;
	q = 0.0;
	zeroes = 0;
	for (int i = 0; i < m; ++i) {
		while (index < events.size() && events[index] >= make_pair(b[i].first.first, 0)) {
			int u = events[index].second;
			if (u > 0) {
				if (l[u] == 100) {
					++zeroes;
				} else {
					q -= log((long double)(100 - l[u]) / 100.0);
				}
			} else {
				if (l[-u] == 100) {
					--zeroes;
				} else {
					q += log((long double)(100 - l[-u]) / 100.0);
				}
			}
			++index;
		}
		p[b[i].second] += (zeroes == 0 ? q : 1e20);
	}

	long double res = 0.0;
	for (int i = 0; i < m; ++i) {
		if (p[i] > 1e17) {
			continue;
		}
		res += exp(p[i]) * v[i];
	}

	printf("%.10lf\n", (double)(res));

	return 0;
}