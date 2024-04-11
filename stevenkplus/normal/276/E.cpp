#include <cstdio>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
const int MAXN = 100100;

int N, Q;

struct bit {
	int *BIT;
	int N;
	bit() {}
	void init(int sz) {
		N = sz;
		BIT = new int[N + 2];
		for(int i = 0; i <= N; ++i) {
			BIT[i] = 0;
		}
	}
	int ask(int x) {
		++x;
		int ret = 0;
		while (x) {
			ret += BIT[x];
			x -= x & -x;
		}
		return ret;
	}

	void inc(int x, int val) {
		++x;
		while (x <= N) {
			BIT[x] += val;
			x += x & -x;
		}
	}
};

bit chainsums[MAXN];
bit rootsums;

vector<int> conn[MAXN];

int pos[MAXN];
int num[MAXN];
int cnts[MAXN];

void build(int cur, int prv, int curnum, int &curpos) {
	++curpos;
	pos[cur] = curpos;
	num[cur] = curnum;
	repi(i, conn[cur]) {
		if (*i != prv) {
			build (*i, cur, curnum, curpos);
		}
	}
}

void buildall() {
	int curnum = 0;
	repi(i, conn[1]) {
		int cnt = 0;
		build (*i, 1, curnum, cnt);
		chainsums[curnum].init(cnt + 1);
		++curnum;
	}
	rootsums.init(N);
}


int query(int x) {
	int ans = rootsums.ask(pos[x]);
	//printf("part1 = %d\n", ans);
	if (x != 1) {
		int part2 = chainsums[num[x]].ask(pos[x]);
		//printf("part2 = %d\n", part2);
		ans += part2;
	}
	return ans;
}

void add(int node, int val, int dst) {
	int rdst = dst - pos[node];
	if (rdst >= 0) {
	//printf("inc [%d %d) %d\n", 0, rdst + 1, val);
		rootsums.inc(0, val);
		rootsums.inc(rdst + 1, -val);
	}

	bit &b = chainsums[num[node]];
	int top = pos[node] - dst;
	int low = pos[node] + dst + 1;
	if (top <= rdst) {
		top = rdst + 1;
	}

	//printf("pos = %d\n", pos[node]);
	//printf("low = %d, top = %d\n", low, top);
	if (top < low) {
		b.inc(top, val);
		b.inc(low, -val);
	}
}

int main() {
	scanf("%d %d", &N, &Q);
	for(int i = 1; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
	}
	//printf("building.\n");
	buildall();
	//printf("done building.\n");

	for(int q = 0; q < Q; ++q) {
		int qtype;
		scanf("%d", &qtype);
		if (qtype == 0) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			//printf("adding %d %d %d\n", a, b, c);
			add(a,b,c);
		} else if (qtype == 1) {
			int p;
			scanf("%d", &p);
			int ans = query(p);
			printf("%d\n", ans);
		}
	}
	return 0;
}