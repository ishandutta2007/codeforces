#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

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

const ll MAXN = 2.5e5 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

bool ch[2][2] , c[] = {false , false};
vector<pll> v;
vector<ll> ans;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ll x , y;
		cin>>x>>y; x += 1e6; y += 1e6;
		v.push_back({x , y});
	}
	while(true){
		ch[0][0] = false;
		ch[0][1] = false;
		ch[1][0] = false;
		ch[1][1] = false;
		c[0] = false;
		c[1] = false;
		for(int i = 0 ; i < n ; i++){
			ch[v[i].first % 2][v[i].second % 2] = true;
			c[(v[i].first + v[i].second) % 2] = true;
		}
		if(c[0] & c[1]){
			for(int i = 0 ; i < n ; i++){
				if(v[i].first % 2 == v[i].second % 2){
					ans.push_back(i + 1);
				}
			}
			cout<<ans.size()<<'\n';
			for(auto i : ans){
				cout<<i<<' ';
			}
			cout<<'\n';
			return 0;
		}
		bool s = 1 , o = false;
		if(c[0]) s = 0;
		if(s){
			o = ch[1][0] & ch[0][1];
		} else {
			o = ch[0][0] & ch[1][1];
		}
		if(o){
			for(int i = 0 ; i < n ; i++){
				if(v[i].second % 2){
					ans.push_back(i + 1);
				}
			}
			cout<<ans.size()<<'\n';
			for(auto i : ans){
				cout<<i<<' ';
			}
			cout<<'\n';
			return 0;
		}
		for(int i = 0 ; i < n ; i++){
			v[i].first /= 2;
			v[i].second /= 2;
		}
	}
	return 0;
}

/*

*/