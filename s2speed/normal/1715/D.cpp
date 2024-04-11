#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 17 , md = 1e9 + 7 , inf = 2e16;

short int a[maxn][30];
vector<int> adj[maxn][30];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(a , -1 , sizeof(a));
	ll n , q;
	cin>>n>>q;
	for(ll e = 0 ; e < q ; e++){
		ll i , j , x;
		cin>>i>>j>>x; i--; j--;
		if(i == j){
			for(ll k = 0 ; k < 30 ; k++){
				a[i][k] = (bool)(x & (1 << k));
			}
			continue;
		}
		for(ll k = 0 ; k < 30 ; k++){
			if(x & (1 << k)){
				adj[i][k].push_back(j); adj[j][k].push_back(i);
			} else {
				a[i][k] = a[j][k] = 0;
			}
		}
	}
	for(ll j = 0 ; j < 30 ; j++){
		for(ll i = 0 ; i < n ; i++){
			if(a[i][j] != -1) continue;
			a[i][j] = 0;
			for(auto k : adj[i][j]){
				if(a[k][j] == 0){
					a[i][j] = 1;
					break;
				}
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		ll h = 0;
		for(ll j = 0 ; j < 30 ; j++){
			if(a[i][j]) h += (1 << j);
		}
		cout<<h<<' ';
	}
	cout<<'\n';
	return 0;
}