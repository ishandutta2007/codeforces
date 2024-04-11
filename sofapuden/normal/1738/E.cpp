#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 998244353;
const int mxN = 2e5+5;

ll fac[mxN];

ll pw(ll a, ll b){
	a%=M;
	ll ret = 1;
	while(b){
		if(b&1)ret = ret * a % M;
		a = a * a % M;
		b>>=1;
	}
	return ret;
}

ll inv(ll x){
	return pw(x,M-2);
}

ll ch(ll n, ll k){
	return fac[n] * inv(fac[n-k] * fac[k]) % M;
}

void solve(){
	int n; cin >> n;
	vector<ll> v(n);
	for(auto &x : v)cin >> x;
	ll ret = 1;
	ll su1 = v[0], su2 = v[n-1];
	int lptr = 0, rptr = n-1;
	while(lptr < rptr){
		if(su1 < su2)su1+=v[++lptr];
		else if(su1 > su2)su2+=v[--rptr];
		else{
			int lam = 1, ram = 1;
			while(lptr < rptr-1 && (!v[lptr+1] || !v[rptr-1])){
				if(!v[lptr+1]){lam++;lptr++;}
				else if(!v[rptr-1]){ram++; rptr--;}
			}
			if(lptr == rptr-1){
				ret*=pw(2,lam+ram-1);
				ret%=M;
				break;
			}
			else{
				ll su = 0;
				for(int i = 0; i <= min(lam,ram); ++i){
					su+=ch(lam,i) * ch(ram,i);
					su%=M;
				}
				ret = ret * su % M;
				su1+=v[++lptr];
			}
		}
	}
	cout << ret << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fac[0] = 1;
	for(int i = 1; i < mxN; ++i)fac[i] = fac[i-1] * i % M;
	int t; cin >> t;
	while(t--)solve();
}