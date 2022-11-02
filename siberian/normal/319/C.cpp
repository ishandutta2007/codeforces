#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

const ll INF = 1e18;

struct line{
	ll k, b;
	line() {
		k = 0, b = INF;
	}
	line(ll x, ll y) {
		k = x, b = y;
	}
};

ll eval(line l, ll x) {
	return l.k * x + l.b;
}

struct node{
	node *L, *R;
	line l;
	node() {
		l = line();
		L = nullptr;
		R = nullptr;
	}
	node(line x) {
		l = x;
		L = nullptr;
		R = nullptr;
	}
};

const int MINL = -1e9 - 10, MAXR = 1e9 + 10;

struct Li_chao{
	node * root;
	Li_chao() {
		root = new node();
	}

	node * add(line x, node * root, int tl, int tr) {
		if (root == nullptr) root = new node();
		int tm = (tl + tr) / 2;
		bool mid = eval(x, tm) < eval(root->l, tm);
		bool left = eval(x, tl) < eval(root->l, tl);
		if (mid) swap(x, root->l);
		if (tl == tr - 1) return root;
		if (mid != left){
			//if (root->L == nullptr) root->L = new node();
			root->L = add(x, root->L, tl, tm);
		}
		else{
			//if (root->R == nullptr) root->R = new node();
			root->R = add(x, root->R, tm, tr);
		}
		return root;
	} 

	void add(line x) {
		root = add(x, root, MINL, MAXR);
	}

	ll get(int x, node * root, int tl, int tr) {
		if (root == nullptr) return INF;
		if (tl >= x + 1 || tr <= x) return INF;
		if (tl == tr - 1) return eval(root->l, x);
		int tm = (tl + tr) / 2;
		return min(eval(root->l, x), min(get(x, root->L, tl, tm), get(x, root->R, tm, tr)));
	}

	ll get(int x) {
		return get(x, root, MINL, MAXR);
	}
};

const int MAXN = 1e5 + 10;
int n;
ll a[MAXN], b[MAXN];
ll dp[MAXN];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	Li_chao help = Li_chao();
	help.add(line(b[1], 0));
	for (int i = 2; i <= n; i++) {
		dp[i] = help.get(a[i]);
		help.add(line(b[i], dp[i]));
		//for (int j = 1; j < i; j++) {
		//	dp[i] = min(dp[i], dp[j] + a[i] * b[j]);
		//}
	}

	cout << dp[n] << endl; 
	return 0;
}