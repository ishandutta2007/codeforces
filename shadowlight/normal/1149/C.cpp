#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e6 + 7;

struct Data {
	ll min, max, resl, resr;
};

struct TNode {
	ll L, R;
	TNode *left, *right;
	Data d;
	ll val;
};

TNode *new_node(ll L, ll R) {
	return new TNode({L, R, nullptr, nullptr, {INF, -1, -1, -1}, 0});
}

Data safe(TNode *root) {
	if (!root) {
		return {INF, -1, -1, -1};
	}
	return root->d;
}

Data upd(Data a, Data b) {
	Data c;
	c.min = min(a.min, b.min);
	c.max = max(a.max, b.max);
	c.resl = max({a.resl, b.resl, a.max - 2 * b.min});
	c.resr = max({a.resr, b.resr, b.max - 2 * a.min});
	return c;
}

void relax(TNode *root) {
	if (!root) return;
	root->d = upd(safe(root->left), safe(root->right));
}

void add_val(TNode *root, ll val) {
	if (!root) return;///asf;asfjpaSGJPAGJassa
	root->val += val;
	(root->d).min += val;
	(root->d).max += val;
	(root->d).resl -= val;
	(root->d).resr -= val;
}

void push(TNode *root) {
	if (!root) return;
	add_val(root->left, root->val);
	add_val(root->right, root->val);
	root->val = 0;
}

vector <ll> pref;

TNode *build_tree(ll L, ll R) {
	TNode *root = new_node(L, R);
	if (R - L == 1) {
		root->d = {pref[L], pref[L], -pref[L], -pref[L]};
	} else {
		ll M = (L + R) / 2;
		root->left = build_tree(L, M);
		root->right = build_tree(M, R);
		relax(root);
	}
	return root;
}

void add_seg(TNode *root, ll L, ll R, ll val) {
	if (L >= root->R || root->L >= R) {
		return;
	}
	if (L <= root->L && root->R <= R) {
		add_val(root, val);
		return;
	}
	push(root);
	add_seg(root->left, L, R, val);
	add_seg(root->right, L, R, val);
	relax(root);
	//cout << root->L << " " << root->R << " " << (root->d).resl << "\n";
}

Data get_res(TNode *root, ll L, ll R) {
	if (L >= root->R || root->L >= R) {
		return {INF, -1, -1, -1};
	}
	if (L <= root->L && root->R <= R) {
		return root->d;
	}
	push(root);
	Data res = upd(get_res(root->left, L, R), get_res(root->right, L, R));
	//cout << root->L << " " << root->R << " " << L << " " << R << "\n";
	//cout << res.resl << "\n";
	relax(root);
	return res;
}

ll m;

pair <ll, ll> get_max(TNode *root) {
	if (root->R - root->L == 1) {
		return {(root->d).max, root->L};
	}
	push(root);
	pair <ll, ll> ret;
	if (safe(root->left).max > safe(root->right).max) {
		ret = get_max(root->left);
	} else {
		ret = get_max(root->right);
	}
	relax(root);
	return ret;
}

void print(TNode *root) {
	if (root->R - root->L == 1) {
		cout << (root->d).max << " ";
		return;
	}
	push(root);
	print(root->left);
	print(root->right);
	relax(root);
}

ll query(TNode *root) {
	auto t = get_max(root);
	ll pos = t.second, val = t.first;
	//cout << pos << " " << val << "\n";
	Data a = get_res(root, 0, pos);
	Data b = get_res(root, pos + 1, m);
	//cout << a.resl << " " << b.resr << "\n";
	return max(max(a.resl, b.resr) + val, 0LL);
}
//huidogasdkda
int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	pref.push_back(0);
	for (ll i = 0; i < 2 * (n - 1); i++) {
		pref.push_back(pref.back() + (s[i] == '(' ? 1 : -1));
	}
	m = 2 * n - 1;
	TNode *root = build_tree(0, m);
	cout << query(root) << "\n";
	for (ll i = 0; i < q; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		if (a > b) swap(a, b);
		if (s[a] != s[b]) {
			if (s[a] == '(') {
				add_seg(root, a + 1, b + 1, -2);
			} else {
				add_seg(root, a + 1, b + 1, 2);
			}
			swap(s[a], s[b]);
		}
		//print(root);
		//cout << "\n";
		cout << query(root) << "\n";
	}
}