#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

struct Node {
	pair<int, int> key; int val, fix;
	int key_lazy, val_lazy;
	Node *lc, *rc;
	Node(pair<int, int> key, int val) : key(key), val(val),
		key_lazy(0), val_lazy(0), lc(NULL), rc(NULL) { fix = rand(); }
	void push() {
		if(!key_lazy && !val_lazy) return;
		key.fi += key_lazy; val += val_lazy;
		if(lc) { lc -> key_lazy += key_lazy; lc -> val_lazy += val_lazy; }
		if(rc) { rc -> key_lazy += key_lazy; rc -> val_lazy += val_lazy; }
		key_lazy = val_lazy = 0;
	}
};
void split(Node *p, pair <int, int> c, Node* &l, Node* &r) {
	if(!p) l = r = NULL;
	else {
		p -> push();
		if(p -> key >= c) split(p -> lc, c, l, p -> lc), r = p;
		else split(p -> rc, c, p -> rc, r), l = p;
	}
}
void merge(Node* &p, Node *l, Node *r) {
	if(!l) p = r; else if(!r) p = l;
	else {
		l -> push(); r -> push();
		if(l -> fix < r -> fix) merge(l -> rc, l -> rc, r), p = l;
		else merge(r -> lc, l, r -> lc), p = r;
	}
}
void insert(Node* &p, Node *q) {
	Node *l, *r;
	split(p, q -> key, l, r);
	merge(p, l, q);
	merge(p, p, r);
}

void dfs1(Node *p, Node* &q) {
	if(!p) return;
	p -> push();
	insert(q, new Node(p -> key, p -> val));
	dfs1(p -> lc, q); dfs1(p -> rc, q);
}

const int N = (int)2e5 + 11;
int ans[N];
void dfs2(Node *p) {
	if(!p) return;
	p -> push();
	ans[p -> key.se] = p -> val;
	dfs2(p -> lc); dfs2(p -> rc);
}

int main() {
	srand(25252);
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	vector <pair <int, int> > v;
	while(n --) {
		int c, q; cin >> c >> q;
		v.push_back({-q, c});
	}
	sort(v.begin(), v.end());
	int q; cin >> q;
	Node* treap = NULL;
	for(int i = 1; i <= q; i ++) {
		int b; cin >> b;
		insert(treap, new Node({b, i}, 0));
	}
	
	for(auto p : v) {
		int c = p.se;
		Node *l, *r, *r2;
		split(treap, {c, 0}, l, r);
		if(r) { r -> push(); r -> key_lazy -= c; r -> val_lazy ++; }
		split(r, {c, 0}, r, r2);
		dfs1(r, l);
		merge(treap, l, r2);
	}
	
	dfs2(treap);
	for(int i = 1; i <= q; i ++)
		cout << ans[i] << ' ';
	cout << '\n';
	
	return 0;
}