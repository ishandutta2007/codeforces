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

const ll maxn = 2e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , cnt[(ll)1e6 + 16] , dead[(ll)1e6 + 16];
vector<ll> v;
vector<pll> u;
ll n;

bool check(ll y){
	dead[v[y]]++; dead[v[n - 1]]++;
	cnt[v[y]]--; cnt[v[n - 1]]--;
	u.push_back({v[y] , v[n - 1]});
	ll ls = v[n - 1];
	for(ll i = n - 1 ; i >= 0 ; i--){
		if(dead[v[i]]){
			dead[v[i]]--;
			continue;
		}
		cnt[v[i]]--;
		if(cnt[ls - v[i]] == 0){
			u.clear();
			return false;
		}
		u.push_back({v[i] , ls - v[i]});
		dead[v[i]]++; dead[ls - v[i]]++;
		cnt[ls - v[i]]--;
		ls = v[i];
	}
	return true;
}

void solve(){
	for(auto i : v){
		cnt[i] = dead[i] = 0;
	}
	v.clear();
	u.clear();
	cin>>n; n <<= 1;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		cnt[a[i]]++;
		v.push_back(a[i]);
	}
	sort(all(v));
	for(ll i = 0 ; i < n - 1 ; i++){
		if(check(i)){
			cout<<"YES\n";
			cout<<v[n - 1] + v[i]<<'\n';
			for(auto p : u){
				cout<<p.first<<' '<<p.second<<'\n';
			}
			return;
		}
		for(auto i : v){
			cnt[i] = dead[i] = 0;
		}
		for(auto i : v){
			cnt[i]++;
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	memset(dead , 0 , sizeof(dead));
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}