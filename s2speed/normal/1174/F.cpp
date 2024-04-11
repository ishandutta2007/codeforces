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
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e17;

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

vector<ll> adj[maxn];
ll z[maxn] , dis[maxn] , dep = 0 , jad[maxn][20] , hc[maxn] , cur , h = -1 , o = 0 , t;

void cDFS(ll r , ll par){
	jad[r][0] = par;
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	dis[r] = dep++;
	z[r] = (dis[r] == t);
	ll m = -1;
	for(auto i : adj[r]){
		if(i == par) continue;
		cDFS(i , r);
		z[r] += z[i];
		if(z[i] > m){
			m = z[i];
			hc[r] = i;
		}
	}
	dep--;
	return;
}

ll find_jad(ll v , ll d){
	d = dis[v] - d;
	for(ll j = 0 ; j < 20 ; j++){
		if(d & (1 << j)) v = jad[v][j];
	}
	return v;
}

ll aDFS(ll r , ll par){
	if(cur == 1){
		if(dis[r] == t) return r;
		for(auto i : adj[r]){
			if(i == par) continue;
			if(z[i]) return aDFS(i , r);
		}
	}
	if(z[hc[r]] <= cur / 2){
		cout<<"d "<<r<<endl;
		cin>>o;
		h = (t + dis[r] - o) >> 1;
		h = find_jad(r , h);
		cout<<"s "<<h<<endl;
		cin>>o;
		cur = z[o];
		return aDFS(o , h);
	} else {
		return aDFS(hc[r] , r);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(jad , -1 , sizeof(jad));
	ll n;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	cout<<"d 1"<<endl;
	cin>>t;
	cDFS(1 , -1);
	cur = z[1];
	ll ans = aDFS(1 , -1);
	cout<<"! "<<ans<<'\n';
	return 0;
}