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

const ll maxn = 5e5 + 17 , md = 2000000357 , P = 131 , inf = 2e16;

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

struct fentree {

	ll sz;
	vector<ll> val;

	void init(ll n){
		sz = n;
		val.assign(sz , 0);
		return;
	}

	void add(ll i){
		ll h = i;
		while(h < sz){
			val[h]++;
			h |= (h + 1);
		}
		return;
	}

	ll cal(ll i){
		ll h = i , res = 0;
		while(~h){
			res += val[h];
			h &= (h + 1); h--;
		}
		return res;
	}

	ll cal(ll l , ll r){
		return cal(r - 1) - cal(l - 1);
	}

};

fentree ft;
ll m , q , n;
string s , a[maxn];
ll rnk[maxn] , hnk[maxn] , sf[maxn] , lc[maxn] , hs[maxn] , tv[maxn] , qu[maxn] , ind[maxn] , li[maxn] , ri[maxn] , ans[maxn] , qk[maxn];
vector<ll> cnt[maxn] , v , ql[maxn] , qr[maxn];

ll get_hash(ll l , ll r){
	if(r >= n) return -r;
	ll res = hs[r];
	if(l){
		res -= hs[l - 1] * tv[r - l + 1] % md; res += (res < 0) * md;
	}
	return res;
}

ll lcp(ll i , ll j){
	ll l = 0 , r = n;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(get_hash(i , i + m - 1) == get_hash(j , j + m - 1)){
			l = m;
		} else {
			r = m;
		}
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = tv[i - 1] * P % md;
	}
	cin>>m>>q;
	for(ll i = 0 ; i < m ; i++){
		cin>>a[i];
		ind[i] = sze(s);
		s += a[i] + '$';
	}
	n = sze(s);
	ll lm = max(130ll , n + 1);
	hs[0] = s[0];
	for(ll i = 1 ; i < n ; i++){
		hs[i] = (hs[i - 1] * P + s[i]) % md;
	}
	for(ll i = 0 ; i < n ; i++){
		rnk[i] = s[i];
	}
	for(ll j = 0 ; j < 20 ; j++){
		ll o = 1 << j;
		if(o >= n) break;
		for(ll i = 0 ; i < n - o ; i++){
			hnk[i] = rnk[i + o];
		}
		for(ll i = n - o ; i < n ; i++) hnk[i] = 0;
		for(ll i = 0 ; i < lm ; i++) cnt[i].clear();
		v.clear();
		for(ll i = 0 ; i < n ; i++){
			cnt[hnk[i]].push_back(i);
		}
		for(ll i = 0 ; i < lm ; i++){
			for(auto k : cnt[i]){
				v.push_back(k);
			}
		}
		for(ll i = 0 ; i < lm ; i++) cnt[i].clear();
		for(auto i : v){
			cnt[rnk[i]].push_back(i);
		}
		ll r = 0;
		for(ll i = 0 ; i < lm ; i++){
			ll pr = -1;
			for(auto k : cnt[i]){
				if(hnk[k] != pr){
					r++;
					pr = hnk[k];
				}
				rnk[k] = r;
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		sf[rnk[i] - 1] = i;
	}
//	cout<<s<<'\n';
//	for(ll i = 0 ; i < n ; i++){
//		cout<<sf[i]<<' ';
//	}
//	cout<<'\n';
	for(ll i = 0 ; i < n - 1 ; i++){
		lc[i] = lcp(sf[i] , sf[i + 1]);
//		cout<<lc[i]<<' ';
	}
//	cout<<'\n';
	lc[n] = -1; lc[n - 1] = 0;
	v.clear();
	v.push_back(n);
	memset(qu , -1 , sizeof(qu));
	for(ll i = 0 ; i < m ; i++){
		qu[rnk[ind[i]] - 1] = i;
	}
	for(ll i = 0 ; i < n ; i++){
		if(qu[i] != -1){
			ll j = qu[i] , b = sze(a[j]);
			ll l = 0 , r = sze(v);
			while(l < r - 1){
				ll m = (r + l) >> 1;
				if(lc[v[m]] < b){
					l = m;
				} else {
					r = m;
				}
			}
			li[j] = (v[l] == n ? 0 : v[l] + 1);
		}
		while(lc[v.back()] >= lc[i]) v.pop_back();
		v.push_back(i);
	}
	v.clear(); v.push_back(n);
	for(ll i = n - 1 ; ~i ; i--){
		while(lc[v.back()] >= lc[i]) v.pop_back();
		v.push_back(i);
		if(qu[i] != -1){
			ll j = qu[i] , b = sze(a[j]);
			ll l = 0 , r = sze(v);
			while(l < r - 1){
				ll m = (r + l) >> 1;
				if(lc[v[m]] < b){
					l = m;
				} else {
					r = m;
				}
			}
			ri[j] = v[l] + 1;
		}
	}
//	cout<<li[16]<<' '<<ri[16]<<' '<<rnk[ind[16]] - 1<<' '<<lc[31]<<' '<<lc[32]<<'\n';
	for(ll i = 0 ; i < q ; i++){
		ll l , r , k;
		cin>>l>>r>>k; l--; k--;
		qk[i] = k;
		ql[l].push_back(i); qr[r].push_back(i);
	}
	ft.init(n);
	for(ll i = 0 ; ; i++){
		for(auto j : ql[i]){
			ans[j] -= ft.cal(li[qk[j]] , ri[qk[j]]);
		}
		for(auto j : qr[i]){
			ans[j] += ft.cal(li[qk[j]] , ri[qk[j]]);
		}
		if(i == m) break;
		ll b = sze(a[i]);
		for(ll j = ind[i] ; j < ind[i] + b ; j++){
			ft.add(rnk[j] - 1);
		}
	}
	for(ll i = 0 ; i < q ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}

/*
20 1
e
n
i
g
g
b
u
v
g
t
f
k
n
o
l
h
w
h
o
e
10 18 17
*/