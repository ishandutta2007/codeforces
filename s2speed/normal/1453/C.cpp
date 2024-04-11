#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 2000 + 20;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

vector<ll> sot[MAX_N][10] , sat[MAX_N][10];
ll a[10] , b[10] , c[10] , d[10];
// a = min y , b = max y , c = min x , d = max x

void solve(){
	ll n;
	cin>>n;
	for(int i = 0 ; i < 10 ; i++){
		a[i] = 2001;
		b[i] = -1;
		c[i] = 2001;
		d[i] = -1;
		for(int j = 0 ; j < n ; j++){
			sot[j][i].clear();
			sat[j][i].clear();
		}
	}
	for(ll i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		for(ll j = 0 ; j < n ; j++){
			ll dg = s[j] - '0';
			sot[j][dg].push_back(i);
			sat[i][dg].push_back(j);
			a[dg] = min(a[dg] , i);
			b[dg] = max(b[dg] , i);
			c[dg] = min(c[dg] , j);
			d[dg] = max(d[dg] , j);
		}
	}
	for(int q = 0 ; q < 10 ; q++){
		if(b[q] == -1){
			cout<<"0 ";
			continue;
		}
		ll ans = 0;
		for(int i = 0 ; i < n ; i++){
			if(!sot[i][q].size()){
				continue;
			}
			ll h , o;
			o = max(d[q] - i , i - c[q]);
			h = sot[i][q][sot[i][q].size() - 1] * o;
			ans = max(ans , h);
			h = (n - sot[i][q][0] - 1) * o;
			ans = max(ans , h);
		}
		for(int i = 0 ; i < n ; i++){
			if(!sat[i][q].size()){
				continue;
			}
			ll h , o;
			o = max(b[q] - i , i - a[q]);
			h = sat[i][q][sat[i][q].size() - 1] * o;
			ans = max(ans , h);
			h = (n - sat[i][q][0] - 1) * o;
			ans = max(ans , h);
		}
		cout<<ans<<' ';
	}
	cout<<'\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}