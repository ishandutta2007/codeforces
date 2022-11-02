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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
int a[maxN];
int p[maxN];
int q[maxN];
int n, m;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int x;
		scanf("%d", &x);
		p[x] = -1;
	}

	vector < pair < int, int > > values;
	for (int i = 1; i <= n; ++i) {
		if (p[i] == -1) {
			q[i] = -a[i];
			bool ok = false;
			vector < pair < int, int > > temp;
			while (values.size() > 0) {
				if (values.back().first == a[i] && temp.size() == 0) {
					values.pop_back();
					ok = true;
					break;
				} else {
					int value = values.back().first;
					if (temp.size() > 0 && temp.back().first == value) {
						q[temp.back().second] = -temp.back().first;
						temp.pop_back();
						values.pop_back();
					} else {
						temp.push_back(values.back());
						values.pop_back();
					}
				}
			}
			if (!ok) {
				printf("NO\n");
				return 0;
			}
		} else {
			q[i] = a[i];
			values.push_back(make_pair(a[i], i));
		}
	}

	vector < pair < int, int > > temp;
	while (values.size() > 0) {
		int value = values.back().first;
		if (temp.size() > 0 && temp.back().first == value) {
			q[temp.back().second] = -temp.back().first;
			temp.pop_back();
			values.pop_back();
		} else {
			temp.push_back(values.back());
			values.pop_back();
		}
	}
	if (temp.size() > 0) {
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", q[i]);
	}
	printf("\n");


	return 0;
}