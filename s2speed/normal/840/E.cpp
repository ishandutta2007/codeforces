#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("avx2")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e4 + 16 , sq = 256 , md = 1e9 + 7 , inf = 1e9;

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

short int tr[maxn][sq * 2 + 16][2] , z[maxn][sq] , cur[maxn];

void add(int x , int i){
	bitset<8> o = x;
	int v = 0;
	for(int j = 7 ; j >= 0 ; j--){
		if(tr[i][v][o[j]] == -1){
			tr[i][v][o[j]] = ++cur[i];
		}
		v = tr[i][v][o[j]];
	}
	return;
}

int max_xor(int x , int i){
	bitset<8> o = x;
	int res = 0 , v = 0 , t = 0;
	for(int j = 7 ; j >= 0 ; j--){
		if(tr[i][v][!o[j]] != -1){
			res += (1 << j);
			v = tr[i][v][!o[j]];
			t += (1 << j) * !o[j];
		} else {
			v = tr[i][v][o[j]];
			t += (1 << j) * o[j];
		}
	}
	int h = z[i][t];
	res <<= 8; res |= h;
	return res;
}

vector<int> adj[maxn];
vector<piii> qu[maxn];
int a[maxn] , par[maxn] , dis[maxn] , anc[maxn] , ans[3 * maxn] , dep = 0;

void DFS(int r){
	dis[r] = dep++;
	int v = r;
	for(int j = 0 ; j <= 255 && v != -1 ; j++){
		short int h = a[v] >> (int)8 , o = (a[v] ^ j) & (int)255;
		z[r][h] = max(z[r][h] , o);
		add(h , r);
		v = par[v];
	}
	anc[r] = v;
	for(auto i : adj[r]){
		if(i == par[r]) continue;
		par[i] = r;
		DFS(i);
	}
	dep--;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(tr , -1 , sizeof(tr));
	memset(cur , 0 , sizeof(cur));
	int n , q;
	cin>>n>>q;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	par[0] = -1;
	DFS(0);
	for(int e = 0 ; e < q ; e++){
		int v , u , h , ans = 0 , k = 0;
		cin>>u>>v; v--; u--;
		qu[v].push_back({{dis[u] , u} , e});
	}
	for(int v = 0 ; v < n ; v++){
		sort(all(qu[v]) , greater<piii>());
		int h = v , x = 0 , qs = sze(qu[v]) , u , o , j , cur = 0 , ruc , d , k = 0;
		qu[v].push_back({{-inf , -1} , -1});
		while(h != -1 && x < qs){
			o = h;
			ruc = cur;
			d = k << 8;
			while(dis[h] - qu[v][x].first.first <= 255){
				u = qu[v][x].first.second; j = qu[v][x].second;
				while(o != par[u]){
					ruc = max(ruc , a[o] ^ d);
					d++;
					o = par[o];
				}
				ans[j] = ruc;
				x++;
			}
			cur = max(cur , max_xor(k , h));
			k++;
			h = anc[h];
		}
	}
	for(int i = 0 ; i < q ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}