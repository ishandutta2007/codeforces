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
int n;
int a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	vector < pair < int, int > > b;
	b.push_back(make_pair(a[0], 1));
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i - 1]) {
			++b.back().second;
		} else {
			b.push_back(make_pair(a[i], 1));
		}
	}
	long long res = 0;
	for (int i = 0; i < b.size(); ++i) {
		long long cnt = b[i].second;
		res += (cnt * (cnt + 1));
	}
	cout << res / 2LL << endl;
	
	return 0;
}