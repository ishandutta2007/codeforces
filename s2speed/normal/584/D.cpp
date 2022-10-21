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

const ll maxn = 1e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bool check(ll x){
	ll sq = sqrt(x);
	for(ll i = 2 ; i <= sq ; i++){
		if(x % i == 0) return false;
	}
	return true;
}

bitset<maxn> mark;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , s;
	cin>>n;
	ll h = n;
	while(true){
		if(check(h)){
			s = n - h;
			break;
		}
		h -= 2;
	}
	if(s == 0){
		cout<<"1\n"<<n<<'\n';
		return 0;
	}
	if(s == 2){
		cout<<"2\n2 "<<n - 2<<'\n';
		return 0;
	}
	for(ll i = 2 ; i < s ; i++){
		mark[i] = check(i);
	}
	for(ll i = 2 ; i < s ; i++){
		if(mark[i] && mark[s - i]){
			cout<<"3\n"<<h<<' '<<i<<' '<<s - i<<'\n';
			return 0;
		}
	}
	return 0;
}