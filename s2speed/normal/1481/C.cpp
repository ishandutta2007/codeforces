#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 + 20 , md = 1e9 + 7 , inf = 2e9 + 1;
// check problem statement

ll a[MAXN] , b[MAXN] , c[MAXN] , cnt[MAXN] , x[MAXN] , h[MAXN];
vector<ll> col[MAXN];

void solve(){
	ll n , m;
	cin>>n>>m;
	fill(cnt , cnt + n , 0);
	fill(x , x + n , 0);
	fill(h , h + n , -1);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		col[i].clear();
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i]; b[i]--;
		h[b[i]] = i;
	}
	for(ll i = 0 ; i < m ; i++){
		cin>>c[i]; c[i]--;
		cnt[c[i]]++;
	}
	for(ll i = 0 ; i < n ; i++){
		if(a[i] == b[i]) continue;
		col[b[i]].push_back(i);
		cnt[b[i]]--;
		if(cnt[b[i]] == -1){
			cout<<"NO\n";
			return;
		}
	}
	if(h[c[m - 1]] == -1){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	ll o = (col[c[m - 1]].empty() ? h[c[m - 1]] : col[c[m - 1]].back());
	for(ll i = 0 ; i < m ; i++){
		if(h[c[i]] == -1){
			cout<<o + 1<<' ';
			continue;
		}
		if(x[c[i]] == col[c[i]].size()){
			cout<<(x[c[i]] == 0 ? h[c[i]] : col[c[i]][x[c[i]] - 1]) + 1<<' ';
		} else {
			cout<<col[c[i]][x[c[i]]++] + 1<<' ';
		}
	}
	cout<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*
1

*/