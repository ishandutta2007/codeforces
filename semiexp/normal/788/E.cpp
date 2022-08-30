#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, A[101010];

template <typename T>
struct segtree
{
public:
	segtree() : N(0), data(nullptr) {}
	segtree(int len)
	{
		for (int i = 0;; ++i) {
			if (len <= (1 << i)) {
				N = 1 << i;
				break;
			}
		}
		data = new T[2 * N];
		for (int i = 0; i < 2 * N; ++i) data[i] = T();
	}

	T at(int p) { return data[p + N]; }

	T query(int L, int R) {
		T left = T();
		T right = T();

		L += N; R += N;
		while (L < R) {
			if (L & 1) left = left + data[L++];
			if (R & 1) right = data[--R] + right;
			L >>= 1; R >>= 1;
		}
		return left + right;
	}

	void update(int p, const T& val) {
		p += N;
		data[p] = val;
		p >>= 1;
		while (p) {
			data[p] = data[p * 2] + data[p * 2 + 1];
			p >>= 1;
		}
	}

	T top() { return data[1]; }

private:
	int N;
	T *data;
};

struct Pat
{
	i64 lo, loo, o, ol, ool, loool;

	Pat() : lo(0), loo(0), o(0), ol(0), ool(0), loool(0) {}
	Pat(i64 lo, i64 ol) : lo(lo), loo(0), o(1), ol(ol), ool(0), loool(0) {}
};

inline Pat operator+(const Pat &l, const Pat &r)
{
	Pat ret;
	ret.lo = (l.lo + r.lo) % MOD;
	ret.loo = (l.loo + l.lo * r.o + r.loo) % MOD;
	ret.o = (l.o + r.o) % MOD;
	ret.ol = (l.ol + r.ol) % MOD;
	ret.ool = (r.ool + l.o * r.ol + l.ool) % MOD;
	ret.loool = (l.loool + r.loool + l.lo * r.ool + l.loo * r.ol) % MOD;
	return ret;
}

segtree<Pat> ent[101010];
int idx[101010], totcnt[101010];
int lcomp[101010], rcomp[101010];

void pset(int p)
{
	ent[A[p]].update(idx[p], Pat(lcomp[p], rcomp[p]));
}
void unset(int p)
{
	ent[A[p]].update(idx[p], Pat());
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	vector<int> As;
	for (int i = 0; i < N; ++i) As.push_back(A[i]);
	sort(As.begin(), As.end());
	As.erase(unique(As.begin(), As.end()), As.end());
	for (int i = 0; i < N; ++i) A[i] = lower_bound(As.begin(), As.end(), A[i]) - As.begin();

	{
		segtree<int> seg(N);
		for (int i = 0; i < N; ++i) {
			lcomp[i] = seg.query(0, A[i] + 1);
			seg.update(A[i], seg.at(A[i]) + 1);
		}
	}
	{
		segtree<int> seg(N);
		for (int i = N - 1; i >= 0; --i) {
			rcomp[i] = seg.query(0, A[i] + 1);
			seg.update(A[i], seg.at(A[i]) + 1);
		}
	}

	for (int i = 0; i < N; ++i) totcnt[i] = 0;
	for (int i = 0; i < N; ++i) {
		idx[i] = totcnt[A[i]]++;
	}
	for (int i = 0; i < N; ++i) if (totcnt[i] >= 1) {
		ent[i] = segtree<Pat>(totcnt[i]);
	}
	for (int i = 0; i < N; ++i) pset(i);
	i64 ans = 0;
	for (int i = 0; i < As.size(); ++i) ADD(ans, ent[i].top().loool);

	int M;
	scanf("%d", &M);
	for (; M--;) {
		int t, x;
		scanf("%d%d", &t, &x);
		--x;

		ADD(ans, MOD - ent[A[x]].top().loool);

		if (t == 1) unset(x);
		else pset(x);

		ADD(ans, ent[A[x]].top().loool);

		printf("%lld\n", ans);
	}

	return 0;
}