#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 0;

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

ll n;
vector<ll> a;
ll x[201];

ll mof(int e){
	ll cnt = 1 , q = n;
	if(x[e] >= a[e]){
		return -1;
	}
	for(int i = e + 1 ; i <= n ; i++){
		if(x[i] > x[i - 1] + 1){
			q = i - 1;
			break;
		}
		if(x[i] < a[i]){
			cnt++;
		} else {
			cnt--;
		}
	}
	if(cnt < 0){
		return -1;
	}
	return q;
}

void solve(){
	ll ans = 0;
	cin>>n;
	a.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	a.push_back(-1);
	for(int i = 1 ; i <= n ; i++){
		x[i] = i;
	}
	sort(a.begin() , a.end());
	while(x[n] < a[n]){
		x[n]++;
	}
	for(int i = n - 1 ; i > 0 ; i--){
		while(x[i] < x[i + 1] - 1 && x[i] < a[i]){
			x[i]++;
		}
		if(x[i] == x[i + 1] - 1){
			while(mof(i) > -1){
				ll q = mof(i);
				for(int j = i ; j <= q ; j++){
					x[j]++;
				}
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		ll h = a[i] - x[i];
//		cout<<x[i]<<" ";
		if(h < 0){
			h = 0 - h;
		}
		ans += h;
	}
	cout<<ans<<"\n";
	a.clear();
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