#include <cstdio>
#include <map>
#include <set>

using namespace std;

const int MAXN = 100100;

int ar[MAXN];

map<int, int> dupcnts;
set<int> singles;

void insert(int x) {
	int &d = dupcnts[x];
	if (singles.find(x) != singles.end()) {
		singles.erase(x);
		d += 2;
	} else if (d) {
		++d;
	} else {
		singles.insert(x);
	}
}

void erase(int x) {
	int &d = dupcnts[x];
	if (singles.find(x) != singles.end()) {
		singles.erase(x);
	} else if (d == 2) {
		d = 0;
		singles.insert(x);
	} else {
		--d;
	}
}

int N, K;

int main() {
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}

	for(int i = 0; i < K; ++i) {
		insert(ar[i]);
	}

	for(int i = 0, j = K; j <= N; ++i, ++j) {
		if (!singles.size()) {
			printf("Nothing\n");
		} else {
			int m = *singles.rbegin();
			printf("%d\n", m);
		}

		if (j < N) {
			insert(ar[j]);
			erase(ar[i]);
		}
	}

	return 0;
}