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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

struct fentree {

	int sz;
	vector<int> val;

	void init(int n){
		sz = n;
		val.assign(sz , 0);
		return;
	}

	void add(int i , int k){
		int h = i;
		while(h < sz){
			val[h] ^= k;
			h |= (h + 1);
		}
		return;
	}

	int cal(int i){
		int h = i;
		int res = 0;
		while(h != -1){
			res ^= val[h];
			h &= (h + 1); h--;
		}
		return res;
	}

};

int n , q;
string s;
vector<int> v[27] , px[27];
int c[maxn][26] , d[maxn][26] , u[maxn];
int g[maxn][60];
fentree ft[27];
vector<piii> t;
bool b = false;

int cal(int l , int r){
	bitset<32> mark;
	mark.set();
	for(int j = 0 ; j < 26 ; j++){
		int h = 0;
		if(c[l][j] >= r) continue;
		int kl = (c[l][j] == n ? sze(v[j]) - 1 : u[c[l][j]]) , kr = (!d[r][j] ? 0 : u[d[r][j] - 1]);
		h = g[l][j] ^ g[r][j + 26];
		if(!b){
			h ^= ft[j].cal(kr) ^ ft[j].cal(kl);
		} else {
			h ^= px[j][kr] ^ px[j][kl];
		}
		mark[h] = false;
	}
	return mark._Find_first();
}		

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c , 63 , sizeof(c));
	for(int i = 0 ; i < 26 ; i++) v[i].push_back(-1);
	cin>>s>>q; n = sze(s);
	for(int i = 0 ; i < n ; i++){
		int h = s[i] - 'a';
		u[i] = sze(v[h]);
		v[h].push_back(i);
	}
	for(int i = 0 ; i < 26 ; i++){
		c[n][i] = n;
		d[0][i] = 0;
		v[i].push_back(n);
		ft[i].init(sze(v[i]));
	}
	for(int i = n - 1 ; i >= 0 ; i--){
		for(int j = 0 ; j < 26 ; j++){
			c[i][j] = c[i + 1][j];
		}
		int h = s[i] - 'a';
		c[i][h] = i;
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < 26 ; j++){
			d[i][j] = d[i - 1][j];
		}
		d[i][s[i - 1] - 'a'] = i;
	}
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j < 26 ; j++){
			int l = i , r = c[i][j];
			t.push_back({r - l , {i , j}});
			l = d[i][j]; r = i;
			t.push_back({r - l , {i , j + 26}});
		}
	}
	sort(all(t));
	for(auto p : t){
		int i = p.second.first , e = p.second.second , j = e - (e >= 26) * 26;
		int l , r;
		if(j != e){
			r = i;
			l = d[i][j];
		} else {
			l = i;
			r = c[i][j];
		}
		g[i][e] = cal(l , r);
		if(j == e){
			if(i == 0){
				ft[j].add(1 , g[0][j]);
			} else {
				if(s[i - 1] - 'a' == j){
					ft[j].add((c[i][j] == n ? sze(v[j]) - 1 : u[c[i][j]]) , g[i][j]);
				}
			}
		}
	}
	for(int j = 0 ; j < 26 ; j++){
		int vs = sze(v[j]);
		for(int i = 0 ; i < vs ; i++){
			px[j].push_back(ft[j].cal(i));
		}
	}
	b = true;
	for(int i = 0 ; i < q ; i++){
		int l , r;
		cin>>l>>r; l--;
		int h = cal(l , r);
		cout<<(!h ? "Bob" : "Alice")<<'\n';
	}
	return 0;
}