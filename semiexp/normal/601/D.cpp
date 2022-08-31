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

struct node
{
	node *child[26];
	int size;
	int n_leaves;
	bool is_leaf;
};

node pool[700000]; int pLast = 0;

node *nalloc()
{
	node *ret = &(pool[pLast++]);
	for (int i = 0; i < 26; ++i) ret->child[i] = nullptr;
	ret->size = 1;
	ret->n_leaves = 0;
	ret->is_leaf = false;
	return ret;
}

node *join(node *a, node *b)
{
	if (a == nullptr) return b;
	if (b == nullptr) return a;
	if (a->size < b->size) swap(a, b);

	// a += b
	a->is_leaf |= b->is_leaf;
	a->size = 1;
	a->n_leaves = (a->is_leaf ? 1 : 0);
	for (int i = 0; i < 26; ++i) {
		a->child[i] = join(a->child[i], b->child[i]);
		if (a->child[i]) {
			a->size += a->child[i]->size;
			a->n_leaves += a->child[i]->n_leaves;
		}
	}
	return a;
}

int N, C[303030];
vector<int> graph[303030];
char S[303030];
int D[303030];

node *solve(int p, int rt)
{
	vector<pair<int, node*> > ch;

	for (int q : graph[p]) if (q != rt) {
		node *n = solve(q, p);
		ch.push_back({ n->size, n });
	}
	int ci = S[p] - 'a';
	node *ret;
	if (ch.size() == 0) {
		ret = nalloc();
		ret->child[ci] = nalloc();
		ret->child[ci]->is_leaf = true;
		ret->child[ci]->n_leaves = 1;
		ret->child[ci]->size = 1;
		ret->is_leaf = false;
		ret->n_leaves = 1;
		ret->size = 2;
	} else {
		sort(ch.begin(), ch.end());
		ret = ch[ch.size() - 1].second;
		for (int i = 0; i < ch.size() - 1; ++i) {
			ret = join(ret, ch[i].second);
		}
		if (!ret->is_leaf) {
			ret->is_leaf = true;
			ret->n_leaves++;
		}
		node *ret2 = nalloc();
		ret2->child[ci] = ret;
		ret2->size = ret->size + 1;
		ret2->n_leaves = ret->n_leaves;
		ret2->is_leaf = false;
		ret = ret2;
	}

	D[p] = ret->n_leaves;

	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", C + i);
	scanf("%s", S);
	for (int i = 0; i < N - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	solve(0, -1);

	int best = -1, bp = 0;
	for (int i = 0; i < N; ++i) {
		int a = C[i] + D[i];
		if (best == a) ++bp;
		else if (best < a) {
			best = a;
			bp = 1;
		}
	}
	printf("%d\n%d\n", best, bp);

	return 0;
}