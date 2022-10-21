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

inline ll tav(ll n , ll k){
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

ll a[maxn] , l , r;
string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	l = 0; r = n - 1;
	ll ls = -1;
	while(l <= r){
		if(a[l] <= ls && a[r] <= ls){
			cout<<sze(s)<<'\n'<<s<<'\n';
			return 0;
		}
		if(a[l] == a[r]) break;
		ll al = (a[l] > ls ? a[l] : inf) , ar = (a[r] > ls ? a[r] : inf);
		if(al < ar){
			s += 'L';
			ls = a[l++];
		} else {
			s += 'R';
			ls = a[r--];
		}
	}
	if(l > r){
		cout<<n<<'\n'<<s<<'\n';
		return 0;
	}
	ll cnl = 1 , cnr = 1;
	for(ll i = l + 1 ; i <= r ; i++){
		if(a[i] <= a[i - 1]) break;
		cnl++;
	}
	for(ll i = r - 1 ; i >= l ; i--){
		if(a[i] <= a[i + 1]) break;
		cnr++;
	}
	if(cnl >= cnr){
		while(cnl){
			s += 'L';
			cnl--;
		}
	} else {
		while(cnr){
			s += 'R';
			cnr--;
		}
	}
	cout<<sze(s)<<'\n'<<s<<'\n';
	return 0;
}