#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main() {
	int n, nint, prevday = 0;
	scanf("%d", &n);
	set<int> inoffice, beeninoffice;
	vector<int> daylengths;
	scanf("%d", &nint);
	if (nint < 0) {
		printf("-1");
		return 0;
	} else inoffice.insert(nint);
	for (int i = 1; i < n; ++i) {
		scanf("%d", &nint);
		if (nint > 0) {
			if (inoffice.find(nint) != inoffice.end()) {
				printf("-1");
				return 0;
			} else if (beeninoffice.find(nint) != beeninoffice.end()) {
				printf("-1");
				return 0;
			} else inoffice.insert(nint);
		} else {
			if (inoffice.find(-nint) == inoffice.end()) {
				printf("-1");
				return 0;
			} else {
				beeninoffice.insert(-nint);
				inoffice.erase(-nint);
			}
		}
		if (inoffice.empty()) {
			daylengths.push_back(i - prevday + 1);
			prevday = ++i;
			inoffice.clear();
			beeninoffice.clear();
			if (i != n) {
				scanf("%d", &nint);
				if (nint < 0) {
					printf("-1");
					return 0;
				} else inoffice.insert(nint);
			}
		}
	}
	if (prevday != n) printf("-1");
	else {
		printf("%lu\n", daylengths.size());
		for (int i: daylengths) printf("%d ", i);
	}
	return 0;
}