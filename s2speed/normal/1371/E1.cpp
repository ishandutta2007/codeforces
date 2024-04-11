#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll z = 0;

vector<ll> v , ans;
ll n , p;

ll f(ll k){
	ll ans = 1;
	for(int i = 1 ; i <= n ; i++){
		ans *= min(n , n - (v[n - i] - k)) - (i - 1);
		ans %= p;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll h , as;
	cin>>n>>p;
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		v.push_back(h);
	}
	sort(v.begin() , v.end());
	for(int i = max(z , v[n - 1] - n + 1) ; i < v[n - 1] ; i++){
		if(f(i) % p != 0){
			ans.push_back(i);
		}
	}
	sort(ans.begin() , ans.end());
	as = ans.size();
	cout<<as<<"\n";
	for(int i = 0 ; i < as ; i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}