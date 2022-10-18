#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll mod;
ll M(ll x) {
	x %= mod;
	return x < 0 ? x + mod : x;
}

int N;
vi dom(vector<pii>& a) {
	set<pii> large;
	large.insert(pii(1 << 30, -1));
	vi ret;
	rep(i,0,N) {
		pii v = a[i];
		auto it = large.lower_bound(v);
		ret.push_back(it->second);
		while (it != large.begin()) {
			--it;
			large.erase(it++);
		}
		large.insert(v);
	}
	return ret;
}

ll sol(int i, int left, int right, vi& vals, vector<ll>& mods, vector<vi>& modsc) {
	assert(left <= right);
	// cout << left << ' ' << right << endl;
	ll cur = M(mods[i+1]);
	ll res = 0;
	rep(j,0,left+1) {
		// go j steps to the left. we want to know how many instances of 'cur' are in
		// mods[i+1], ..., mods[i+1+right].
		vi& v = modsc[(int)cur];
		res += ll(upper_bound(all(v), i+1+right) - lower_bound(all(v), i+1));
		/*
		rep(k,0,right+1) {
			if (cur == mods[i+k+1])
				++res;
		}
		*/
		if (j != left)
			cur = (cur + vals[i-1-j]) % mod;
	}
	return res - 1; // exclude (0,0)
}

int main() {
	cin.sync_with_stdio(false);
	cin >> N >> mod;
	vector<pii> a(N);
	vi vals(N), rvals(N);
	rep(i,0,N) {
		int v;
		cin >> v;
		a[i] = pii(v, i);
		vals[i] = v % (int)mod;
		rvals[N-1-i] = v % (int)mod;
	}
	vector<ll> mods(N+1), rmods(N+1);
	mods[N] = rmods[N] = 0;
	for (int i = N; i --> 0; ) {
		mods[i] = (mods[i+1] + vals[i]) % mod;
		rmods[i] = (rmods[i+1] + rvals[i]) % mod;
	}
	vector<vi> modsc((int)mod), rmodsc = modsc;
	rep(i,0,N+1) {
		modsc[mods[i]].push_back(i);
		rmodsc[rmods[i]].push_back(i);
	}

	vi domLeft = dom(a);
	reverse(all(a));
	vi domRight = dom(a);
	reverse(all(domRight));
	trav(x, domRight) if (x == -1) x = N;
	reverse(all(a));

	// trav(x, domLeft) cout << x << ' ' << endl;
	// trav(x, domRight) cout << x << ' ' << endl;
	ll res = 0;
	rep(i,0,N) {
		// Say i is largest.
		int left = i - domLeft[i] - 1;
		int right = domRight[i] - i - 1;
		if (left < right) {
			res += sol(i, left, right, vals, mods, modsc);
		}
		else {
			res += sol(N-1-i, right, left, rvals, rmods, rmodsc);
		}
	}
	cout << res << endl;
}