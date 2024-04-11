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

struct seg_tree
{
	static const int SZ = 1 << 19;
	int data[SZ * 2];
	i64 sum[SZ * 2];

	seg_tree()
	{
		for (int i = 0; i<SZ * 2; i++) {
			data[i] = -1;
			sum[i] = 0;
		}
	}

	void apply(int pL, int pR, int qL, int qR, int value, int depth)
	{
		if (qR <= (pL << depth) || (pR << depth) <= qL) return;
		if (qL <= (pL << depth) && (pR << depth) <= qR) {
			data[pL] = value;
			sum[pL] = (i64)value * (1 << depth);
			return;
		}
		if (data[pL] != -1) {
			data[pL * 2] = data[pL * 2 + 1] = data[pL];
			sum[pL * 2] = sum[pL * 2 + 1] = sum[pL] / 2;
		}
		data[pL] = -1;
		apply(pL << 1, (pL << 1) + 1, qL, qR, value, depth - 1);
		apply((pL << 1) + 1, pR << 1, qL, qR, value, depth - 1);
		sum[pL] = sum[pL * 2] + sum[pL * 2 + 1];
	}

	void apply(int qL, int qR, int value)
	{
		apply(1, 2, qL + SZ, qR + SZ, value, 19);
	}

	i64 query(int pL, int pR, int qL, int qR, int depth)
	{
		if (qR <= (pL << depth) || (pR << depth) <= qL) return 0;
		if (qL <= (pL << depth) && (pR << depth) <= qR) {
			return sum[pL];
		}
		if (data[pL] != -1) {
			return (i64)data[pL] * (min(pR << depth, qR) - max(pL << depth, qL));
		}
		return query(pL << 1, (pL << 1) + 1, qL, qR, depth - 1) +
			query((pL << 1) + 1, pR << 1, qL, qR, depth - 1);
	}

	i64 query(int qL, int qR)
	{
		return query(1, 2, qL + SZ, qR + SZ, 19);
	}
};

struct seg_tree2
{
	static const int SZ = 1 << 19;
	int data[SZ * 2];

	seg_tree2()
	{
		for (int i = 0; i<SZ * 2; i++) data[i] = 0;
	}

	void set(int p, int v)
	{
		p += SZ;
		while (p) {
			data[p] = max(data[p], v);
			p >>= 1;
		}
	}

	int find(int v)
	{
		int p = 1;
		while (p<SZ) {
			if (data[p * 2 + 1]>v) p = p * 2 + 1;
			else p = p * 2;
		}
		return p - SZ;
	}

	int at(int p) { return data[p + SZ]; }
};

pair<int, int> fish[500010];
pair<int, pair<int, int> > query[500010];

seg_tree seg1;
seg_tree2 seg2;

int N, P, Q, R;
int A[505050], B[505050], C[505050];

void append(vector<pair<int, pair<int, int> > > &q, int a, int b, int c)
{
	q.push_back({ a - 1, {b, c} });
}

int main()
{
	scanf("%d%d%d%d", &N, &P, &Q, &R);
	vector<pair<int, pair<int, int> > > query;
	for (int i = 0; i < N; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		append(query, a, b, R);
		append(query, P, b, c);
		append(query, a, Q, c);
	}

	sort(query.begin(), query.end());
	i64 total = 0, ret = 0; int qp = query.size() - 1;
	for (int i = 500000; i >= 0; i--) {
		while (qp >= 0 && query[qp].first == i) {
			//make range[0, q.second.first) :max= q.second.second;
			int lp = seg2.find(query[qp].second.second);
			if (seg2.at(lp) > query[qp].second.second) ++lp;
			//printf("%d %d\n", lp, query[qp].second.first);
			//printf("%d,%d: %d\n", query[qp].second.first, query[qp].second.second, lp);
			if (query[qp].second.first > lp) {
				total += (i64)query[qp].second.second * (query[qp].second.first - lp);
				total -= seg1.query(lp, query[qp].second.first);
				seg1.apply(lp, query[qp].second.first, query[qp].second.second);
				seg2.set(query[qp].second.first - 1, query[qp].second.second);
			}
			--qp;
		}

		//if(total) printf("%d: %lld\n", i, total);
		ret += total;
	}
	ret = (i64)P * Q * R - ret;
	printf("%lld\n", ret);

	return 0;
}