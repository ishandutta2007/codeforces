#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

bool fail;
vector<vector<ll>> ans;

struct Node {
	ll code;
	int depth;
	int sign;
	Node *l, *r, *p;

	Node(int dep, ll cod, int sig = 0) {
		code = cod;
		depth = dep;
		sign = sig;
		l = r = nullptr;
	}

	void addToAns() {
		ll x = (code << (32ll - depth));
		//cout << depth << " " << (code << 2) % 256 << " " << x % 256 << "\n";
		vector<ll> c(4);
		for (int i = 0; i < 4; i++) {
			c[i] = x % 256;
			x /= 256;
		}
		reverse(c.begin(), c.end());
		c.push_back(depth);
		ans.push_back(c);
	}
};

Node* add(Node *v, ll code, int depth, int sign) {
	if (v->depth == depth) {
		if (v->sign * sign == -1) fail = true;
		v->sign = sign;
		return v;
	}

	if (code & (1ll << (31ll - v->depth))) {
		if (v->r == nullptr) {
			v->r = new Node(v->depth + 1, v->code * 2 + 1);
			v->r->p = v;
		}
		return add(v->r, code, depth, sign);
	} else {
		if (v->l == nullptr) {
			v->l = new Node(v->depth + 1, v->code * 2);
			v->l->p = v;
		}
		return add(v->l, code, depth, sign);
	}
}

int go(Node *v) {
	if (v == nullptr) return 0;

	int sl = go(v->l);
	int sr = go(v->r);
	int sm = v->sign;

	if (sm == -1 && (sl == 1 || sr == 1)) {
		fail = true;
		return 1;
	}

	if (sm == 1 && (sl == -1 || sr == -1)) {
		fail = true;
		return 1;
	}

	int res;
	if (sl == 1 || sm == 1 || sr == 1) res = 1;
	else if (sl == -1 || sm == -1 || sr == -1) res = -1;
	else res = 0;

	if (sl == -1 && (sm == 1 || sr == 1)) {
		v->l->addToAns();
	}

	if (sr == -1 && (sl == 1 || sm == 1)) {
		v->r->addToAns();
	}

	return res;
}

void solve() {
	fail = false;
	ans.clear();
	int n;
	cin >> n;
	Node *root = new Node(0, 0, 0);
	vector<Node*> nodes;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		s.push_back('#');

		vector<ll> v;
		int val = -1;
		for (char ch: s) {
			if ('0' <= ch && ch <= '9') {
				if (val == -1) val = 0;
				val = val * 10 + ch - '0';
			} else {
				if (val != -1) {
					v.push_back(val);
					val = -1;
				}
			}
		}		

		ll x = (v[0] << 24ll) + (v[1] << 16ll) + (v[2] << 8ll) + v[3];
		int dep = ((int)v.size() == 4 ? 32 : v[4]);

		nodes.push_back(add(root, x, dep, (s[0] == '+' ? 1 : -1)));
	}

	int sign = go(root);
	if (sign == -1) {
		ans.push_back({0, 0, 0, 0, 0});
	}

	if (fail) {
		cout << "-1\n";
	} else {
		cout << ans.size() << "\n";
		for (auto v: ans) {
			for (int i = 0; i < (int)v.size(); i++) {
				if (i == 1 || i == 2 || i == 3) cout << ".";
				if (i == 4) cout << "/";
				cout << v[i];
			}
			cout << "\n";
		}
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 4;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}