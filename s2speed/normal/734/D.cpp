#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e5 + 16 , md = 1e9 + 7 , inf = 5e18;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

ll x[maxn] , y[maxn] , t[maxn];
vector<plll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , a , b;
	cin>>n>>a>>b;
	for(ll i = 0 ; i < n ; i++){
		char c;
		cin>>c>>x[i]>>y[i];
		if(c == 'B') t[i] = 1;
		if(c == 'R') t[i] = 2;
		if(c == 'Q') t[i] = 3;
	}
	v.push_back({{a , b} , 0});
	for(ll i = 0 ; i < n ; i++){
		v.push_back({{x[i] , y[i]} , t[i]});
	}
	sort(all(v));
	for(ll i = 0 ; i <= n ; i++){
		if(v[i].second) continue;
		if(i){
			if(v[i - 1].first.first == a && v[i - 1].second & 2){
				cout<<"YES\n";
				return 0;
			}
		}
		if(i < n){
			if(v[i + 1].first.first == a && v[i + 1].second & 2){
				cout<<"YES\n";
				return 0;
			}
		}
		break;
	}
	v.clear();
	v.push_back({{b , a} , 0});
	for(ll i = 0 ; i < n ; i++){
		v.push_back({{y[i] , x[i]} , t[i]});
	}
	sort(all(v));
	for(ll i = 0 ; i <= n ; i++){
		if(v[i].second) continue;
		if(i){
			if(v[i - 1].first.first == b && v[i - 1].second & 2){
				cout<<"YES\n";
				return 0;
			}
		}
		if(i < n){
			if(v[i + 1].first.first == b && v[i + 1].second & 2){
				cout<<"YES\n";
				return 0;
			}
		}
		break;
	}
	v.clear();
	v.push_back({{a - b , a} , 0});
	for(ll i = 0 ; i < n ; i++){
		v.push_back({{x[i] - y[i] , x[i]} , t[i]});
	}
	sort(all(v));
	for(ll i = 0 ; i <= n ; i++){
		if(v[i].second) continue;
		if(i){
			if(v[i - 1].first.first == a - b && v[i - 1].second & 1){
				cout<<"YES\n";
				return 0;
			}
		}
		if(i < n){
			if(v[i + 1].first.first == a - b && v[i + 1].second & 1){
				cout<<"YES\n";
				return 0;
			}
		}
		break;
	}
	v.clear();
	v.push_back({{a + b , a} , 0});
	for(ll i = 0 ; i < n ; i++){
		v.push_back({{x[i] + y[i] , x[i]} , t[i]});
	}
	sort(all(v));
	for(ll i = 0 ; i <= n ; i++){
		if(v[i].second) continue;
		if(i){
			if(v[i - 1].first.first == a + b && v[i - 1].second & 1){
				cout<<"YES\n";
				return 0;
			}
		}
		if(i < n){
			if(v[i + 1].first.first == a + b && v[i + 1].second & 1){
				cout<<"YES\n";
				return 0;
			}
		}
		break;
	}
	cout<<"NO\n";
	return 0;
}