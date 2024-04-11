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
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 15 , md = 998244353 , inf = 1e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

ll sw[26];
bitset<26> o;
vector< pair<char , char> > ans;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(sw , -1 , sizeof(sw));
	string s , t;
	cin>>s>>t;
	ll n = s.size();
	for(ll i = 0 ; i < n ; i++){
		ll a = s[i] - 'a' , b = t[i] - 'a';
		if(s[i] != t[i]){
			if(o[a] || o[b]){
				cout<<"-1\n";
				return 0;
			}
			if(sw[a] != -1){
				if(sw[a] != b){
					cout<<"-1\n";
					return 0;
				}
			} else {
				sw[a] = b;
			}
			if(sw[b] != -1){
				if(sw[b] != a){
					cout<<"-1\n";
					return 0;
				}
			} else {
				sw[b] = a;
			}
		} else {
			o[a] = true;
			if(sw[a] != -1){
				cout<<"-1\n";
				return 0;
			}
		}
	}
	for(ll i = 0 ; i < 26 ; i++){
		if(sw[i] > i){
			char c = i + 'a' , y = sw[i] + 'a';
			ans.push_back({c , y});
		}
	}
	cout<<ans.size()<<'\n';
	for(auto p : ans){
		cout<<p.first<<' '<<p.second<<'\n';
	}
	return 0;
}

/*

*/