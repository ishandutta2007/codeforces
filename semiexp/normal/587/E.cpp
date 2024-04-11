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

vector<int> take_base(vector<int> A)
{
	vector<int> A_ori = A;
	vector<int> ret;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] == 0) continue;
		ret.push_back(A_ori[i]);
		int core = A[i] & -A[i];
		for (int j = i + 1; j < A.size(); ++j) {
			if (A[j] & core) A[j] ^= A[i];
		}
		if (ret.size() >= 30) break;
	}
	return ret;
}

typedef pair<int, vector<int> > even_base;

even_base merge_even_base(even_base A, even_base B)
{
	vector<int> seq;
	for (int i = 0; i < A.second.size(); ++i) seq.push_back(A.second[i]);
	seq.push_back(B.first ^ A.first);
	for (int i = 0; i < B.second.size(); ++i) seq.push_back(B.second[i] ^ B.first ^ A.first);
	return{ A.first, take_base(seq) };
}

const int DEPTH = 18;
const int OFS = 1 << DEPTH;
int N, Q;
int A[505050];
even_base segtree[1 << 19];
i64 lazy[1 << 19];

void propagate(int p)
{
//	printf("propagate %d: %d\n", p, lazy[p]);
	lazy[p * 2] ^= lazy[p];
	segtree[p * 2].first ^= lazy[p];
	lazy[p * 2 + 1] ^= lazy[p];
	segtree[p * 2 + 1].first ^= lazy[p];
	lazy[p] = 0;
}

void show_even_base(even_base &b)
{
	printf("%d,", b.first);
	for (int v : b.second) printf(" %d", v);
	puts("");
}

void update(int p, int qL, int qR, int X, int dep = DEPTH)
{
	int pL = p << dep, pR = (p + 1) << dep;
	if (qR <= pL || pR <= qL) return;
	if (qL <= pL && pR <= qR) {
		lazy[p] ^= X;
		segtree[p].first ^= X;
		return;
	}
	propagate(p);
	update(p * 2, qL, qR, X, dep - 1);
	update(p * 2 + 1, qL, qR, X, dep - 1);
	segtree[p] = merge_even_base(segtree[p * 2], segtree[p * 2 + 1]);
//	printf("%d -> ", p);
//	show_even_base(segtree[p]);
}

even_base fold(int p, int qL, int qR, int dep = DEPTH)
{
	int pL = p << dep, pR = (p + 1) << dep;
	if (qR <= pL || pR <= qL) return{ 0, {} };
	if (qL <= pL && pR <= qR) {
		return segtree[p];
	}
	propagate(p);
	return merge_even_base(fold(p * 2, qL, qR, dep - 1), fold(p * 2 + 1, qL, qR, dep - 1));
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; ++i) {
		scanf("%d", A + i);
	}
	if (!true) {
		N = 200000;
		for (int i = 0; i < N; ++i) A[i] = (1 << 30) - 2 - i;
	}
	for (int i = 0; i < OFS; ++i) {
		if (i < N) segtree[i + OFS] = make_pair(A[i], vector<int>());
		else segtree[i + OFS] = make_pair(0, vector<int>());
	}
	for (int i = OFS - 1; i >= 1; --i) segtree[i] = merge_even_base(segtree[i * 2], segtree[i * 2 + 1]);
//	printf("%d", segtree[1].first);
//	for (int v : segtree[1].second) printf(" %d", v);
//	puts("");

	for (int i = 0; i < Q; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			--l;
			update(1, l + OFS, r + OFS, k);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			--l;
			even_base b = fold(1, l + OFS, r + OFS);
			b.second.push_back(b.first);
//			show_even_base(b);
			printf("%d\n", 1 << (take_base(b.second).size()));
		}
	}
	return 0;
}