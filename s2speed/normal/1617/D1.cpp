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

bitset<maxn> ans , mark;
vector<ll> v;

void solve(){
	v.clear();
	ll n , g[] = {-1 , -1};
	cin>>n;
	for(ll i = 1 ; i <= n ; i++) ans[i] = mark[i] = false;
	for(ll i = 1 ; i <= n ; i += 3){
		cout<<"? "<<i<<' '<<i + 1<<' '<<i + 2<<endl;
		bool c;
		cin>>c;
		g[c] = i;
		if(g[0] != -1 && g[1] != -1) break;
	}
	ll a = g[0] , b = g[0] + 1 , c = g[0] + 2 , d = g[1] , e = g[1] + 1 , f = g[1] + 2 , h[2];
	bool z , x , y , t;
	cout<<"? "<<a<<' '<<b<<' '<<c<<endl;
	cin>>z;
	cout<<"? "<<a<<' '<<b<<' '<<d<<endl;
	cin>>x;
	cout<<"? "<<a<<' '<<b<<' '<<e<<endl;
	cin>>y;
	cout<<"? "<<a<<' '<<b<<' '<<f<<endl;
	cin>>t;
	if(x == y && z == t && x == z){
		ans[a] = ans[b] = x;
		mark[a] = mark[b] = true;
		h[x] = a;
		cout<<"? "<<e<<' '<<f<<' '<<a<<endl;
		cin>>z;
		if(z == !x){
			h[z] = f;
			ans[f] = ans[e] = z;
			mark[f] = mark[e] = true;
		} else {
			cout<<"? "<<e<<' '<<f<<' '<<c<<endl;
			cin>>z;
			ans[c] = z;
			cout<<"? "<<e<<' '<<f<<' '<<d<<endl;
			cin>>z;
			ans[d] = z;
			h[ans[c]] = c;
			h[ans[d]] = d;
			mark[c] = mark[d] = true;
		}
	} else {
		ans[c] = z;
		ans[d] = x;
		ans[e] = y;
		ans[f] = t;
		h[ans[c]] = c;
		h[ans[d]] = d;
		h[ans[e]] = e;
		h[ans[f]] = f;
		mark[c] = mark[d] = mark[e] = mark[f] = true;
	}
	for(ll i = 1 ; i <= n ; i++){
		if(mark[i]) continue;
		cout<<"? "<<h[0]<<' '<<h[1]<<' '<<i<<endl;
		cin>>z;
		ans[i] = z;
	}
	ll cnt = 0;
	for(ll i = 1 ; i <= n ; i++){
		if(!ans[i]){
			cnt++;
			v.push_back(i);
		}
	}
	cout<<"! "<<cnt<<' ';
	for(auto i : v){
		cout<<i<<' ';
	}
	cout<<endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}