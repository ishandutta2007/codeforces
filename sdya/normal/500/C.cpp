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

const int maxN = 1100;
int n, m;
int a[maxN], b[maxN];
bool used[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}

	int value = 0;
	for (int i = 1; i <= m; ++i) {
		memset(used, 0, sizeof(used));
		int last = 1;
		for (int j = i - 1; j >= 1; --j) {
			if (b[j] == b[i]) {
				last = j + 1;
				break;
			}
		}

		for (int j = last; j < i; ++j) {
			used[b[j]] = true;
		}
		for (int j = 1; j <= n; ++j) {
			if (used[j]) {
				value += a[j];
			}
		}
	}
	cout << value << endl;
	
	return 0;
}