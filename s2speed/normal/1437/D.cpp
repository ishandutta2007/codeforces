#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 2e5;

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

ll a[MAX_N];

void solve(){
	bool nw;
	ll n , h = 0 , f = 1 , ans = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll x = 0;
	while(x < n - 1){
		nw = true;
		ans++;
		h = f;
		f = 0;
		for(int i = x + 1 ; i < n && h > 0 ; i++){
//			cout<<i<<"\n";
			f++;
			if(nw){
				nw = false;
				continue;
			}
			if(a[i] < a[i - 1]){
				h--;
			}
			if(h == 0){
				f--;
			}
		}
		x += f;
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}