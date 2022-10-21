#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll maxn = 5e6 + 17 , md = 1e9 + 7 , inf = 2e8;

int dp[maxn];
multiset<int , greater<int>> s;
bitset<maxn> a;
vector<int> v;

void solve(){
	v.clear(); s.clear();
	int n , m;
	cin>>n>>m;
	fill(dp , dp + m + 1 , inf);
	for(int i = 0 ; i < n ; i++){
		int h;
		cin>>h;
		a[h] = true;
		v.push_back(h);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	if(sze(v) == 1){
		cout<<"0\n";
		a[v[0]] = false;
		return;
	}
	for(auto i : v){
		s.insert(inf);
	}
	int res = inf;
	for(int i = m ; i > 1 ; i--){
		dp[i] = i;
		if(a[i]){
			s.erase(s.find(inf));
			s.insert(i);
			res = min(res , *s.begin() - i);
		}
		if(1ll * i * i > m) continue;
		for(ll j = i * i ; j <= m ; j += i){
			int h = dp[j / i];
			if(h < dp[j]){
				if(a[j]){
					s.erase(s.find(dp[j]));
					s.insert(h);
					res = min(res , *s.begin() - i);
				}
				dp[j] = h;
			}
		}
	}
	if(a[1]){
		s.erase(s.begin());
		res = *s.begin() - 1;
	}
	cout<<res<<'\n';
	for(auto i : v) a[i] = false;
	return;
}

/*
1
3 50
12 2 3
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}