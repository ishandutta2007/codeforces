#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

const ll INF = 998244353;

ll power(ll a, ll k, ll mod = INF) {
	if (!k) {
		return 1;
	}
	ll b = power(a, k / 2, mod);
	b = b * b % mod;
	if (k % 2) {
		return a * b % mod;
	} else {
		return b;
	}
}

void add(ll &x, ll y) {
	x = (x + y) % (INF - 1);
}

ll rev(ll a) {
	return power(a, INF - 2);
}


struct Matrix {
	ll n, m;
	vector <vector <ll> > a;
	Matrix(vector <vector <ll> > &a) : a(a) {
		n = a.size();
		m = a[0].size();
	}
	Matrix(ll n, ll m) : n(n), m(m), a(n, vector <ll> (m, 0)) {}
};

typedef Matrix* matrix;


vector <ll> pi;
ll g = 3;
ll phi = 95831457792;


matrix mul(matrix a, matrix b) {
	matrix c = new Matrix(a->n, b->m);
	assert(a->n == b->m);
	for (ll i = 0; i < a->n; i++) {
		for (ll j = 0; j < b->m; j++) {
			for (ll k = 0; k < a->m; k++) {
				add(c->a[i][j], a->a[i][k] * b->a[k][j] % (INF - 1));
			}
		}
	}
	return c;
}

matrix ones, mat;
vector <ll> b;

void get_ones(ll n) {
	ones = new Matrix(n, n);
	for (ll i = 0; i < n; i++) {
		ones->a[i][i] = 1;
	}
}

void get_mat(ll n) {
	mat = new Matrix(n, n);
	for (ll i = 0; i < n; i++) {
		mat->a[i][0] = b[i];
	}
	for (ll i = 1; i < n; i++) {
		mat->a[i - 1][i] = 1;
	}
}

matrix power(matrix a, ll k) {
	if (!k) {
		return ones;
	}
	matrix b = power(a, k / 2);
	b = mul(b, b);
	if (k % 2) {
		return mul(b, a);
	} else {
		return b;
	}
}

void init(ll k) {
	get_ones(k);
	get_mat(k);
	pi.clear();
	ll t = INF - 1;
	for (ll i = 2; i <= sqrt(INF); i++) {
		ll cnt = 0;
		while (t % i == 0) {
			cnt++;
			t /= i;
		}
		if (cnt) {
			pi.push_back(i);
		}
	}
	if (t != 1) {
		pi.push_back(t);
	}	
}

int get_ind(int a, int b, int m) {
	int n = (int) sqrt (m + .0) + 1;
 
	int an = 1;
	for (int i=0; i<n; ++i)
		an = (an * a) % m;
 
	map<int,int> vals;
	for (int i=1, cur=an; i<=n; ++i) {
		if (!vals.count(cur))
			vals[cur] = i;
		cur = (cur * an) % m;
	}
 
	for (int i=0, cur=b; i<=n; ++i) {
		if (vals.count(cur)) {
			int ans = vals[cur] * n - i;
			if (ans < m)
				return ans;
		}
		cur = (cur * a) % m;
	}
	return -1;
}

void solve() {
	b.clear();	
	ll k;
	cin >> k;
	b.resize(k);
	for (ll i = 0 ; i < k; i++) {
		cin >> b[i];
	}
	init(k);
	ll n, m;
	cin >> n >> m;
	if (m == 1) {
		cout << 1 << "\n";
		return;
	}
	matrix a = new Matrix(k, k);
	a->a[0][0] = 1;
	//cout << n - k << "\n";
	// matrix kek = ones;
	// for (int i = 0; i < n - k; i++) {
	// 	kek = mul(kek, mat);
	// }
	matrix res = mul(a, power(mat, n - k));
	ll st = res->a[0][0];
	ll was_st = st;
	ll t;
	ll d = 1;
	t = get_ind(g, m, INF);
	assert(power(g, t) == m);
	ll gd = __gcd(st, t);
	st /= gd, t /= gd;
	//cout << st << " " << t << "\n";	
	if (__gcd(st, INF - 1) != 1) {
		cout << "-1\n";
		return;
	}
	ll val = t * power(st, phi - 1, INF - 1) % (INF - 1);
	ll ans = power(g, val);
	cout << ans << "\n";
	//assert(power(6, was_st) == m);
}


const ll TESTS = 1;

signed main() {
	//freopen("F.in", "r", stdin);
	//freopen("F.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	for (ll i = 0; i < TESTS; i++) {
		solve();
	}
}