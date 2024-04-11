#include<bits/stdc++.h>
#include<fstream>
 
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
struct plll { ll x , y , z; };
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 16 , inf = 2e17;
ll md , f;
vector<ll> pr;

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

ll tv[maxn] , vt[maxn];

ll dv(ll n , ll k){
	return 1ll * n * vt[k] % md;
}

vector<pll> adj[maxn];
map<ll , ll> t , g[maxn];
ll z[maxn] , cur = 0 , sz , ans = 0 , dep = -1;
bitset<maxn> mark , dead;

void zDFS(ll r){
	sz++;
	mark[r] = true;
	z[r] = 1;
	for(auto p : adj[r]){
		ll i = p.first;
		if(mark[i]) continue;
		zDFS(i);
		z[r] += z[i];
	}
	return;
}

ll find_centroid(ll r , ll par){
	for(auto p : adj[r]){
		ll i = p.first;
		if(i == par || dead[i]) continue;
		if(z[i] > sz) return find_centroid(i , r);
	}
	return r;
}

ll h;

void tDFS(ll r , ll par , ll m , ll d){
	if(par != -1){
		cur += 1ll * tv[dep] * d; cur %= md;
	}
	dep++;
	if(t.count(cur)) t[cur]++;
	else t[cur] = 1;
	if(r != h){
		if(g[m].count(cur)) g[m][cur]++;
		else g[m][cur] = 1;
	}
	for(auto p : adj[r]){
		ll i = p.first , w = p.second;
		if(i == par || dead[i]) continue;
		tDFS(i , r , (h == r ? i : m) , w);
	}
	if(par != -1){
		cur -= 1ll * tv[dep - 1] * d; cur %= md; if(cur < 0) cur += md;
	}
	dep--;
	return;
}

void aDFS(ll r , ll par , ll m , ll d){
	dep++;
	cur *= 10; cur += d; cur %= md;
	ll o = md - cur; if(o == md) o = 0;
	o = dv(o , dep);
	if(t.count(o)){
		ans += t[o];
	}
	if(r != h){
		ans -= g[m][o];
	}
	for(auto p : adj[r]){
		ll i = p.first , w = p.second;
		if(i == par || dead[i]) continue;
		aDFS(i , r , (h == r ? i : m) , w);
	}
	cur -= d; cur = dv(cur , 1); if(cur < 0) cur += md;
	dep--;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , y , lm;
	cin>>n>>md; y = md; lm = sqrt(md);
	for(ll i = 2 ; i <= lm ; i++){
		if(y % i == 0) pr.push_back(i);
		while(y % i == 0) y /= i;
	}
	if(y != 1) pr.push_back(y);
	ll ps = sze(pr); lm = 1 << ps;
	for(ll mask = 0 ; mask < lm ; mask++){
		ll cnt = 0 , h = 1;
		for(ll j = 0 ; j < ps ; j++){
			if(mask & (1 << j)){
				cnt++;
				h *= pr[j];
			}
		}
		f += (1 - ((cnt & 1) << 1)) * md / h;
	}
	tv[0] = vt[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = 10ll * tv[i - 1] % md;
		vt[i] = tav(tv[i] , f - 1);
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u , w;
		cin>>v>>u>>w;
		adj[v].push_back({u , w}); adj[u].push_back({v , w});
	}
	ll cnt = 0;
	while(cnt < n){
		mark = dead;
		for(ll i = 0 ; i < n ; i++){
			if(mark[i]) continue;
			sz = 0;
			zDFS(i);
			sz >>= 1;
			h = find_centroid(i , -1);
			tDFS(h , -1 , -1 , 0);
			aDFS(h , -1 , -1 , 0);
			t.clear();
			for(auto p : adj[h]){
				ll i = p.first;
				g[i].clear();
			}
			dead[h] = true;
			cnt++;
		}
	}
	ans -= n;
	cout<<ans<<'\n';
	return 0;
}