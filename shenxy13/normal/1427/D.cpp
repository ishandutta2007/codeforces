#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, a[52];
void repartition(vector<int> &x) {
	int na[n];
	int ptr = n, pfx = 0;
	for (int i: x) {
		ptr -= i;
		for (int j = 0; j < i; ++j) na[ptr + j] = a[pfx + j];
		pfx += i;
	}
	for (int i = 0; i < n; ++i) a[i] = na[i];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	vector< vector<int> > sol;
	for (int i = 0; i < n - 1; ++i) {
		vector<int> ops;
		if (i % 2) {
			int j = 0;
			while (a[j] != i + 1) ++j;
			if (j != 0) ops.push_back(j);
			ops.push_back(n - i - j);
			for (int j = 0; j < i; ++j) ops.push_back(1);
		} else {
			for (int j = 0; j < i; ++j) ops.push_back(1);
			int j = i;
			while (a[j] != i + 1) ++j;
			ops.push_back(j - i + 1);
			if (j != n - 1) ops.push_back(n - j - 1);
		}
		if (ops.size() == 1) continue;
		repartition(ops);
		sol.push_back(ops);
	}
	if (n % 2 == 0) {
		vector<int> ops;
		for (int i = 0; i < n; ++i) ops.push_back(1);
		repartition(ops);
		sol.push_back(ops);
	}
	printf("%lu\n", sol.size());
	for (vector<int> &i: sol) {
		printf("%lu", i.size());
		for (int j: i) printf(" %d", j);
		printf("\n");
	}
	return 0;
}