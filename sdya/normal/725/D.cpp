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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 310000;
pair < long long, long long > p[maxN];
int n;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%I64d%I64d", &p[i].first, &p[i].second);
	}

	sort(p + 1, p + n);

	long long total = 0;
	multiset < long long > tin, tout;
	int res = n;
	long long s = 0;

	long long t = p[0].first;
	p[n] = make_pair(2000000000000000000LL, 4000000000000000000LL);
	for (int i = n; i >= 1; --i) {
		if (p[i].first > t) {
			tout.insert(p[i].second - p[i].first + 1);
			while (i - 1 >= 1 && p[i - 1].first > t) {
				--i;
				tout.insert(p[i].second - p[i].first + 1);
			}
		} else {
			tout.insert(p[i].second - p[i].first + 1);
			while (i - 1 >= 1 && p[i - 1].first == p[i].first) {
				--i;
				tout.insert(p[i].second - p[i].first + 1);
			}
		}
		long long nt = (i - 1 == 0 ? 0 : (p[i - 1].first));
		total = t - nt;
		while (!tin.empty() && !tout.empty() && (*tin.rbegin()) > (*tout.begin())) {
			long long v1 = *tin.rbegin();
			tin.erase(tin.find(v1));

			long long v2 = *tout.begin();
			tout.erase(tout.find(v2));
			tin.insert(v2);
			tout.insert(v1);

			s -= v1;
			s += v2;
		}

		while (!tout.empty() && s + (*tout.begin()) <= total) {
			long long v = *tout.begin();
			tout.erase(tout.find(v));
			tin.insert(v);
			s += v;
		}

		res = min(res, (int)(tout.size()));
	}
	printf("%d\n", res);

	return 0;
}