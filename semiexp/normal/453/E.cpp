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
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

struct dyn_segtree
{
	struct node
	{
		node *left, *right;
		i64 M, R;
	};

	node *top;
	static node pool[32 * 2 * 100000];
	static int pLast;
	static const int TOP = 1 << 18;

	node *alloc()
	{
		node *ret = &(pool[pLast++]);
		ret->left = ret->right = NULL;
		ret->M = ret->R = 0;
		return ret;
	}

	void init()
	{
		top = alloc();
	}

	i64 M(node* ptr)
	{
		return ptr ? ptr->M : 0;
	}
	i64 R(node* ptr)
	{
		return ptr ? ptr->R : 0;
	}

	node* add(const node* ptr, int pos, int depth, int Mval, int Rval)
	{
		if (depth == 0) {
			node *ret = alloc();
			ret->M = ptr->M + Mval;
			ret->R = ptr->R + Rval;
			return ret;
		}

		node *ret = alloc();

		if (pos < (1 << (depth - 1))) {
			ret->left = add(!ptr->left ? alloc() : ptr->left, pos, depth - 1, Mval, Rval);
			ret->right = ptr->right;
		}
		else {
			ret->right = add(!ptr->right ? alloc() : ptr->right, pos - (1 << (depth - 1)), depth - 1, Mval, Rval);
			ret->left = ptr->left;
		}

		ret->M = M(ret->left) + M(ret->right);
		ret->R = R(ret->left) + R(ret->right);
		return ret;
	}

	dyn_segtree add(int pos, int Mval, int Rval)
	{
		node* rt = add(top, pos, 18, Mval, Rval);

		dyn_segtree ret;
		ret.top = rt;
		return ret;
	}

	pair<i64, i64> query(node* ptr, int L, int R, int pL, int pR)
	{
		if (R <= pL || pR <= L || !ptr) return make_pair(0LL, 0LL);
		if (L <= pL && pR <= R) {
			return make_pair(ptr->M, ptr->R);
		}

		auto lf = query(ptr->left, L, R, pL, (pL + pR) / 2);
		auto rg = query(ptr->right, L, R, (pL + pR) / 2, pR);

		return make_pair(lf.first + rg.first, lf.second + rg.second);
	}

	pair<i64, i64> query(int L, int R)
	{
		return query(top, L, R, 0, TOP);
	}
};
dyn_segtree::node dyn_segtree::pool[32 * 2 * 100000];
int dyn_segtree::pLast = 0;

int N, M;
int S[100100], Mx[100100], Re[100100], Et[100100];
int T[100100], Lf[100100], Rg[100100];
i64 sumM[100100], sumRe[100100];

dyn_segtree seg;

map<int, dyn_segtree> Mp;

i64 count(int L, int R, int dur)
{
	auto q = (--Mp.upper_bound(dur))->second.query(L, R);
	return q.first + (sumRe[R] - sumRe[L] - q.second) * dur;
}

int main()
{
	dyn_segtree::pLast = 0;
	seg.init();

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", S + i, Mx + i, Re + i);

		if (Re[i] == 0) Et[i] = (1 << 30) - 1;
		else Et[i] = Mx[i] / Re[i] + (Mx[i] % Re[i] != 0 ? 1 : 0);
	}

	vector<pair<int, int> > V;
	for (int i = 0; i < N; i++) V.push_back(make_pair(Et[i], i));
	sort(V.begin(), V.end());

	Mp.insert(make_pair(0, seg));
	for (int i = 0; i < N; i++){
		int p = V[i].second;
		seg = seg.add(p, Mx[p], Re[p]);
		if (Mp.count(Et[p]) == 1) Mp[Et[p]] = seg;
		else Mp.insert(make_pair(Et[p], seg));
	}

	sumRe[0] = 0;
	for (int i = 0; i < N; i++) sumRe[i+1] = sumRe[i] + Re[i];

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", T + i, Lf + i, Rg + i);
		--Lf[i];
	}

	set<pair<int, int> > acts;
	acts.insert(make_pair(0, -1)); //renewal [first, ?) at time <second>

	for (int i = 0; i < M; i++) {
		auto iter = acts.upper_bound(make_pair(Lf[i], 2100000000));
		--iter;

		i64 sol = 0;
		int nxp = -1, nxtime = 0;

		auto tmp = *iter;

		for (; iter != acts.end();) {
			if (iter->first > Rg[i]) {
				break;
			}

			if (iter->first <= Rg[i]) {
				nxp = iter->first;
				nxtime = iter->second;
			}

			auto iter2 = iter;
			++iter2;

			if (iter->first >= Rg[i]) {
				acts.erase(iter);
				break;
			}

			int nex = iter2 == acts.end() ? N : iter2->first;

			if (iter->second == -1) {
				// from the beginning
				int lef = max(Lf[i], iter->first), rig = min(Rg[i], nex);

				for (int j = lef; j < rig; j++) {
					sol += min((i64)Mx[j], (i64)S[j] + (i64)Re[j] * T[i]);
				}
			}
			else {
				sol += count(max(Lf[i], iter->first), min(Rg[i], nex), T[i] - iter->second);
			}

			acts.erase(iter);
			iter = iter2;
		}
		acts.insert(make_pair(Lf[i], T[i]));
		acts.insert(make_pair(Rg[i], nxtime));
		if (tmp.first < Lf[i]) acts.insert(tmp);
		
		/*
		for (auto el : acts) {
			printf("%d %d, ", el.first, el.second);
		}
		puts("");
		*/
		cout << sol << endl;
	}

	return 0;
}