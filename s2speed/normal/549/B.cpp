#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e2 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

vector<ll> ans;
ll adj[MAXN][MAXN] , cnt[MAXN] , a[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < n ; j++){
			char c;
			cin>>c;
			adj[i][j] = c - '0';
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll q = 0 ; q < n ; q++){
		bool ch = true;
		for(ll i = 0 ; i < n && ch ; i++){
			if(a[i] == cnt[i]){
				ans.push_back(i);
				for(ll j = 0 ; j < n ; j++){
					cnt[j] += adj[i][j];
				}
				ch = false;
			}
		}
		if(ch) break;
	}
	cout<<ans.size()<<'\n';
	for(auto i : ans){
		cout<<i + 1<<' ';
	}
	return 0;
}

/*

*/