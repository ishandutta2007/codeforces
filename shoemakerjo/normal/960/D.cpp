#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

ll sz[62];
ll st[62];
ll en[62];

ll myshift[62];
ll pshift[62];


int getlevel(ll val) {
	//slow b/c i don't care
	for (int i = 1; i <= 61; i++) {
		if (en[i] >= val && st[i] <= val) {
			//this is my spot
			return i;
		}
	}
}

ll getpar(ll val) {
	if (val == 1) {
		return -1LL; //no parent for the root
	}
	int lev = getlevel(val);

	ll nv = (val - st[lev] + myshift[lev])%sz[lev];
	nv = nv + st[lev];
	ll pc = nv/2LL; //this is what it would be if relative to parent nothing happened
	//we want to now subtract out our levels parent crap
	pc -= pshift[lev];
	if (pc < st[lev-1]) {
		// cout << "FLAG FLAG FLAG" << endl;
		//amount if flowed below is st[lev-1] - pc
		//thus the amount of nodes from it to the en[lev-1] should be the flow below
		pc = en[lev-1] - (st[lev-1] - pc)+1LL; //should only overflow once
	}
	return pc;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("output.txt", "w", stdout);
	int Q;
	cin >> Q;
	
	st[1] = 1;
	sz[1] = 1;
	for (int i = 2; i <= 61; i++) {
		sz[i] = sz[i-1]*2LL;
		st[i] = st[i-1]*2LL;
		en[i-1] = st[i]-1LL;
	}
	//interestingly, st and sz are actually the same
	int t;
	ll x, k;
	fill(myshift, myshift+62, 0LL);
	fill(pshift, pshift+62, 0LL);
	while (Q--) {
		cin >> t >> x;
		if (t == 1) {
			cin >> k;
			int lev = getlevel(x);
			k = k % sz[lev];
			if (k < 0) {
				k += sz[lev];
			}
			myshift[lev]  = (myshift[lev] + k) % sz[lev];
			pshift[lev+1] = (pshift[lev+1] + k) % sz[lev];
		}
		else if (t == 2) {
			cin >> k;
			int lev = getlevel(x);
			k = k % sz[lev];
			if (k < 0) {
				k += sz[lev];
			}
			myshift[lev]  = (myshift[lev] + k) % sz[lev];
			//no parent shifting here

		}
		else {
			ll cur = x;
			while (cur != -1LL) {
				cout << cur << " ";
				cur = getpar(cur);
			}
			cout << endl; //maybe do '\n' if needed
		}
	}
	cin >> Q;

}