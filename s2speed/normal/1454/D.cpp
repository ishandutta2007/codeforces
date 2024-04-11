#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 1e5 + 20;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

bool gh[MAX_N];
vector<ll> p;

void gh_build(){
	for(int i = 0 ; i < MAX_N ; i++){
		gh[i] = true;
	}
	gh[0] = false;
	gh[1] = false;
	for(int i = 2 ; i < MAX_N ; i++){
		if(gh[i]){
			p.push_back(i);
			for(int j = 2 * i ; j < MAX_N ; j += i){
				gh[j] = false;
			}
		}
	}
}

void solve(){
	ll n , ans , m = 1;
	cin>>n; ans = n;
	for(auto i : p){
		ll h = n , c = 0;
		while(h % i == 0){
			h /= i;
			c++;
		}
		if(c > m){
			ans = i;
			m = c;
		}
	}
	cout<<m<<"\n";
	ll h = ans * ans;
	while(n % h == 0){
		cout<<ans<<" ";
		n /= ans;
	}
	cout<<n<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	gh_build();
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}