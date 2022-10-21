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

const ll maxn = 1e5 + 17 , md = 1e9 + 7 , inf = 2e16;

int a[maxn] , sq[maxn] , b[maxn] , x[maxn];
vector<int> v[maxn];

void nxt(int i){
	int k = x[i];
	if(k > sq[a[i]]){
		bool f = false;
		int o = b[i] + 1 , h , c;
		while(true){
			h = a[i] / (o + 1) + 1; c = a[i] / h;
			if(c == o) break;
			if(h <= sq[a[i]]){
				k = h;
				f = true;
				break;
			}
			o++;
		}
		if(!f){
			x[i] = h;
			b[i] = a[i] / x[i];
			v[b[i]].push_back(i);
			return;
		}
	}
	while(true){
		int o = a[i] / --k;
		if(o > b[i]){
			x[i] = k;
			b[i] = o;
			v[o].push_back(i);
			return;
		}
	}
	return;
}

void solve(){
	int n , k;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		sq[i] = sqrt(a[i]);
	}
	int res , mx = 0;
	for(int i = 0 ; i < n ; i++){
		b[i] = a[i] / k;
		v[b[i]].push_back(i);
		mx = max(mx , b[i]);
		x[i] = k;
	}
	res = mx;
	for(int i = 1 ; i <= a[0] ; i++){
		for(auto j : v[i - 1]){
			nxt(j);
			mx = max(mx , b[j]);
		}
		v[i - 1].clear(); v[i - 1].shrink_to_fit();
		res = min(res , mx - i);
	}
	for(int i = 0 ; i < n ; i++){
		v[b[i]].clear(); v[b[i]].shrink_to_fit();
	}
	cout<<res<<'\n';
	return;
}

/*
1
7 3
2 3 5 5 6 9 10
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}