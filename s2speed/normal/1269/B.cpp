#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 2020;

vector<ll> a , b , c;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	bool ch;
	ll n , m , ans = 1e18;
	cin>>n>>m;
	a.resize(n); b.resize(n); c.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin>>b[i];
	}
	sort(a.begin() , a.end());
	sort(b.begin() , b.end());
	for(int i = 0 ; i < n ; i++){
		ch = true;
		ll o = b[i] - a[0] + m;
		o %= m;
		for(int j = 0 ; j < n ; j++){
			c[j] = a[j] + o; c[j] %= m;
		}
		sort(c.begin() , c.end());
		for(int j = 0 ; j < n ; j++){
			if(c[j] != b[j]){
				ch = false;
				break;
			}
		}
		if(ch){
			ans = min(ans , o);
		}
	}
	cout<<ans<<"\n";
	return 0;
}