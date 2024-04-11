#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1;

ll K, N;

ll calc(ll x){
	if(x<=1)	return N;
	if(x%2){
		ll two = 1;
		ll ret = 0;
		while(1){
			if(x*two+two-1<=N){
				ret += two;
				two*=2;
				continue;
			}
			ll s = 0, e = two-1, m;
			while(s<e){
				m = (s+e)/2;
				if(x*two+m>N){
					e = m;
				}else{
					s = m+1;
				}
			}
			ret += s;
			break;
		}
		return ret;
	}else{
		ll two = 1;
		ll ret = 0;
		while(1){
			if(x*two+two*2-1<=N){
				ret += two*2;
				two*=2;
				continue;
			}
			ll s = 0, e = two*2-1, m;
			while(s<e){
				m = (s+e)/2;
				if(x*two+m>N){
					e = m;
				}else{
					s = m+1;
				}
			}
			ret += s;
			break;
		}
		return ret;
	}	
}

int main(){
	cin>>N>>K;
	ll s = 0, e = N/2, m;
	while(s<e){
		m = (s+e)/2+1;
		if(calc(2*m)>=K){
			s = m;
		}else{
			e = m-1;
		}
	}
	if(calc(2*s+1)>=K){
		cout<<2*s+1;
	}else{
		cout<<2*s;
	}
	return 0;
}