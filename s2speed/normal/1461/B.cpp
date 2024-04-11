#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
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

string s[505];
ll o[505][505];

void solve(){
	ll n , m , ans = 0;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		cin>>s[i]; s[i] += '.';
		for(int j = 0 ; j < m ; j++){
			o[i][j] = 0;
			if(s[i][j] == '*'){
				o[i][j]++;
				if(i == 0){
					ans += o[i][j];
					continue;
				}
				int d = 1;
				for(int x = j + 1 ; x < m ; ){
					if(s[i][x] == '.'){
						break;
					}
					x++;
					if(s[i][x] == '.'){
						break;
					}
					x++;
					if(o[i - 1][j + 1] >= d){
						o[i][j]++;
						d++;
					}
				}
			}
			ans += o[i][j];
		}
	}
	cout<<ans<<'\n';
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