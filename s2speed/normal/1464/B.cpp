#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
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

ll p[MAX_N];

void solve(){
	string s , h;
	ll a , b , ans = 0 , m = 0 , cnt = 0 , n , q = 0 , o = 1 , x = 0 , u = 0 , y = 0;
	cin>>s>>a>>b;
	n = s.size();
	h = s;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '?'){
			h[i] = '1';
		}
		if(s[i] == '0'){
			cnt++;
		}
	}
	if(a > b){
		reverse(s.begin() , s.end());
		reverse(h.begin() , h.end());
		swap(a , b);
	}
	for(int i = 0 ; i < n ; i++){
		if(h[i] == '0'){
			q++;
		}
		p[i] = q;
		if(h[i] == '0'){
			continue;
		}
		ans += 1ll * a * q;
		ans += 1ll * b * (cnt - q);
	}
	m = ans;
	q = 0;
	for(int x = 0 ; x < n ; x++){
		if(s[x] == '?'){
			ans -= 1ll * a * q;
			ans -= 1ll * b * (cnt - q);
			ans += 1ll * b * (x - q);
			ans += 1ll * a * (n - x - 1 - cnt + q);
			h[x] = '0';
			cnt++;
		}
		if(h[x] == '0'){
			q++;
		}
		m = min(m , ans);
	}
	cout<<m<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	solve();
	return 0;
}