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

const int maxN = 4050;
int n, p;
int c[maxN], h[maxN], t[maxN];
vector < pair < int, int > > order;

int a[5 * maxN], b[5 * maxN], res[5 * maxN];
vector < pair < int, int > > queries;

vector < int > sa;
int da[maxN][maxN], aSize;
vector < int > sb;
int db[maxN][maxN], bSize;

void addElement(int index) {
	sa.push_back(index);
	int cost = c[index];
	int happy = h[index];

	++aSize;
	for (int i = 0; i < maxN; ++i) {
		da[aSize][i] = da[aSize - 1][i];
		if (i > 0) {
			da[aSize][i] = max(da[aSize][i], da[aSize][i - 1]);
		}
		if (i >= cost) {
			da[aSize][i] = max(da[aSize][i], da[aSize - 1][i - cost] + happy);
		}
	}
}

void removeElement() {
	if (bSize > 0) {
		--bSize;
		sb.pop_back();
		return;
	}

	sb = sa;
	sa.clear();
	aSize = 0;
	reverse(sb.begin(), sb.end());
	sb.pop_back();
	bSize = sb.size();

	memset(db[0], 0, sizeof(db[0]));
	for (int i = 1; i <= bSize; ++i) {
		int cost = c[sb[i - 1]];
		int happy = h[sb[i - 1]];
		memset(db[i], 0, sizeof(db[i]));
		for (int j = 0; j < maxN; ++j) {
			db[i][j] = db[i - 1][j];
			if (j > 0) {
				db[i][j] = max(db[i][j], db[i][j - 1]);
			}
			if (j >= cost) {
				db[i][j] = max(db[i][j], db[i - 1][j - cost] + happy);
			}
		}
	}
}

int getValue(int budget) {
	int res = 0;
	for (int i = 0; i <= budget; ++i) {
		res = max(res, da[aSize][i] + db[bSize][budget - i]);
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &c[i], &h[i], &t[i]);
		order.push_back(make_pair(t[i], i));
	}
	sort(order.begin(), order.end());

	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		queries.push_back(make_pair(a[i], i));
	}
	sort(queries.begin(), queries.end());

	int start = 0, end = 0;
	int index = 0;
	for (int timestamp = 0; timestamp <= 20000; ++timestamp) {
		while (end < order.size() && order[end].first <= timestamp) {
			addElement(order[end].second);
			++end;
		}

		while (start < end && order[start].first + p <= timestamp) {
			removeElement();
			++start;
		}

		while (index < queries.size() && queries[index].first == timestamp) {
			res[queries[index].second] = getValue(b[queries[index].second]);
			++index;
		}
	}

	for (int i = 1; i <= q; ++i) {
		printf("%d\n", res[i]);
	}
	
	return 0;
}