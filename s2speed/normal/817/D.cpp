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

const ll maxn = 1e6 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<ll> v , u;
ll a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , cur = 0 , ans = 0;
	cin>>n;
	v.push_back(-1); u.push_back(-1);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		while(sze(v) > 1){
			ll j = v.back() , t = a[j];
			if(t > a[i]) break;
			v.pop_back();
			cur -= t * (j - v.back());
		}
		cur += (i - v.back()) * a[i];
		while(sze(u) > 1){
			ll j = u.back() , t = a[j];
			if(t < a[i]) break;
			u.pop_back();
			cur += t * (j - u.back());
		}
		cur -= (i - u.back()) * a[i];
		ans += cur;
		v.push_back(i); u.push_back(i);
	}
	cout<<ans<<'\n';
	return 0;
}