#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1e5;

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

ll ans[MAX_N];
vector<ll> v;

void solve(){
	ll n , h , counter = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		v.push_back(h);
	}
	sort(v.begin() , v.end());
//	cout<<(n - 1) / 2<<"\n";
	ll x = n / 2 , y = 0;
	for(int i = 0 ; i < n ; i++){
		if(i % 2 == 0){
			ans[i] = v[x];
			x++;
		} else {
			ans[i] = v[y];
			y++;
		}
	}
	for(int i = 1 ; i < n - 1 ; i++){
		if(ans[i] < ans[i - 1] && ans[i] < ans[i + 1]){
			counter++;
			i++;
		}
	}
	cout<<counter<<"\n";
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}