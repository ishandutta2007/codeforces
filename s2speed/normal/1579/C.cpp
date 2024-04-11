#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 20 , md = 1e9 + 7 , inf = 2e16;

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

ll n , m , k;
bitset<maxn> mark[maxn] , a[maxn];

bool b(ll i , ll j){
	if(i < 0 || j < 0 || i >= n || j >= m) return false;
	return a[i][j];
}

/*
1
4 9 2
*.*.*...*
.*.*...*.
..*.*.*..
.....*...
*/

void solve(){
	cin>>n>>m>>k;
	for(ll i = 0 ; i < n ; i++){
		mark[i].reset();
		a[i].reset();
		string s;
		cin>>s;
		for(ll j = 0 ; j < m ; j++){
			a[i][j] = (s[j] == '*');
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			ll h = 0;
			while(true){
				if(b(i - h , j - h) & b(i - h , j + h)){
					h++;
					continue;
				}
				break;
			}
			h--;
			if(h >= k){
				for(ll q = 0 ; q <= h ; q++){
					mark[i - q][j - q] = mark[i - q][j + q] = true;
				}
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		if((mark[i] ^ a[i]).any()){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}