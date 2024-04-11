#include <cstdio>
#include <set>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
const int MAXN = 300100;

int enemies[MAXN];
int assign[MAXN];

vector<int> conn[MAXN];

int N, M;

struct cmp {
	bool operator() (const int &a, const int &b) const {
		if (enemies[a] != enemies[b]) {
			return enemies[a] > enemies[b];
		} else {
			return a < b;
		}
	}
};

set<int, cmp> myset;

void update(int cow, int val) {
	myset.erase(cow);
	enemies[cow] = val;
	myset.insert(cow);
}

void move(int cow) {
	int cnt = 0;
	int &a = assign[cow];
	a = 1 - a;
	repi(i, conn[cow]) {
		if (assign[*i] == a) {
			++cnt;
			update(*i, enemies[*i] + 1);
		} else {
			update(*i, enemies[*i] - 1);
		}
	}
	update(cow, cnt);
}

void disp() {
	for(int i = 1; i <= N; ++i) {
		printf("%d", assign[i]);
	}
	printf("\n");

	repi(j, myset) {
		int i = *j;
		printf("%d has %d enemies.\n", i, enemies[i]);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
		++enemies[a];
		++enemies[b];
	}

	for(int i = 1; i <= N; ++i) {
		myset.insert(i);
	}

	while (true) {
//		disp();
		int k = *myset.begin();
//		printf("k = %d\n", k);
		if (enemies[k] >= 2) {
			move(k);
		} else break;
	}

	for(int i = 1; i <= N; ++i) {
		printf("%d", assign[i]);
	}
	printf("\n");
	return 0;
}