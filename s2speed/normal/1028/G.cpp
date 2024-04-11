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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16 , M = 10004205361450474 , S = 204761410474 , B = 2046 , D = 20452044 + 16382 + 1;

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

vector<ll> v;

void end(ll l , ll r){
	v.clear();
	ll x = min(l , (ll)1e4);
	if(x >= r - l){
		cout<<r - l<<' ';
		for(ll i = l ; i < r ; i++){
			cout<<i<<' ';
		}
		cout<<endl;
		ll h;
		cin>>h;
		return;
	}
	bool t = false;
	if(l == B + 1 && r == S){
		v.push_back(D);
		l = D + 1; x--;
		t = true;
	}
	if(l == B + 1 && r == D){
		ll h = 2046;
		while(h < 1e4){
			h <<= 1;
			h += 2;
			v.push_back(h);
		}
		l = h + 1; x -= 3;
		t = true;
	}
	ll h = (r - l) / (x + 1) , c = l;
	for(ll i = 0 ; i < x && c + h <= M ; i++){
		c += h;
		v.push_back(c++);
	}
	ll vs = sze(v);
	cout<<sze(v)<<' ';
	for(auto i : v) cout<<i<<' ';
	cout<<endl;
	cin>>h;
	if(h == -1) return;
	if(h == 0){
		if(t){
			end(B + 1 , v[0]);
		} else {
			end(l , v[0]);
		}
		return;
	}
	if(h == vs){
		end(v.back() + 1 , r);
		return;
	}
	end(v[h - 1] + 1 , v[h]);
	return;
}

/*
10004205361450474
10004000600040000
204761410474
204740942046
20468427
20452044
16382
*/
// 1028G
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cout<<"1 "<<S<<endl;
	ll h;
	cin>>h;
	if(h == -1) return 0;
	if(h == 1){
		end(S + 1 , M + 1);
		return 0;
	}
	cout<<"1 "<<(ll)B<<endl;
	cin>>h;
	if(h == -1) return 0;
	if(h == 1){
		end(B + 1 , S);
		return 0;
	}
	cout<<"1 6"<<endl;
	cin>>h;
	if(h == -1) return 0;
	if(h == 0){
		cout<<"1 2"<<endl;
		cin>>h;
		if(h == -1) return 0;
		if(h == 0){
			cout<<"1 1"<<endl;
		} else {
			cout<<"3 3 4 5"<<endl;
		}
		cin>>h;
		return 0;
	}
	v.clear();
	ll c = 6;
	cout<<"7 ";
	v.push_back(6);
	for(ll i = 0 ; i < 7 ; i++){
		c <<= 1; c += 2;
		cout<<c<<' ';
		v.push_back(c);
	}
	v.push_back(B);
	cout<<endl;
	cin>>h;
	if(h == -1) return 0;
	cout<<v[h + 1] - v[h] - 1<<' ';
	for(ll i = v[h] + 1 ; i < v[h + 1] ; i++){
		cout<<i<<' ';
	}
	cout<<endl;
	cin>>h;
	return 0;
}