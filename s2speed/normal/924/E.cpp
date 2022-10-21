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

const ll maxn = 1e4 + 17 , md = 1e9 + 7 , inf = 2e16;

bitset<maxn> dp , tmp , df;
vector<ll> v;
ll a[maxn];
int f[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(f , -31 , sizeof(f));
	dp[0] = true; f[0] = 0;
	ll n , l , r;
	cin>>n>>l>>r;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll ps = 0 , sum;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		if(!h){
			tmp = dp << a[i];
			dp |= tmp;
		} else {
			v.push_back(a[i]);
			ps += a[i];
		}
	}
	for(int i = 0 ; i < maxn ; i++){
		if(dp[i]) f[i] = i;
		df[i] = dp[i];
	}
	sum = ps;
	if(v.empty()){
		cout<<"0\n";
		return 0;
	}
	sort(all(v));
	r += v[0]; l--;
	ll vs = sze(v);
	for(ll i = vs - 1 ; ~i ; i--){
		for(int h = l + 1 ; h + ps <= r - v[0] ; h++){
			if(f[h] > h + ps - sum){
				cout<<i + 1 + (i != vs - 1)<<'\n';
				return 0;
			}
		}
		int h = dp._Find_next(l);
		if(h + ps <= r){
			cout<<i + 1<<'\n';
			return 0;
		}
		ps -= v[i];
		tmp = dp << v[i];
		dp |= tmp;
		for(int j = 1e4 ; j >= v[i] ; j--){
			f[j] = max(f[j]  , f[j - v[i]]);
		}
	}
	for(int h = l + 1 ; h <= r - v[0] ; h++){
		if(f[h] > h + ps - sum){
			cout<<"1\n";
			return 0;
		}
	}
	cout<<"0\n";
	return 0;
}