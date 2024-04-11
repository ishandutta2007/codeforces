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

const ll maxn = 1.25e6 , md = 1e9 + 7 , inf = 2e16;

vector<ll> v;
bitset<maxn> dp[25] , tmp , fmp;
int par[25][maxn] , a[2][26];
bitset<52> mark;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(par , -1 , sizeof(par));
	ll n , lm;
	cin>>n; lm = (n << 1);
	for(ll i = 0 ; i < lm ; i++){
		ll h;
		cin>>h;
		v.push_back(h);
	}
	sort(all(v) , greater<ll>()); lm -= 2;
	ll sum = 0;
	dp[0][0] = true;
	for(ll i = 0 ; i < lm ; i++){
		sum += v[i];
		for(ll j = 24 ; j ; j--){
			tmp = dp[j] | (dp[j - 1] << v[i]);
			fmp = tmp ^ dp[j];
			dp[j] = tmp;
			for(ll k = fmp._Find_first() ; k < maxn ; k = fmp._Find_next(k)){
				par[j][k] = i;
			}
		}
	}
	mark[lm] = mark[lm + 1] = true;
	a[0][0] = v[lm + 1];
	a[1][n - 1] = v[lm];
	int pt = n - 1 , h = dp[n - 1]._Find_next((sum + 1) / 2 - 1);
	while(h > 0){
		a[0][n - pt] = v[par[pt][h]];
		mark[par[pt][h]] = true;
		h -= v[par[pt][h]];
		pt--;
	}
	pt = 0;
	for(ll i = 0 ; i < lm ; i++){
		if(!mark[i]){
			a[1][pt++] = v[i];
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<a[0][i]<<' ';
	}
	cout<<'\n';
	for(ll i = 0 ; i < n ; i++){
		cout<<a[1][i]<<' ';
	}
	cout<<'\n';
	return 0;
}