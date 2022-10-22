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

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 1e9;

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

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k , a , b;
	bool rev = false;
	string ans;
	cin>>n>>k>>a>>b;
	if(min(a , b) < n / (k + 1)){
		cout<<"NO\n";
		return 0;
	}
	if(a < b){
		rev = true;
		swap(a , b);
	}
	ll cnt = 0;
	while(a > b){
		if(cnt == k){
			cnt = 0;
			b--;
			ans += 'B';
		} else {
			cnt++;
			ans += 'G';
			a--;
		}
	}
	ll lm = a + b;
	for(ll i = 0 ; i < lm ; i++){
		ans += (i % 2 ? 'G' : 'B');
	}
	if(rev){
		for(ll i = 0 ; i < n ; i++){
			if(ans[i] == 'G'){
				ans[i] = 'B';
			} else {
				ans[i] = 'G';
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/