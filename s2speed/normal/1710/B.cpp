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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll x[maxn] , p[maxn] , c[maxn];
vector<pll> v;
ll ps[maxn] , cnt[maxn] , val[maxn] , a[maxn] , b[maxn];
bitset<maxn> ans;

void solve(){
	v.clear();
	ll n , m;
	cin>>n>>m;
	fill(ps , ps + n , 0);
	fill(cnt , cnt + n , 0);
	for(ll i = 0 ; i < n ; i++){
		cin>>x[i]>>p[i];
		v.push_back({x[i] , p[i]});
	}
	sort(all(v));
	for(ll i = 0 ; i < n ; i++){
		c[i] = lower_bound(all(v) , mp(x[i] , p[i])) - v.begin();
		ll x = v[i].first , p = v[i].second , h = x - p;
		ll j = lower_bound(all(v) , mp(h , -1ll)) - v.begin();
		ps[j] += p - x; ps[i + 1] -= p - x;
		cnt[j]++; cnt[i + 1]--;
		h = x + p;
		j = lower_bound(all(v) , mp(h , -1ll)) - v.begin();
		ps[i + 1] += p + x; ps[j] -= p + x;
		cnt[i + 1]--; cnt[j]++;
	}
	for(ll i = 0 ; i < n ; i++){
		val[i] = ps[i] + v[i].first * cnt[i];
		ps[i + 1] += ps[i];
		cnt[i + 1] += cnt[i];
	}
	for(ll i = 0 ; i < n ; i++){
		if(val[i] <= m){
			a[i] = b[i] = -inf;
			continue;
		}
		ll j = v[i].first;
		ll h = val[i] - m;
		a[i] = h + j;
		b[i] = h - j;
	}
	for(ll i = 1 ; i < n ; i++){
		b[i] = max(b[i - 1] , b[i]);
	}
	for(ll i = n - 2 ; ~i ; i--){
		a[i] = max(a[i + 1] , a[i]);
	}
	for(ll i = 0 ; i < n ; i++){
		ll h = (i ? b[i - 1] : -inf) , j = v[i].first , p = v[i].second;
		bool f = true;
		f &= (h <= p - j);
		h = (i == n - 1 ? -inf : a[i + 1]);
		f &= (h <= p + j);
		ans[i] = f;
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[c[i]];
	}
	cout<<'\n';
	return;
}

/*
1
2 3
1 3
5 2
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}