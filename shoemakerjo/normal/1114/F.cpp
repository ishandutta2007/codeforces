#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxn = 400010;
const int mod = 1000000007;
int n, q;
int nums[maxn];

ll mult(ll a, ll b) {
	return a*b%mod;
}

bool isprime(int u) {
	for (int i = 2; i *i <= u; i++) {
		if (u% i == 0)  return false;
	}
	return true;
}

vector<int> primes;

ll segm[maxn*4];
ll lazym[maxn*4];
ll segc[maxn*4];
ll lazyc[maxn*4];

ll frac[maxn]; //store (p-1) / p for every value p

ll modpow(ll u, ll p) {
	if (p == 0) return 1LL;
	if (p%2 == 0) {
		ll tmp = modpow(u, p/2);
		return mult(tmp, tmp);
	}
	ll tmp = modpow(u, p-1);
	return mult(tmp, u);
}

ll inv(ll u) {
	return modpow(u, mod-2);
}

void buildtree(int ss = 1, int se = n, int si = 0) {
	lazym[si] = 1;
	if (ss == se) {
		segm[si] = nums[ss];
		for (int i = 0; i < primes.size(); i++) {
			if (nums[ss] % primes[i] == 0) {
				segc[si] |= (1LL << i);
			}
		}
		return;
	}
	int mid = (ss+se)/2;
	buildtree(ss, mid, si*2+1);
	buildtree(mid+1, se, si*2+2);
	segm[si] = mult(segm[si*2+1], segm[si*2+2]);
	segc[si] = segc[si*2+1] | segc[si*2+2];
}

void delaze(int ss, int se, int si) {
	if (lazym[si] > 1) {
		segm[si] = mult(segm[si], modpow(lazym[si], se-ss+1LL));
		if (ss != se) {
			lazym[si*2+1] = mult(lazym[si*2+1], lazym[si]);
			lazym[si*2+2] = mult(lazym[si*2+2], lazym[si]);
		}
		lazym[si] = 1;
	}
	segc[si] |= lazyc[si];
	if (ss != se) {
		lazyc[si*2+1] |= lazyc[si];
		lazyc[si*2+2] |= lazyc[si];
	}
	lazyc[si] = 0;
}

ll cmask;
ll cmult;

void update(int us, int ue, ll val, int ss = 1, int se = n, int si = 0) {
	delaze(ss, se, si);
	if (us > ue || ss > se || ue < ss || us > se) return;
	if (us <= ss && se <= ue) {
		// cout << ss << "   to    " << se << '\n';

		lazyc[si] |= cmask;
		lazym[si] = mult(lazym[si], val);
		delaze(ss, se, si);
		return;
	}
	int mid = (ss+se)/2;
	update(us, ue, val, ss, mid, si*2+1);
	update(us, ue, val, mid+1, se, si*2+2);
	segm[si] = mult(segm[si*2+1], segm[si*2+2]);
	segc[si] = segc[si*2+1] | segc[si*2+2];
}

void query(int qs, int qe, int ss = 1, int se = n, int si = 0) {
	delaze(ss, se, si);
	if (qs > qe || ss > se || qs > se || qe < ss) return;
	if (qs <= ss && se <= qe) {
		cmask |= segc[si];
		cmult = mult(cmult, segm[si]);
		return;
	}
	int mid = (ss + se)/2;
	query(qs, qe, ss, mid, si*2+1);
	query(qs, qe, mid+1, se, si*2+2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 2; i <= 300; i++) {
		if (isprime(i)) primes.push_back(i);
	}
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	buildtree();


	for (int i = 0; i < primes.size(); i++) {
		frac[i] = mult(primes[i]-1LL, inv(primes[i]));
	}

	string tp;
	int l, r;
	ll x;
	while (q--) {
		cin >> tp >> l >> r;
		if (tp[0] == 'M') {
			cin >> x;
			cmask = 0;
			for (int i = 0; i < primes.size(); i++) {
				if (x % primes[i] == 0) {
					cmask |= (1LL << i);
					// cout << " !!! " << primes[i] << '\n';
				}
			}
			update(l, r, x);
		}
		else {
			cmask = 0;
			cmult = 1LL;
			query(l, r);


			// cout << "    " << cmult << '\n';
			for (int i = 0; i < primes.size(); i++) {
				if (cmask & (1LL << i)) {
					cmult = mult(cmult, frac[i]);
				}
			}


			cout << cmult << '\n';
		}
	}
	cout.flush();

}