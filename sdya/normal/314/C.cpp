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

const long long P = 1000000007LL;
const int maxN = 110000;
int n;
int a[maxN];

long long t[maxN];

void update(int k, long long delta) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		t[i] = (t[i] + delta) % P;
	}
}

long long get(int k) {
	long long res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
		res %= P;
	}
	return res;
}

long long get(int l, int r) {
	long long res = get(r) - get(l - 1);
	if (res < 0) {
		res += P;
	}
	return res;
}

const int maxL = 1100000;
int used[maxL];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	vector < pair < int, int > > p;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		p.push_back(make_pair(a[i], i));
	}

	sort(p.begin(), p.end());
	update(0, 1);
	for (int i = 0; i < p.size(); ++i) {
		int position = p[i].second;
		int value = p[i].first;
		long long score = (get(used[value], position - 1) * (long long)(value)) % P;
		update(position, score);
		used[value] = position;
	}

	long long res = get(1, n);
	printf("%d\n", (int)(res));


	return 0;
}