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

typedef map<i64, int> *state;

int N;
i64 M, inv10;
vector<pair<int, int> > graph[101010];
i64 ret;

i64 p10[201010], i10[201010];

pair<state, state> solve(int p, int rt, int dep, i64 acc_up, i64 acc_dw)
{
	// <up, down>
	vector<pair<int, pair<state, state> > > subs;
	for (auto q : graph[p]) if (q.first != rt) {
		auto a = solve(q.first, p, dep + 1, (acc_up + q.second * p10[dep + 1]) % M, (acc_dw + q.second * i10[dep + 1]) % M);
		subs.push_back(make_pair( (int)a.first->size(), a ));
	}
	sort(subs.begin(), subs.end());
//	printf("%d %lld %lld %lld->\n",p, acc_up, acc_dw, ret);
	map<i64, int> *r1, *r2;
	
	if (subs.size() > 0) {
		r1 = subs[subs.size() - 1].second.first;
		r2 = subs[subs.size() - 1].second.second;
		subs[subs.size() - 1].second.first = new map<i64, int>();
		subs[subs.size() - 1].second.second = new map<i64, int>();
		(*(subs[subs.size() - 1].second.first))[acc_up] += 1;
		(*(subs[subs.size() - 1].second.second))[acc_dw] += 1;
		for (int i = 0; i < subs.size(); ++i) {
			for (auto v : *(subs[i].second.first)) {
				i64 target = ((v.first - acc_up) * i10[dep + 1] % M) * i10[dep] % M;
				target = (M - target) % M;
				target = (target + acc_dw) % M;
			//	printf("%lld->%lld %lld\n", v.first, target, (*r2)[target]);
				ret += (i64)v.second * (*r2)[target];
			}
			for (auto v : *(subs[i].second.second)) {
				i64 target = ((v.first - acc_dw) * p10[dep] % M) * p10[dep + 1] % M;
				target = (M - target) % M;
				target = (target + acc_up) % M;
			//	printf("%lld->%lld %lld\n", v.first, target, (*r1)[target]);
				ret += (i64)v.second * (*r1)[target];
			}
			for (auto v : *(subs[i].second.first)) (*r1)[v.first] += v.second;
			for (auto v : *(subs[i].second.second)) (*r2)[v.first] += v.second;
		}
	} else {
		r1 = new map<i64, int>();
		r2 = new map<i64, int>();

		(*r1)[acc_up] += 1;
		(*r2)[acc_dw] += 1;
	}
	return{ r1, r2 };
}

int main()
{
	scanf("%d%lld", &N, &M);
	for (int i = 0; i < N - 1; ++i) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		graph[x].push_back({ y, w });
		graph[y].push_back({ x, w });
	}

	for (int i = 0; i < 10; ++i) {
		if ((i * M + 1) % 10 == 0) {
			inv10 = (i * M + 1) / 10;
		}
	}

	p10[0] = 1;
	i10[0] = 1;
	for (int i = 1; i <= 2 * N; ++i) {
		p10[i] = p10[i - 1] * 10 % M;
		i10[i] = i10[i - 1] * inv10 % M;
	}
	ret = 0;
	solve(0, -1, 0, 0, 0);

	printf("%lld\n", ret);

	return 0;
}