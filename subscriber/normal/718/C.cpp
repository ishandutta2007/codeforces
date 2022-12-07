#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 411111

#define TASK "1"

using namespace std;

vector<vector<int> > w[N], add[N], q[N];

int n, m;
vector<vector<int> > a, W;

vector<vector<int> > zero = vector<vector<int> >(2, vector<int>(2, 0));
vector<vector<int> > one = zero;

long long u[2][2];

void oo(vector<vector<int> > &r, vector<vector<int> > &c) {
	u[0][0] = u[0][1] = u[1][0] = u[1][1] = 0;

	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) u[i][j] = 0;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++)
		u[i][j] += r[i][k] * 1ll * c[k][j];
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) r[i][j] = u[i][j] % M;
}


vector<vector<int> > getpow(int k) {
	vector<vector<int> > r = one;

	vector<vector<int> > c = a;

	for (int i = 0; i < 30; i++) {
		if (k & pw(i)) oo(r, c);
		oo(c, c);
	}
	return r;
}

void init(int pos, int l, int r) {
	add[pos] = vector<vector<int> >(2, vector<int>(2, 0));
	add[pos][0][0] = add[pos][1][1] = 1;
	w[pos] = q[l];
	if (l == r) return;
	init(pos + pos, l, (l + r) / 2);
	init(pos + pos + 1, (l + r) / 2 + 1, r);
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
		w[pos][i][j] = (w[pos + pos][i][j] + w[pos + pos + 1][i][j]) % M;
}

int get(int pos, int l, int r, int ll, int rr) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return 0;
	if (l == ll && r == rr) return w[pos][0][0];
	if (add[pos][0][0] != 1 || add[pos][1][1] != 1 || add[pos][0][1] != 0 || add[pos][1][0] != 0) {
		oo(w[pos + pos], add[pos]);
		oo(w[pos + pos + 1], add[pos]);

		oo(add[pos + pos], add[pos]);
		oo(add[pos + pos + 1], add[pos]);

		add[pos] = one;
		
	}
	int v1 = get(pos + pos, l, (l + r) / 2, ll, rr);
	int v2 = get(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr);
//	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
//		w[pos][i][j] = (w[pos + pos][i][j] + w[pos + pos + 1][i][j]) % M;
	return (v1 + v2) % M;
}

void mod(int pos ,int l, int r, int ll, int rr, int x) {
	ll =max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return;
	if (l == ll && r == rr) {
		oo(add[pos], W);
		oo(w[pos], W);
		return;
	} 
	if (add[pos][0][0] != 1 || add[pos][1][1] != 1 || add[pos][0][1] != 0 || add[pos][1][0] != 0) {
		oo(w[pos + pos], add[pos]);
		oo(w[pos + pos + 1], add[pos]);

		oo(add[pos + pos], add[pos]);
		oo(add[pos + pos + 1], add[pos]);

		add[pos] = one;
		
	}
	mod(pos + pos, l, (l + r) / 2, ll, rr, x);
	mod(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr, x);
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
		w[pos][i][j] = (w[pos + pos][i][j] + w[pos + pos + 1][i][j]) % M;
	
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;

	one[0][0] = one[1][1] = 1;

	a = vector<vector<int> >(2, vector<int>(2, 0));
	a[0][1] = 1;

	a[0][0] = 1;
	a[1][0] = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;

		q[i] = getpow(x);
	}
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int ty, x, y;
		cin >> ty >> x >> y;
		x--;
		y--;
		if (ty == 2) {
			cout << get(1, 0, n - 1, x, y) << endl;
		} else {
			int val;
			cin >> val;
			W = getpow(val);
			mod(1, 0, n - 1, x, y, val);
		}
		
	}
	return 0;
}