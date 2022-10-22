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

ll a[maxn];
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k; 
	cin>>n>>k;
	ll a12 , a13 , a23 , o12 , o13 , o23 , x123 , x12 , x13 , x23 , x1 , x2 , x3;
	cout<<"and 1 2"<<endl;
	cin>>a12;
	cout<<"and 1 3"<<endl;
	cin>>a13;
	cout<<"and 2 3"<<endl;
	cin>>a23;
	cout<<"or 1 2"<<endl;
	cin>>o12;
	cout<<"or 1 3"<<endl;
	cin>>o13;
	cout<<"or 2 3"<<endl;
	cin>>o23;
	x123 = a12 & a13;
	x12 = a12 ^ x123;
	x13 = a13 ^ x123;
	x23 = a23 ^ x123;
	a[1] = (o12 & o13) ^ x23;
	a[2] = (o12 & o23) ^ x13;
	a[3] = (o13 & o23) ^ x12;
//	a[1] = x1 + x12 + x13 + x123;
//	a[2] = x2 + x12 + x23 + x123;
//	a[3] = x3 + x13 + x23 + x123;
	for(ll i = 4 ; i <= n ; i++){
		ll a1i , o1i;
		cout<<"and 1 "<<i<<endl;
		cin>>a1i;
		cout<<"or 1 "<<i<<endl;
		cin>>o1i;
		a[i] = (o1i ^ a[1]) | a1i;
	}
	for(ll i = 1 ; i <= n ; i++){
		v.push_back(a[i]);
	}
	cout<<'\n';
	sort(all(v));
	cout<<"finish "<<v[k - 1]<<endl;
	return 0;
}
// 1 6 4 2 3 5 4