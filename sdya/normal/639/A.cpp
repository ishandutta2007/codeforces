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

	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);
	vector < int > t(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t[i]);
	}
	set < pair < int, int > > S;
	for (int i = 0; i < q; ++i) {
		int mode, id;
		scanf("%d%d", &mode, &id);
		--id;
		if (mode == 1) {
			S.insert(make_pair(-t[id], id));
			if (S.size() > k) {
				pair < int, int > buf = *S.rbegin();
				S.erase(buf);
			}
		} else {
			if (S.count(make_pair(-t[id], id))) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}

	return 0;
}