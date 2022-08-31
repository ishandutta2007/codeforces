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
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

typedef pair<int, int> pat;
const int MODa = 1000000007;
const int MODb = 1000000009;

void upd(pair<int, pat> &a, pair<int, pat> b)
{
	if (a.first > b.first) return;
	if (a.first < b.first) a = b;
	else {
		a.second.first += b.second.first;
		if (a.second.first >= MODa) a.second.first -= MODa;
		a.second.second += b.second.second;
		if (a.second.second >= MODb) a.second.second -= MODb;
	}
}

struct segtree
{
	static const int DEPTH = 20;
	static const int N = 1 << DEPTH;
	pair<int, pat> *data;

	segtree() {
		data = new pair<int, pat>[2 * N];
	}
	~segtree() {
		delete[] data;
	}
	void init()
	{
		for (int i = 0; i < 2 * N; ++i) data[i] = { -1, {0, 0} };
	}

	pair<int, pat> query(int L, int R)
	{
		pair<int, pat> ret{ 0, {1, 1} };
		L += N; R += N;
		while (L < R) {
			if (L & 1) upd(ret, data[L++]);
			if (R & 1) upd(ret, data[--R]);
			L >>= 1; R >>= 1;
		}
		return ret;
	}

	void update(int p, pair<int, pat> v)
	{
		p += N;
		while (p) {
			upd(data[p], v);
			p >>= 1;
		}
		/*
		data[p] = v;
		p >>= 1;
		while (p) {
			data[p] = data[p * 2];
			upd(data[p], data[p * 2 + 1]);
			p >>= 1;
		}
		*/
	}
};

int N, M, H[404040];
int A[404040], B[404040];
vector<int> qi[404040];

segtree seg;
pair<int, pat> lpat[404040], rpat[404040]; // for each loc
int lbest[404040], rbest[404040]; // for each q

pat mul(pat a, pat b)
{
	return{ (int)((i64)a.first * b.first % MODa), (int)((i64)a.second * b.second % MODb) };
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%d", H + i);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", A + i, B + i);
		--A[i];
		qi[A[i]].push_back(i);
	}
	vector<int> vs;
	for (int i = 0; i < N; ++i) vs.push_back(H[i]);
	for (int i = 0; i < M; ++i) vs.push_back(B[i]);
	sort(vs.begin(), vs.end());
	vs.erase(unique(vs.begin(), vs.end()), vs.end());
	for (int i = 0; i < N; ++i) H[i] = lower_bound(vs.begin(), vs.end(), H[i]) - vs.begin();
	for (int i = 0; i < M; ++i) B[i] = lower_bound(vs.begin(), vs.end(), B[i]) - vs.begin();

	pair<int, pat> bpat{ -1, {0, 0} };

	seg.init();
	for (int i = 0; i < N; ++i) {
		for (int a : qi[i]) {
			lbest[a] = seg.query(0, B[a]).first;
		}
		auto qv = seg.query(0, H[i]);
		lpat[i] = qv;
		qv.first += 1;
		seg.update(H[i], qv);
	}
	seg.init();
	for (int i = N - 1; i >= 0; --i) {
		for (int a : qi[i]) {
			rbest[a] = seg.query(B[a] + 1, segtree::N).first;
		}
		auto qv = seg.query(H[i] + 1, segtree::N);
		rpat[i] = qv;
		qv.first += 1;
		seg.update(H[i], qv);
		//printf("%d %d\n", H[i], qv.first);
		upd(bpat, qv);
	}

	for (int i = 0; i < M; ++i) {
		int a = A[i];
		int ret;
		if (1 + lpat[a].first + rpat[a].first == bpat.first && mul(lpat[a].second, rpat[a].second) == bpat.second) {
			ret = bpat.first - 1;
		} else {
			ret = bpat.first;
		}
		ret = max(ret, 1 + lbest[i] + rbest[i]);

		printf("%d\n", ret);
	}

	return 0;
}