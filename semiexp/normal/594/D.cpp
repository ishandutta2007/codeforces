#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

struct segtree
{
	static const int N = 1 << 18;
	i64 data[2 * N];

	void Init()
	{
		fill(data, data + 2 * N, 1LL);
	}

	i64 query(int p)
	{
		p += N;
		i64 ret = 1;
		while (p) {
			ret *= data[p];
			ret %= MOD;
			p >>= 1;
		}
		return ret;
	}

	void update(int L, int R, i64 mult)
	{
		L += N; R += N;
		while (L < R) {
			if (L & 1) {
				data[L] = data[L] * mult % MOD;
				L++;
			}
			if (R & 1) {
				--R;
				data[R] = data[R] * mult % MOD;
			}
			L >>= 1; R >>= 1;
		}
	}
};

i64 modpow(i64 a, int p)
{
	if (p == 0) return 1;
	i64 tmp = modpow(a, p / 2);
	tmp = tmp * tmp % MOD;
	if (p % 2) tmp = tmp * a % MOD;
	return tmp;
}

i64 inv(i64 a)
{
	return modpow(a, MOD - 2);
}

struct action
{
	int left, right;
	i64 mult;

	action() {}
	action(int lf, int rg, i64 m) : left(lf), right(rg), mult(m) {}
};

int N, Q, A[202020], L[202020], R[202020];
i64 invs[1010101];

i64 accmul[202020], accinv[202020];
segtree seg;

int pfactor[1010101];
int last_pos[1010101];

void gen_prime()
{
	for (int i = 2; i <= 1000000; ++i) {
		pfactor[i] = -1;
		last_pos[i] = -1;
	}

	for (int i = 2; i <= 1000000; ++i) {
		if (pfactor[i] == -1) {
			pfactor[i] = i;
			if (i > 1000) continue;
			for (int j = i * i; j <= 1000000; j += i) pfactor[j] = pfactor[i];
		}
	}
}

i64 ret[202020];
vector<action> acts[202020];
vector<pair<int, int> > queries[202020];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		scanf("%d%d", L + i, R + i);
		--L[i];

		queries[L[i]].push_back(make_pair(i, R[i]));
	}
	for (int i = 1; i <= 1000000; ++i) invs[i] = inv(i);

	gen_prime();

	accmul[0] = accinv[0] = 1;
	for (int i = 0; i < N; ++i) {
		accmul[i + 1] = accmul[i] * A[i] % MOD;
		accinv[i + 1] = accinv[i] * invs[A[i]] % MOD;
	}

	for (int i = 0; i < N; ++i) {
		int v = A[i];
		while (v > 1) {
			int p = pfactor[v];
			while (v % p == 0) v /= p;

			acts[last_pos[p] + 1].push_back(action(i, N, (p - 1) * invs[p] % MOD));
			acts[i + 1].push_back(action(i, N, p * invs[p - 1] % MOD));

			last_pos[p] = i;
		}
	}

	seg.Init();
	for (int i = 0; i < N; ++i) {
		for (action &a : acts[i]) {
			seg.update(a.left, a.right, a.mult);
		}

		for (auto &q : queries[i]) {
			int ql = i, qr = q.second, qpos = q.first;
			ret[qpos] = seg.query(qr - 1) * accmul[qr] % MOD * accinv[ql] % MOD;
		}
	}

	for (int i = 0; i < Q; ++i) printf("%d\n", (int)ret[i]);
	return 0;
}