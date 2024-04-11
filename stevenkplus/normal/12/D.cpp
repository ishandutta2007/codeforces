#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 19;

int BIT[MAXN];
int query(int x) {
	int ret = 0;
	while (x) {
		if (BIT[x] > ret) {
			ret = BIT[x];
		}
		x -= x & -x;
	}
	return ret;
}

void put(int x, int val) {
	while (x < MAXN) {
		if (val > BIT[x]) {
			BIT[x] = val;
		}
		x += x & -x;
	}
}

bool flag;
struct gurl {
	int b, i, r;
	int brank;
	bool operator<(const gurl &o) const {
		if (flag) {
			return b > o.b;
		} else {
			return i > o.i;
		}
	}
	gurl(){}
};

gurl gurls[MAXN];
int N;
int main() {
	scanf("%d", &N);
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < N; ++j) {
			int a;
			scanf("%d", &a);
			if (i == 0) gurls[j].b = a;
			else if (i == 1) gurls[j].i = a;
			else if (i == 2) gurls[j].r = a;
		}
	}

	flag = true;
	sort(gurls, gurls + N);
	int r = 0;
	int prv = 1;
	for(int i = 0; i < N; ++i) {
		if (gurls[i].b != prv) ++r;
		prv = gurls[i].b;
		gurls[i].brank = r;
	}

	flag = false;
	sort(gurls, gurls + N);

	int cnt = 0;
	for(int i = 0; i < N;) {
		int prv = gurls[i].i;
		int start = i;
		while (i < N && gurls[i].i == prv) {
			int mval = query(gurls[i].brank - 1);
			if (mval > gurls[i].r) ++cnt;
			++i;
		}

		for(int j = start; j < i; ++j) {
			put(gurls[j].brank, gurls[j].r);
		}
	}

	printf("%d\n", cnt);
	return 0;
}