#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

const int maxN = 110000;

int n;
int a[maxN];

multiset < int > S;
vector < vector < int > > res;

set < pair < int, int > > A;

map < int, int > M;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), M[a[i]] ++;

	int sz = 0;
	for (map < int, int > :: iterator it = M.begin(); it != M.end(); ++it) {
		A.insert(make_pair(-it->second, -it->first));
		++ sz;
	}


	while (sz >= 3) {
		pair < int, int > x = * A.begin(); A.erase(A.begin());
		pair < int, int > y = * A.begin(); A.erase(A.begin());
		pair < int, int > z = * A.begin(); A.erase(A.begin());
		sz -= 3;

		vector < int > buf;
		buf.push_back(-x.second);
		buf.push_back(-y.second);
		buf.push_back(-z.second);
		res.push_back(buf);

		if (x.first + 1 != 0) A.insert(make_pair(x.first + 1, x.second)), sz ++;
		if (y.first + 1 != 0) A.insert(make_pair(y.first + 1, y.second)), sz ++;
		if (z.first + 1 != 0) A.insert(make_pair(z.first + 1, z.second)), sz ++;
	}

	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		sort(res[i].rbegin(), res[i].rend());
		for (int j = 0; j < res[i].size(); ++j)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return 0;
}