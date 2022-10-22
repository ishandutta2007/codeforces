#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<db , db> point;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e2 + 16 , md = 1e9 + 7 , inf = 2e17;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

struct line {
	db a , b;
	void build_line(point c , point d){
		b = c.second;
		a = (d.second - c.second) / (db)1;
		return;
	}
};

point merge(line a , line b){
	point res;
	if(a.a == b.a){
		return {-2 , -2};
	}
	res.first = (db)1 * (a.b - b.b) / (b.a - a.a);
	res.second = res.first * a.a + a.b;
	return res;
}

ll a[maxn][maxn];
line l[maxn][maxn];
db ans[maxn];
vector<point> v , v1;
vector<ll> u , u1;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		ans[i] = 0;
		for(ll j = 0 ; j <= k ; j++){
			cin>>a[i][j];
		}
		for(ll j = 0 ; j < k ; j++){
			l[i][j].build_line({0 , (db)a[i][j]} , {1 , (db)a[i][j + 1]});
		}
	}
	for(ll j = 0 ; j < k ; j++){
		v.clear(); u.clear();
		v.push_back({0 , (db)a[0][j]}); v.push_back({1 , (db)a[0][j + 1]});
		u.push_back(0);
		db o = (a[0][j] + a[0][j  +1]) / (db)2;
		ans[0] += o;
		for(ll i = 1 ; i < n ; i++){
			ll us = sze(u);
			bool ch = false , done = false;
			if(a[i][j] > v[0].second){
				v1.push_back({0 , a[i][j]});
				ch = true;
			} else {
				v1.push_back(v[0]);
			}
			for(ll e = 0 ; e < us ; e++){
				if(done){
					u1.push_back(u[e]);
					v1.push_back(v[e + 1]);
				}
				ll ind = u[e];
				point h = merge(l[ind][j] , l[i][j]);
				if(!ch){
					if((h.first > v[e].first || (h.first == v[e].first && l[i][j].a > l[ind][j].a)) && h.first < v[e + 1].first){
						ch = true;
						v1.push_back(h);
						u1.push_back(ind);
						continue;
					}
				}
				if(ch){
					if(h.first >= v[e].first && h.first < v[e + 1].first){
						done = true;
						v1.push_back(h);
						u1.push_back(i);
						v1.push_back(v[e + 1]);
						u1.push_back(ind);
					}
					continue;
				}
				v1.push_back(v[e + 1]);
				u1.push_back(ind);
			}
			if(a[i][j + 1] >= v[us].second && ch && !done){
				v1.push_back({1 , a[i][j + 1]});
				u1.push_back(i);
			}
			u = u1; v = v1; v1.clear(); u1.clear();
			us = sze(u);
			db q = 0;
			for(ll e = 0 ; e < us ; e++){
				db h = (v[e + 1].second + v[e].second) * (v[e + 1].first - v[e].first) / (db)2;
				q += h;
			}
			ans[i] += q - o;
			o = q;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<fixed<<setprecision(8)<<ans[i]<<'\n';
	}			
	return 0;
}

/*
2 1
7 5
4 2
 5 5 9 10 9 8 7 5 10
 8 2 9 1 2 8 10 7 10
*/