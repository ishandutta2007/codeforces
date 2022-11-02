#include <bits/stdc++.h>
using namespace std;

#define N 200200

struct taxi {
	long long free;
	int pos;
} car[N];

bool cmp(int i, int j) {
	return car[i].free != car[j].free ? car[i].free < car[j].free : i < j;
}

void chkmin(int &x, int y) {if (cmp(y, x)) x = y;}

struct RMQ_Tree {

private:
	int n, mn[N<<1];

public:
	void init(int sz) {
		n = sz;
		for (int i = 1; i <= 2 * n; i ++) mn[i] = 0;
	}

	void modify(int p, int val) {
		mn[p+=n] = val;
		for (; p > 1; p >>= 1) mn[p>>1] = cmp(mn[p], mn[p^1]) ? mn[p] : mn[p^1];
	}

	int value(int x) {return mn[n+x];}

	int query(int l, int r) {
		int rlt = 0;
		for (l += n, r += n; l <= r; l = l + 1 >> 1, r = r - 1 >> 1) {
			if (l & 1) chkmin(rlt, mn[l]);
			if (r & 1 ^ 1) chkmin(rlt, mn[r]);
		}
		return rlt;
	}

	int query(int x) {
		int st = -1, en = n;
		while (en - st > 1) {
			int mid = st + en >> 1;
			int l = max(x - mid, 1), r = min(x + mid, n);
			if (query(l, r)) en = mid;
			else st = mid;
		}
		int l = max(x - en, 1), r = min(x + en, n);
		return query(l, r);
	}
} T;

struct compare {
	bool operator () (const int &i, const int &j) {
		return car[i].free != car[j].free ? car[i].free > car[j].free : i > j;
	}
};

int freecnt;
priority_queue <int, vector <int>, compare> pq;
queue <int> q[N];

void pop(long long t) {
	while (!pq.empty()) {
		int x = pq.top();
		if (car[x].free > t) break;
		pq.pop(), freecnt ++;
		if (T.value(car[x].pos)) q[car[x].pos].push(x);
		else T.modify(car[x].pos, x);
	}
}

int n, k, m;

int main() {
//	freopen("l.in", "r", stdin);
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= k; i ++) scanf("%d", &car[i].pos), car[i].free = 0;
	car[0].free = 1ll << 60;
	for (int i = 1; i <= k; i ++) pq.push(i);
	T.init(n);
	long long last = 0;
	while (m --) {
		long long t, wait = 0;
		int from, to;
		scanf("%I64d %d %d", &t, &from, &to);
		pop(t);
		if (!freecnt) pop(last = car[pq.top()].free);
		else last = max(last, t);
		wait += last - t;
		t = last;
		int use = T.query(from);
		freecnt --;
		int x = car[use].pos;
		T.modify(x, 0);
		if (!q[x].empty()) T.modify(x, q[x].front()), q[x].pop();
		wait += abs(x - from);
		car[use].free = t + abs(x - from) + abs(from - to);
		car[use].pos = to;
		pq.push(use);
		printf("%d %I64d\n", use, wait);
	}
	return 0;
}