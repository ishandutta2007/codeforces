#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 100100
#define SIGMA 27

struct node {

	node *par, *suffixlink, *chd[SIGMA];
	int l, r, pardp, children, son;

	node() {
		par = suffixlink = NULL;
		for (int i = 0; i < SIGMA; i ++) chd[i] = NULL;
		l = r = pardp = children = son = 0;
	}

	inline int len() {return r - l;}
	inline int depth() {return pardp + len();}
	inline bool inedge(int pos) {return pardp <= pos && pos < depth();}

	void setedge(node *child, int l, int r, char *s) {
		chd[s[l]] = child;
		children ++;
		child -> par = this;
		child -> pardp = depth();
		child -> l = l, child -> r = r;
	}
};

struct Suffix_Tree {

	char *s;
	int length, size;
	bool needwalk;
	node *root, *cur, *needsuffixlink;
	vector <node> v;

	node *newnode() {
		v[size] = node();
		return &v[size++];
	}

	void assign(char *str, int len) {
		s = str;
		length = len;
		size = 0;
		v.clear();
		v.reserve(length * 2 + 7);
		root = newnode();
		cur = newnode();
		root -> setedge(cur, 0, length, s);
		needsuffixlink = NULL;
		needwalk = 1;
	}

	void walkdown(int i, int j) {
		if (i > j) return;
		for (int k = i + cur -> depth(); !cur -> inedge(j - i); k += cur -> len()) cur = cur -> chd[s[k]];
	}

	void addsuffixlink() {
		if (needsuffixlink) needsuffixlink -> suffixlink = cur;
		needsuffixlink = NULL;
	}

	void build(char *str, int len) {
		assign(str, len);
		for (int i = 0, j = 1; i < len; i ++) {	/// extend.
			char c = s[i+1];
			node *leaf, *split;
			for (;j <= i + 1; j ++) {
				if (needwalk) {
					if (!cur -> suffixlink && cur -> par) cur = cur -> par;
					cur = cur -> suffixlink ? cur -> suffixlink : root;
					walkdown(j, i);
				}
				needwalk = 1;
				///	cur is the highest node such that has s[j, i] to a prefix.
				int k = i - j + 1;	///	the length of s[j, i].
				if (k == cur -> depth()) {
					///	when s[j, i] ends in cur.
					addsuffixlink();
					if (cur -> chd[c]) {
						///	extended rule 3.
						cur = cur -> chd[c], needwalk = 0; break;
					}
					else {
						leaf = newnode();
						cur -> setedge(leaf, i + 1, length, s);
					}
				}
				else {
					///	when s[j, i] ends in edge (cur -> par, cur).
					int pos = cur -> l + k - cur -> pardp;
					if (s[pos] == c) {
						///	extend rule 1 or 3.
						addsuffixlink();
						if (pos != i + 1) {
							///	extend rule 3.
							needwalk = 0; break;
						}
					}
					else {
						///	extend rule 2.
						split = newnode(), leaf = newnode();
						cur -> par -> setedge(split, cur -> l, pos, s);
						cur -> par -> children --;
						split -> setedge(cur, pos, cur -> r, s);
						split -> setedge(leaf, i + 1, length, s);
						cur = split;
						addsuffixlink();
						if (cur -> depth() == 1) cur -> suffixlink = root;
						else needsuffixlink = cur;
					}
				}
			}
		}
	}

	void pre(node *x) {
		x -> son = 0;
		if (!x-> children) {
			x -> son = 1; return;
		}
		for (int i = 0; i < SIGMA; i ++) if (x -> chd[i]) {
			node *y = x -> chd[i];
			pre(y);
			if (y -> len() == 0) x -> son = 1;
		}
	}

	ll dfs(node *x) {
		ll rlt = 0;
		if (!x -> children) return rlt;
		for (int i = 0; i < SIGMA; i ++) if (x -> chd[i]) {
			node *y = x -> chd[i];
			if (y -> len() == 0) continue;
			rlt += dfs(y);
			x -> son += y -> son;
			int re = y -> son;
			rlt += 1ll * (y -> len()) * re * re;
		}
		return rlt;
	}
} ST;

int t;
char s[N];

int main() {
//	freopen("i.in", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s);
		int n = strlen(s);
		for (int i = 0; i < n; i ++) s[i] -= 'a' - 1;
		ST.build(s, n);
		ST.pre(ST.root);
		printf("%I64d\n", ST.dfs(ST.root));
	}
	return 0;
}