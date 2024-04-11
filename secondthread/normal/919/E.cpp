#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

namespace CRT {
	ll fastpow(ll base, ll exp, ll mod) {
		if (exp==0) return 1;
		ll half=fastpow(base, exp/2, mod);
		if (exp%2==0) return half*half%mod;
		return half*half%mod*base%mod;
	}
	ll modInv(ll base, ll mod) {
		return fastpow(base, mod-2, mod);
	}
	ll gcd(ll a, ll b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}

	//finds x where x=a[i] (mod m[i])
	ll solveCRT(vector<ll> a, vector<ll> m) {
		ll A=a[0], M=m[0];
		for (int i=1; i<(int)a.size(); i++) {
			if (A<a[i]) {
				swap(A, a[i]);
				swap(M, m[i]);
			}
			ll g=gcd(M, m[i]), diff=a[i]-A;
			if (diff%g!=0) return -1; //no solutions
			ll MOD=M*m[i]/g;
			ll tmp=modInv(M/g, m[i]/g)*(diff/g)%MOD;
			A=(tmp*M+A)%MOD;
			M=MOD;
		}
		if (A<0) A+=M;
		return A;
	}
};

int main() {
	ll a, b, p, x; cin>>a>>b>>p>>x;
	vector<int> indexInCycle(p, -1);
	vector<int> cycleLength(p, -1);
	vector<int> cycle(p, -1);
	for (int cycleStart=0; cycleStart<p; cycleStart++) {
		int curLength=0, curIndex=cycleStart;
		while (indexInCycle[curIndex]==-1) {
			indexInCycle[curIndex]=curLength++;
			cycle[curIndex]=cycleStart;
			curIndex=(int)(curIndex*a%p);
		}
		curIndex=cycleStart;
		while (cycleLength[curIndex]==-1) {
			cycleLength[curIndex]=curLength;
			curIndex=(int)(curIndex*a%p);
		}
	}
	ll ans=0;
	for (ll k=1; k<p; k++) {
		//cout<<"k: "<<k<<endl;
		ll inv=(b*CRT::modInv(k, p))%p;
		if (cycle[inv]!=1) continue;

		ll posInCycle=indexInCycle[inv], cycLen=cycleLength[1];
		vector<ll> vals, mods;
		vals.push_back(k); mods.push_back(p);
		vals.push_back(posInCycle); mods.push_back(cycLen);

		ll indexInFinal=CRT::solveCRT(vals, mods);
		indexInFinal%=p*(cycLen);
		ans+=x/(p*cycLen) + ((indexInFinal<=x%(p*cycLen))?1:0);
	}
	cout<<ans<<endl;
	return 0;
}