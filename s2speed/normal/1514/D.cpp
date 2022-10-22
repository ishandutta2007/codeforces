#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 3e5 + 16 , maxsq = 555 , md = 1e9 + 7 , inf = 2e18;
 
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

int a[maxn];
int cnt[maxn] , tnc[maxn] , ans[maxn] , x = 0;
vector<piii> v[maxsq];

void add(int j){
	int i = a[j];
	tnc[cnt[i]]--;
	cnt[i]++;
	tnc[cnt[i]]++;
	if(x == cnt[i] - 1) x++;
	return;
}

void del(int j){
	int i = a[j];
	tnc[cnt[i]]--;
	cnt[i]--;
	tnc[cnt[i]]++;
	if(tnc[cnt[i] + 1] == 0 && x == cnt[i] + 1) x--;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(cnt , 0 , sizeof(cnt));
	memset(tnc , 0 , sizeof(tnc));
	int n , q , sq , qs;
	cin>>n>>q; sq = sqrt(n); qs = (n + sq - 1) / sq;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	for(int i = 0 ; i < q ; i++){
		int l , r;
		cin>>l>>r; l--;
		v[l / sq].push_back({{r , l} , i});
	}
	int l = 0 , r = 0;
	for(int i = 0 ; i < qs ; i++){
		sort(all(v[i]));
		for(auto y : v[i]){
			int lx = y.first.second , rx = y.first.first , j = y.second , g = rx - lx , o , h;
			while(r < rx){
				add(r++);
			}
			while(r > rx){
				del(--r);
			}
			while(l < lx){
				del(l++);
			}
			while(l > lx){
				add(--l);
			}
			o = g - x;
			h = max(1 , g - 2 * o);
			ans[j] = h;
		}
	}
	for(int i = 0 ; i < q ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}