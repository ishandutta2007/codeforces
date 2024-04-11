#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 100010
int n, m;
int N;
struct Matrix {
	ll mat[2][2];
};

Matrix fm;
Matrix id;

ll svals[maxn];
ll top[maxn*4];
ll bot[maxn*4];
Matrix lazy[maxn*4];

const int mod = 1000000007;


Matrix matMul(Matrix a, Matrix b) {
	Matrix ans;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ans.mat[i][j] = 0LL;
			for (int k = 0; k < 2; k++) {
				ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k]*b.mat[k][j])%mod;
			}
		}
	}
	return ans;
}

Matrix matPow(Matrix base, ll p) {
	Matrix ans = id;
	
	while (p) {
		if (p & 1) {
			ans = matMul(ans, base);
		}
		base = matMul(base, base);
		p >>= 1;
	}
	return ans;
}



void up(int us, int ue, Matrix ch, int ss, int se, int si) {
	// if (lazy[si] > 0) {
		// Matrix mc = matPow(fm, lazy[si]);
		ll tc = (lazy[si].mat[0][0]*top[si] + lazy[si].mat[0][1]*bot[si])%mod;
		ll bc = (lazy[si].mat[1][0]*top[si] + lazy[si].mat[1][1]*bot[si])%mod;
		top[si] = tc % mod;
		bot[si] = bc % mod;
		if (ss != se) {
			lazy[si*2+1] = matMul(lazy[si*2+1], lazy[si]);
			lazy[si*2+2]  = matMul(lazy[si*2+2], lazy[si]);
		}
		lazy[si] = id;
	// }
	if (us > ue || ss > se || us > se || ue < ss) return;
	int mid = (ss+se)/2;
	if (us <= ss && se <= ue) {
		
		ll tc = ch.mat[0][0]*top[si] + ch.mat[0][1]*bot[si];
		ll bc = ch.mat[1][0]*top[si] + ch.mat[1][1]*bot[si];
		top[si] = tc % mod;
		bot[si] = bc % mod;
		if (ss != se) {
			lazy[si*2+1] = matMul(lazy[si*2+1], ch);
			lazy[si*2+2] = matMul(lazy[si*2+2], ch);
		}
		return;
	}
	up(us, ue, ch, ss, mid, si*2+1);
	up(us, ue, ch, mid+1, se, si*2+2);
	top[si] = (top[si*2+1] + top[si*2+2])%mod;
	bot[si] = (bot[si*2+1] + bot[si*2+2])%mod;

}

void update(int low, int high, ll ch) {
	Matrix mc = matPow(fm, ch);
	up(low, high, mc, 1, N, 0);
}

void buildtree(int ss, int se, int si) {
	lazy[si] = id;
	if (ss == se) {
		Matrix mc = matPow(fm, svals[ss]);
		top[si] = mc.mat[1][0];
		bot[si] = mc.mat[1][1];
		return;
	}
	int mid = (ss+se)/2;
	buildtree(ss, mid, si*2+1);
	buildtree(mid+1, se, si*2+2);
	top[si] = (top[si*2+1] + top[si*2+2])%mod;
	bot[si] = (bot[si*2+1] + bot[si*2+2])%mod;;

}

ll qu(int qs, int qe, int ss, int se, int si) {

	ll tc = (lazy[si].mat[0][0]*top[si] + lazy[si].mat[0][1]*bot[si])%mod;
	ll bc = (lazy[si].mat[1][0]*top[si] + lazy[si].mat[1][1]*bot[si])%mod;
	top[si] = tc % mod;
	bot[si] = bc % mod;
	if (ss != se) {
		lazy[si*2+1] = matMul(lazy[si*2+1], lazy[si]);
		lazy[si*2+2]  = matMul(lazy[si*2+2], lazy[si]);
	}
	lazy[si] = id;


	if (qs <= ss && se <= qe) {
		return top[si];
	}
	if (qs > qe || ss > se || qs > se || qe < ss) return 0LL;
	int mid = (ss+se)/2;
	return (qu(qs, qe, ss, mid, si*2+1) + qu(qs, qe, mid+1, se, si*2+2))%mod;
}

ll query(int low, int high) {
	return qu(low, high, 1, N, 0)%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	N = n;
	for (int i = 1; i <= n; i++) {
		cin >> svals[i];
	}
	fm.mat[0][0] = 1LL;
	fm.mat[0][1] = 1LL;
	fm.mat[1][0] = 1LL;
	fm.mat[1][1] = 0LL;

	id.mat[0][0] = 1LL;
	id.mat[1][0] = 0LL;
	id.mat[0][1] = 0LL;
	id.mat[1][1] = 1LL;

	buildtree(1, N, 0);
	int tp, l, r;
	ll x;
	for (int i = 0; i < m; i++) {
		cin >> tp >> l >> r;
		if (tp == 1) {
			cin >> x;
			update(l, r, x);
		}
		else {
			ll ans = query(l, r);
			cout << ans << '\n';
		}
	}
	cin >> n;
}