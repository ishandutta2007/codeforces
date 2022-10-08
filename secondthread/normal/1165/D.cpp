#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const ll maxn=1000001;
bool prime[maxn];
ll timesUsed[maxn];

void precomp() {
	for (ll i=0; i<maxn; i++) prime[i]=true;
	for (ll i=2; i<maxn; i++) {
		if (!prime[i]) continue;
		for (ll j=i*(ll)i; j<maxn; j+=i)
			prime[j]=false;
	}
	prime[0]=prime[1]=false;
}

int main() {
	precomp();
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll T; cin>>T;

	for (ll tt=1; tt<=T; tt++) {
		ll nDivs; cin>>nDivs;
		vector<ll> divs;
		vector<ll> primeDivs;
		for (ll i=0; i<nDivs; i++) {
			ll temp; cin>>temp;
			divs.push_back(temp);
			if (prime[temp]) {
				primeDivs.push_back(temp);
				timesUsed[temp]=1;
			}
		}
		sort(divs.begin(), divs.end());
		bool possible=true;

		for (ll i=0; i<nDivs; i++) {
			ll considering=divs[i];
			for (ll prime=0; prime<primeDivs.size(); prime++) {
				ll divTimes=0;
				while (considering%primeDivs[prime]==0) {
					divTimes++;
					considering/=primeDivs[prime];
				}
				timesUsed[primeDivs[prime]]=max(timesUsed[primeDivs[prime]], divTimes);
			}
			if (considering!=1)
				possible=false;
		}
		ll prod=1;
		if (primeDivs.size()==0) {
			possible=false;
		}
		else if (primeDivs.size()==1) {
			prod=divs[nDivs-1]*(ll)primeDivs[0];
			possible&=(timesUsed[primeDivs[0]]==divs.size());
			for (ll &i:divs) {
				if (prod%i!=0) possible=false;
			}
		}
		else {
			if (prod>1e12)
				possible=false;
			ll nFactors=1;
			for (ll &prime:primeDivs) {
				nFactors*=timesUsed[prime]+1;
				if (nFactors>300) possible=false;

				for (ll i=0; i<timesUsed[prime]; i++) {
					prod*=prime;
					if (prod>1e12) possible=false;
				}
			}
			possible&=(nFactors-2==nDivs);
			for (ll &i:divs) {
				if (prod%i!=0) possible=false;
			}
		}
		if (find(divs.begin(), divs.end(), prod)!=divs.end())
			possible=false;

		if (!possible) {
			cout<<-1<<'\n';
		}
		else {
			cout<<prod<<'\n';
		}
	}
	return 0;
}