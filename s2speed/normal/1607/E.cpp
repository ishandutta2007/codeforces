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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

string s;

void solve(){
	ll n , m , q , x1 , x2 , y1 , y2 , x , y;
	cin>>n>>m>>s; q = sze(s);
	x = y = x1 = x2 = y1 = y2 = 0;
	for(ll i = 0 ; i < q ; i++){
		if(s[i] == 'D'){
			y++;
		}
		if(s[i] == 'U'){
			y--;
		}
		if(s[i] == 'L'){
			x--;
		}
		if(s[i] == 'R'){
			x++;
		}
		if(y - y1 >= n) break;
		if(y2 - y >= n) break;
		if(x - x1 >= m) break;
		if(x2 - x >= m) break;
		y1 = min(y , y1); y2 = max(y , y2);
		x1 = min(x , x1); x2 = max(x , x2);
	}
	cout<<-y1 + 1<<' '<<-x1 + 1<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();	
	return 0;
}