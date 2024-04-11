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

const ll MAXN = 4e2 + 15 , md = 1e9 + 7 , inf = 1e9;

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

void solve(){
	string s;
	cin>>s;
	ll n = s.size() , h = 0;
	ll cnt[] = {0 , 0 , 0};
	char d;
	ll p , e;
	if(s[0] == s[n - 1]){
		cout<<"NO\n";
		return;
	}
	for(ll i = 0 ; i < n ; i++){
		cnt[s[i] - 'A']++;
	}
	if(cnt[0] == n / 2){
		d = 'A';
	}
	if(cnt[1] == n / 2){
		d = 'B';
	}
	if(cnt[2] == n / 2){
		d = 'C';
	}
	if(s[0] == d){
		p = 1;
		e = -1;
	} else {
		p = -1;
		e = 1;
	}
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == d){
			h += p;
		} else {
			h += e;
		}
		if(h < 0){
			cout<<"NO\n";
			return;
		}
	}
	if(h != 0){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*
3 3 3 1
1 2 7 2
1 3 3 1
2 3 7 2
2
1 5
1 7
*/