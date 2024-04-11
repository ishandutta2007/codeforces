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

const ll maxn = 4e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll n , m;
vector<vector<ll>> a , cnt;
vector<ll> v;
pll p[maxn];

bool check(ll i , ll j){
	if(i < 0 || i >= n || j < 0 || j >= m) return true;
	if(a[i][j] == 0) return true;
	bool res = false;
	if(i){
		res |= (a[i - 1][j] < a[i][j]);
	}
	if(j){
		res |= (a[i][j - 1] < a[i][j]);
	}
	if(i < n - 1){
		res |= (a[i + 1][j] < a[i][j]);
	}
	if(j < m - 1){
		res |= (a[i][j + 1] < a[i][j]);
	}
	return res;
}

ll mna(ll i , ll j){
	ll res = inf;
	if(i){
		res = min(a[i - 1][j] , res);
	}
	if(j){
		res = min(a[i][j - 1] , res);
	}
	if(i < n - 1){
		res = min(a[i + 1][j] , res);
	}
	if(j < m - 1){
		res = min(a[i][j + 1] , res);
	}
	return res;
}

bool check_swap(ll i1 , ll j1 , ll i2 , ll j2){
	if(i1 < 0 || i1 >= n || j1 < 0 || j2 >= m) return false;
	swap(a[i1][j1] , a[i2][j2]);
	bool res = true;
//	for(ll i = 0 ; i < n ; i++){
//		for(ll j = 0 ; j < m ; j++){
//			cout<<a[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	res &= check(i1 , j1);
	res &= check(i1 + 1 , j1);
	res &= check(i1 , j1 + 1);
//	cout<<i1<<' '<<j1 + 1<<'\n';
	res &= check(i1 , j1 - 1);
	res &= check(i1 - 1 , j1);
	res &= check(i2 + 1 , j2);
	res &= check(i2 , j2 + 1);
	res &= check(i2 , j2 - 1);
	res &= check(i2 - 1 , j2);
	res &= check(i2 , j2);
	swap(a[i1][j1] , a[i2][j2]);
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	a.resize(n); cnt.resize(n);
	for(ll i = 0 ; i < n ; i++){
		a[i].resize(m); cnt[i].assign(m , 0);
		for(ll j = 0 ; j < m ; j++){
			cin>>a[i][j]; a[i][j]--;
			p[a[i][j]] = {i , j};
		}
	}
	wall;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			if(!a[i][j]) continue;
			if(!check(i , j)){
				v.push_back(a[i][j]);
			}
		}
	}
	if(v.empty()){
		cout<<"0\n";
		return 0;
	}
	ll ans = 0;
	if(sze(v) == 1){
		ll r = v[0] , ir = p[r].first , jr = p[r].second;
		for(ll i = 0 ; i < n ; i++){
			for(ll j = 0 ; j < m ; j++){
				if(mna(i , j) < r){
					ans += check_swap(i , j , ir , jr);
				}
			}
		}
		for(ll e = 0 ; e < r ; e++){
			ll i = p[e].first , j = p[e].second;
			ans += check_swap(ir + 1 , jr , i , j);
			ans += check_swap(ir - 1 , jr , i , j);
			ans += check_swap(ir , jr + 1 , i , j);
			ans += check_swap(ir , jr - 1 , i , j);
		}
		if(ans == 0){
			cout<<"2\n";
			return 0;
		}
		cout<<"1 "<<ans<<'\n';
		return 0;
	}
	sort(all(v));
	ll vs = sze(v);
	for(auto r : v){
		ll i = p[r].first , j = p[r].second;
		if(i){
			cnt[i - 1][j]++;
		}
		if(j){
			cnt[i][j - 1]++;
		}
		if(i < n - 1){
			cnt[i + 1][j]++;
		}
		if(j < m - 1){
			cnt[i][j + 1]++;
		}
	}
	ll r = v[0];
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			if(cnt[i][j] == vs){
				for(ll e = 0 ; e < r ; e++){
					ll ie = p[e].first , je = p[e].second;
					ans += check_swap(i , j , ie , je);
				}
			}
		}
	}
	ll i = p[r].first , j = p[r].second;
	if(i){
		cnt[i - 1][j]--;
	}
	if(j){
		cnt[i][j - 1]--;
	}
	if(i < n - 1){
		cnt[i + 1][j]--;
	}
	if(j < m - 1){
		cnt[i][j + 1]--;
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			if(cnt[i][j] == vs - 1){
				ll ie = p[r].first , je = p[r].second;
				ans += check_swap(i , j , ie , je);
			}
		}
	}
	if(ans == 0){
		cout<<"2\n";
		return 0;
	}
	cout<<"1 "<<ans<<'\n';
	return 0;
}