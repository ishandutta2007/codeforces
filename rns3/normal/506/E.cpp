// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 10007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

const int P = 200;
const int R = 3;

const int MAX = 1000010;
ll inv[MAX];
ll invfact[MAX];
void getinv(ll n){
	inv[1] = 1;
	rep2(i, 2, n + 1){
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	}
}

ll extgcd(ll a, ll b, ll& x, ll& y){
	ll d = a;
	if(b) d = extgcd(b, a%b, y, x), y -= (a / b) * x;
	else x = 1, y = 0;
	return d;
}

ll mod_inverse(ll a, ll m){
	ll x, y;
	extgcd(a, m, x, y);
	return ((ll)m + x % m) % m;
}

ll r[R],s[R];

ll nCr[P+2][P+2];

vector<ll> mul(vector<ll>& a, vector<ll>& b){
	int n = sz(a) - 1, m = sz(b) - 1;
	vector<ll> res(n + m + 1);
	rep(i,n+1) rep(j,m+1){
		res[i+j] += a[i] * b[j] % MOD;
	}
	rep(i,sz(res)){
		res[i] %= MOD;
	}
	return res;
}

ll mod_pow(ll x,ll n){
	ll res = 1;
	while(n){
		if(n & 1) res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}

int offset;
ll p24[P+1], p25[P+1], p26[P+1];

vector<ll> a[R][P+2];
ll b[R][P+2];
ll p[P+2][P+2];

vector<ll> c[P+2];

int n, l;
string str;

int dp[P][P][P+1];

int f(int left, int right, int n24){
	int& res = dp[left][right][n24];
	if(res != -1) return res;
	res = 0;

	if(left == right){
		if(n24 == 0) res = 1;
	}
	else{
		if(str[left] == str[right]){
			if(left + 1 == right){
				if(n24 == 0) res = 1;
			}
			else{
				res = f(left + 1, right - 1, n24);
			}
		}else{
			if(n24 > 0){
				res = f(left + 1, right, n24 - 1) + f(left, right - 1, n24 - 1);
			}
		}
	}

	return res %= MOD;
}

int calc(int n0, int n1, int n2){
	ll p[P+1] = {}, pc = 0;
	ll pn0[P+1] = {1};
	rep(i,l) pn0[i+1] = pn0[i] * n0 % MOD;

	rep(i,n2){
		rep(j,i+1){
			p[j] += c[n2-1][i] * a[0][i][j];
		}
		pc += c[n2-1][i] * b[0][i];
	}
	rep(i,n2){
		p[i] %= MOD;
	}
	pc %= MOD;

	if(n1 == 0){
		ll res = pc * p26[n0 - offset];
		rep(i,n2){
			res += p[i] * pn0[i] * p25[n0 - offset];
		}
		return res * invfact[n2-1] % MOD;
	}

	vector<ll> q(n2);
	rep(i,n2){
		rep(j,i+1){
			q[j] += nCr[i][j] * p[i] * pn0[i - j] * (j % 2 ? (MOD - 1) : 1);
		}
	}
	rep(i,n2){
		q[i] %= MOD;
	}

	ll d[P+1] = {}, dc = 0;
	rep(i,n1){
		rep(j,i+1){
			d[j] += c[n1-1][i] * a[1][i][j];
		}
		dc += c[n1-1][i] * b[1][i];
	}
	rep(i,n1){
		d[i] %= MOD;
	}
	dc %= MOD;
	ll res1 = dc * p26[n0 - offset];
	rep(i,n1){
		res1 += d[i] * pn0[i] * p24[n0 - offset];
	}
	res1 %= MOD;

	q = mul(q, c[n1-1]);
	ll e[P+1] = {}, ec = 0;
	rep(i,sz(q)){
		rep(j,i+1){
			e[j] += q[i] * a[2][i][j];
		}
		ec += q[i] * b[2][i];
	}
	rep(i,sz(q)){
		e[i] %= MOD;
	}
	ec %= MOD;
	ll res2 = ec * p25[n0 - offset];
	rep(i,sz(q)){
		res2 += e[i] * pn0[i] * p24[n0 - offset] % MOD;
	}
	return (res1 * pc + res2) * invfact[n1-1] * invfact[n2-1] % MOD;
}

ll calc2(int n0, int n1, int n2){
	if(n1 == 0){
		ll res = p25[n0 - offset];
		rep(i,n2-1){
			res = res * (n0 + i + 1) % MOD;
		}
		return res * invfact[n2-1] % MOD;
	}

	ll p[P+1] = {}, pc = 0;
	ll pn0[P+1] = {1};
	rep(i,l) pn0[i+1] = pn0[i] * n0 % MOD;

	vector<ll> v = c[n1-1];
	rep(i,n2-1){
		vector<ll> w{n0+i+1, MOD-1};
		v = mul(v, w);
	}

	rep(i,sz(v)){
		rep(j,i+1){
			p[j] += v[i] * a[2][i][j];
		}
		pc += v[i] * b[2][i];
	}
	rep(i,sz(v)){
		p[i] %= MOD;
	}
	pc %= MOD;
	ll res = pc * p25[n0 - offset];
	rep(i,sz(v)){
		res += p[i] * pn0[i] * p24[n0 - offset] % MOD;
	}
	return res * invfact[n1-1] * invfact[n2-1] % MOD;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> str >> n;
	l = sz(str);
	n += l;
	int m = (n + 1) / 2;

	getinv(P+1);
	invfact[0] = 1;
	rep(i,P) invfact[i+1] = invfact[i] * inv[i+1] % MOD;
	r[0] = 25 * inv[26] % MOD;
	r[1] = 24 * inv[26] % MOD;
	r[2] = 24 * inv[25] % MOD;
	rep(i,R){
		s[i] = mod_inverse(r[i] - 1, MOD);
	}
	rep(i,P+2)rep(j,i+1){
		if(j == 0 || j == i) nCr[i][j] = 1;
		else nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
	}
	offset = max(0, m - l);
	p24[0] = mod_pow(24, offset);
	p25[0] = mod_pow(25, offset);
	p26[0] = mod_pow(26, offset);
	rep(j,P){
		p24[j+1] = p24[j] * 24 % MOD;
		p25[j+1] = p25[j] * 25 % MOD;
		p26[j+1] = p26[j] * 26 % MOD;
	}

	rep(I,R){
		a[I][0].resize(1); a[I][0][0] = r[I] * s[I] % MOD;
		b[I][0] = (MOD - 1) * s[I] % MOD;
		rep2(i,1,P+1){
			a[I][i].clear(); b[I][i] = 0; a[I][i].resize(i+1);
			a[I][i][i] = r[I];
			rep(j,i){
				rep(k,j+1){
					a[I][i][k] += ((i - j) % 2 ? MOD - a[I][j][k] : a[I][j][k]) * nCr[i][j];
				}
				b[I][i] += ((i - j) % 2 ? MOD - b[I][j] + (j == 0) : b[I][j] + MOD - (j == 0)) * nCr[i][j];
			}
			rep(j,i+1){
				a[I][i][j] = a[I][i][j] * s[I] % MOD;
			}
			b[I][i] = b[I][i] * s[I] % MOD;
		}
	}

	c[0].resize(1); c[0][0] = 1;
	rep2(i,1,P+1){
		vector<ll> v{i, 1};
		c[i] = mul(c[i-1], v);
	}

	memset(dp,-1,sizeof(dp));
	ll ans = 0;
	rep(n24, l){
		int n25 = (l - n24 + 1) / 2;
		bool last25_double = (l - n24) % 2 == 0;
		int n26 = m - n24 - n25;
		if(n26 < 0) continue;
		int ways = f(0, l-1, n24);
		ans += ways * calc(n26, n24, n25);
		if(n % 2 == 1 && last25_double){
			ans += MOD * MOD - ways * calc2(n26, n24, n25);
		}
	}
	cout << ans % MOD << endl;
}