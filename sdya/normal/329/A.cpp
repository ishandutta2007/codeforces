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

const int maxN = 110;
int n;
string s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	vector < pair < int, int > > res;
	{
		res.clear();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (s[i][j] != 'E') {
					res.push_back(make_pair(i + 1, j + 1));
					break;
				}
			}
		}
		if (res.size() == n) {
			for (int i = 0; i < n; ++i) {
				printf("%d %d\n", res[i].first, res[i].second);
			}
			return 0;
		}
	}
	{
		res.clear();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (s[j][i] != 'E') {
					res.push_back(make_pair(j + 1, i + 1));
					break;
				}
			}
		}
		if (res.size() == n) {
			for (int i = 0; i < n; ++i) {
				printf("%d %d\n", res[i].first, res[i].second);
			}
			return 0;
		}
	}

	printf("-1\n");

	return 0;
}