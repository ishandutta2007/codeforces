#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 500010

ll rel[maxn]; //initial reliability
ll sub[2*maxn]; //to be used in the binary search code
ll addon[2*maxn]; // only in initial guy
int n, r;
ll k;

bool check(ll cur) {

	//can we get to at least cur for everything

	ll cv = 0LL;
	for (int i = 0; i <= n; i++) {
		sub[i] = 0LL; //just a manual fill
	}
	ll kleft = k; //the amount left at start is everything
	for (int i = 1; i <= n; i++) {
		cv -= sub[i]; //what is no longer active
		assert(cv >= 0LL);
		if (cv + rel[i] < cur) { //the reliability of this point now
			ll cadd = cur-(cv+rel[i]);
			kleft -= cadd; //subtract out what he had to add here
			cv += cadd;
			int en = min(n, i+2*r); //last guy we affect
			sub[en+1] += cadd; //no longer active here

		}
		if (kleft < 0) return false; //maybe overflow here
	}
	if (kleft >= 0LL) return true;
	return false; //see if we overused archers
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> r >> k;

	ll val;
	fill(sub, sub+2*maxn, 0LL);
	fill(addon, addon+2*maxn, 0LL);
	ll ksum = 0LL; //total number of archers seen at beginning
	for (int i = 1; i <= n; i++) {
		cin >> val;
		int st = max(i-r, 1);
		addon[st] += val;
		int en = min(n, i+r);
		sub[en+1] += val;
		ksum += val+0LL; //contribute to the whole
	}
	fill(rel, rel+maxn, 0LL); // just a precaution

	ll cv = 0LL; //curvalue
	for (int i = 1; i <= n; i++) {
		cv += addon[i];
		cv -= sub[i];
		rel[i] = cv;
		assert(cv >= 0LL);
		// cout << "rel  " << i << " " << rel[i] << endl;
	}

	ll lo = 0LL;
	ll hi = k+ksum; 
	// assert(hi <= 2000000000000000000LL);
	hi = 2000000000000000000LL; // bump it up just in case
								//somehow this causes it to fail
								//this should work 
	while (lo < hi) {
		ll diff = hi-lo; //try to prevent overflow
		ll mid = lo + (diff+1LL)/2LL;
		// cout << "checking  " << mid << endl;
		if (check(mid)) { //this is attainable
			lo = mid;
		}
		else {
			hi = mid-1LL; //can't even get this thing
		}
	}
	assert(lo == hi); 
	assert(check(lo+1) == false); //somehow this evaluates  and still gets WA
	assert(check(lo));
	//somehow the binary search can find different answers and still say 
	//    each is ok. this does not make sense (the bin search should satisfy
	//    binary search condition regardless)

	cout << lo << endl;
	cin >> n;
}