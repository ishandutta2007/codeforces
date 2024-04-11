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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e6 + 16 , md = 1e9 + 7 , inf = 2e17;

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

int n;
map<int , int> t;
int a[maxn] , b[maxn] , c[maxn];
vector<int> v , adj[maxn];
bitset<maxn> mark;
int sz , ed , dis[maxn];

void DFS(int r){
	mark[r] = true;
	sz++;
	for(auto i : adj[r]){
		ed++;
		if(mark[i]) continue;
		DFS(i);
	}
	return;
}

bool BFS(){
	int x = 0;
	while(x < sze(v)){
		int u = v[x++];
		for(auto i : adj[u]){
			if(dis[i] == dis[u] + 1 || dis[i] == dis[u]) return false;
			if(dis[i] > dis[u]){
				dis[i] = dis[u] + 1;
				v.push_back(i);
			}
		}
	}
	return true;
}

bool check(int x){
	mark.reset(); v.clear();
	memset(dis , 63 , sizeof(dis));
	for(int i = 0 ; i < n ; i++){
		int u = c[i];
		if(b[i] > x && !mark[u]){
			v.push_back(u);
			dis[u] = 0;
			mark[u] = true;
		}
	}
	return BFS();
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int l = 0 , r = 1e9 + 1;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i]>>b[i]; l = max(l , a[i] - 1);
		v.push_back(a[i]); v.push_back(b[i]);
	}
	sort(all(v));
	t[v[0]] = 0;
	int cnt = 1;
	for(int i = 1 ; i < (n << 1) ; i++){
		if(v[i] == v[i - 1]) continue;
		t[v[i]] = cnt++;
	}
	for(int i = 0 ; i < n ; i++){
		int v = t[a[i]] , u = c[i] = t[b[i]];
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(int i = 0 ; i < cnt ; i++){
		if(mark[i]) continue;
		sz = ed = 0;
		DFS(i);
		if(ed > (sz << 1)){
			cout<<"-1";
			return 0;
		}
	}
	while(l < r - 1){
		int m = (r + l) >> 1;
		if(check(m)){
			r = m;
		} else {
			l = m;
		}
	}
	cout<<l + 1<<'\n';
	return 0;
}