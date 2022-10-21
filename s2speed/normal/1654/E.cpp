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

const ll maxn = 1e5 + 17 , maxc = 3e7 + 1e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

int n , sq , ans = 0;
int a[maxn] , cnt[maxc];
vector<int> v;

void d_mosbat(){
	for(int d = 0 ; d <= sq ; d++){
		for(int i = 0 ; i < n ; i++){
			int h = a[i] - i * d + 3e7;
			v.push_back(h);
			ans = max(ans , ++cnt[h]);
		}
		for(auto i : v) cnt[i]--;
		v.clear();
	}
	for(int i = 0 ; i < n ; i++){
		int lm = min(i + 340 , n);
		for(int j = i + 1 ; j < lm ; j++){
			if(a[j] < a[i]) continue;
			int h = (a[j] - a[i]);
			if(h % (j - i) != 0) continue;
			h /= (j - i);
			ans = max(ans , ++cnt[h] + 1);
			v.push_back(h);
		}
		for(auto i : v) cnt[i]--;
		v.clear();
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n; sq = 300;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	d_mosbat();
	reverse(a , a + n);
	d_mosbat();
	cout<<n - ans<<'\n';
	return 0;
}