#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 2e5;

vector<ll> v;
ll l[MAX_N] , r[MAX_N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , k;
		cin>>n>>k;
		v.resize(n);
		for(int i = 0 ; i < n ; i++){
			cin>>v[i];
		}
		for(int i = 0 ; i < n ; i++){
			ll trash;
			cin>>trash;
		}
		sort(v.begin() , v.end());
		if(n == 1){
			cout<<"1\n";
			v.clear();
			continue;
		}
		ll x = 0 , y = 0 , ans = 0;
		for(int i = 0 ; i < n ; i++){
			while(x < n - 1){
				if(v[x] < v[i] - k){
					x++;
				} else {
					break;
				}
			}
			while(y < n - 1){
				if(v[y + 1] <= v[i] + k){
					y++;
				} else {
					break;
				}
			}
			l[i] = i - x + 1; r[i] = y - i + 1;
		}
		for(int i = 1 ; i < n ; i++){
			l[i] = max(l[i] , l[i - 1]);
		}
		for(int i = n - 2 ; i >= 0 ; i--){
			r[i] = max(r[i] , r[i + 1]);
		}
		for(int i = 0 ; i < n - 1 ; i++){
			ans = max(ans , l[i] + r[i + 1]);
		}
		cout<<ans<<"\n";
		v.clear();
	}
	return 0;
}