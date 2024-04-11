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

bitset<10> mark;
ll ch[10];

void solve(){
	ll k;
	string s;
	cin>>k>>s;
	for(ll i = 0 ; i < k ; i++){
		ll h = s[i] - '0';
		if(mark[h]){
			cout<<1<<'\n'<<s[i]<<'\n';
			return;
		}
	}
	cout<<2<<'\n';
	memset(ch , -1 , sizeof(ch));
	for(ll i = 0 ; i < k ; i++){
		ll h = s[i] - '0';
		if(ch[h] != -1){
			cout<<h * 11<<'\n';
			return;
		}
		ch[h] = i;
	}
	if(ch[5] > 0){
		cout<<s[0]<<"5\n";
		return;
	}
	if(ch[2] > 0){
		cout<<s[0]<<"2\n";
		return;
	}
	if(ch[5] < ch[7] && ch[5] > -1){
		cout<<"57\n";
		return;
	}
	if(ch[2] < ch[7] && ch[2] > -1){
		cout<<"27\n";
		return;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	mark.set();
	mark[2] = mark[3] = mark[5] = mark[7] = false;
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}