#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
int n, m, q, p[200000], a[300000], b[300000], t[300000], w[400000], preo[400000], posto[400000], coro[200000], cnt = 0, decomp[20][400000];
vector<int> adjlist[400000];
inline int readInt() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9'){
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x;
}
void dfs(int v) {
	preo[v] = cnt;
	if (v < n) coro[cnt++] = v;
	for (int i: adjlist[v]) dfs(i);
	posto[v] = cnt - 1;
}
struct UFDS {
	int join = -1;
	vector<int> parent, rankof, root;
	UFDS(int N) {
		for (int i = 0; i < N; ++i) parent.push_back(i), rankof.push_back(0), root.push_back(i);
	}
	int find_parent(int i) {
		if (i == parent[i]) return i;
		return parent[i] = find_parent(parent[i]);
	}
	void union_set(int p, int q, int k) {
		p = find_parent(p), q = find_parent(q);
		if (p == q) return;
		++join;
		adjlist[n + join].push_back(root[p]), adjlist[n + join].push_back(root[q]);
		decomp[0][root[p]] = decomp[0][root[q]] = n + join;
		if (rankof[p] == rankof[q]) ++rankof[p];
		if (rankof[p] > rankof[q]) parent[q] = p, root[p] = n + join;
		else parent[p] = q, root[q] = n + join;
		w[n + join] = k;
	}
};
struct seg{
    int n;
    vector<ii> tree;
    void create(int Size){
        n = Size;
        tree.resize(2 * Size + 5);
        for(int i = 0;i < n;i++){
            tree[n + i] = ii(p[coro[i]], i);
        }
        for(int i = n - 1;i > 0;i--){
            tree[i] = max(tree[i<<1],tree[i<<1 | 1]);
        }
    }
    void update(int index, int newVal){
        index += n;
        tree[index].first = newVal;
        while(index != 0){
            tree[index >> 1] = max(tree[index], tree[index ^ 1]);
            index = index >> 1;
        }
    }
    ii query(int l, int r){
		++r;
        ii res = ii(0, 0);
        for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l&1)
            res = max(res, tree[l++]);
        if (r&1)
            res = max(res, tree[--r]);
        }
        return res;
    }
    ii get(int i){
        return tree[i + n];
    }
} *root;
ii twok(int v, int k) {
	for (int i = 19; i >= 0; --i) {
		if (decomp[i][v] != -1 && w[decomp[i][v]] > k) v = decomp[i][v];
	}
	return root -> query(preo[v], posto[v]);
}
int main() {
	n = readInt(), m = readInt(), q = readInt();
	for (int i = 0; i < n; ++i) p[i] = readInt();
	for (int i = 0; i < m; ++i) a[i] = readInt(), b[i] = readInt(), --a[i], --b[i];
	fill_n(t, m, q + 1);
	vector<ii> queries;
	int x, y;
	for (int i = 0; i < q; ++i) {
		x = readInt(), y = readInt();
		if (x == 1) queries.push_back(ii(y - 1, i));
		else t[y - 1] = i;
	}
	priority_queue<ii> pq;
	for (int i = 0; i < m; ++i) pq.push(ii(t[i], i));
	UFDS krus(n);
	fill_n(decomp[0], 400000, -1);
	while (!pq.empty()) {
		ii k = pq.top();
		pq.pop();
		krus.union_set(a[k.second], b[k.second], k.first);
	}
	for (int i = 0; i <= n + krus.join; ++i) {
		if (decomp[0][i] == -1) dfs(i);
	}
	root = new seg();
	root -> create(n);
	for (int i = 1; i < 20; ++i) {
		for (int j = 0; j < 400000; ++j) {
			if (decomp[i - 1][j] == -1) decomp[i][j] = -1;
			else decomp[i][j] = decomp[i - 1][decomp[i - 1][j]];
		}
	}
	for (ii i: queries) {
		ii ans = twok(i.first, i.second);
		printf("%d\n", ans.first);
		root -> update(ans.second, 0);
	}
	return 0;
}