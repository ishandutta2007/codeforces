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

ll a[100][100];
vector<ll> v;

void solve(){
	ll n , m , ans = 0;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>>a[i][j];
		}
	}
	for(int i = 0 ; i <= (n + 1) / 2 - 1 ; i++){
		for(int j = 0 ; j <= (m + 1) / 2 - 1 ; j++){
			v.clear();
			v.push_back(a[i][j]);
			v.push_back(a[n - i - 1][j]);
			v.push_back(a[i][m - j - 1]);
			v.push_back(a[n - i - 1][m - j - 1]);
			sort(v.begin() , v.end());
			ans += v[1] - v[0] + v[2] - v[1] + v[3] - v[1];
			if((m % 2 == 1 && j == (m + 1) / 2 - 1) || (n % 2 == 1 && i == (n + 1) / 2 - 1)){
				ans -= v[3] - v[1];
			}
		}
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