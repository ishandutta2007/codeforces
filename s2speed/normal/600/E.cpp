#include<bits/stdc++.h>

using namespace std;

#define all(x) x.begin() , x.end()
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 16;

ll cnt[maxn] , cm , s[maxn];
ll a[maxn] , c[maxn] , bt[maxn] , ft[maxn] , tme = 0 , ans[maxn];
vector<ll> adj[maxn];
vector<pllll> q;

void add(ll i){
	s[cnt[a[i]]] -= a[i];
	s[++cnt[a[i]]] += a[i];
	if(s[cm + 1] != 0) cm++;
	return;
}

void del(ll i){
	s[cnt[a[i]]] -= a[i];
	s[--cnt[a[i]]] += a[i];
	if(s[cm] == 0) cm--;
	return;
}

void bDFS(ll r , ll par){
	bt[r] = tme++;
	for(auto i : adj[r]){
		if(i == par) continue;
		bDFS(i , r);
	}
	ft[r] = tme;
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n , sq;
	cin>>n; sq = min(n , 350ll);
	for(ll i = 0 ; i < n ; i++){
		cin>>c[i];
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	bDFS(0 , -1);
	for(ll i = 0 ; i < n ; i++){
		a[bt[i]] = c[i];
		q.push_back({{bt[i] / sq , ft[i]} , {bt[i] , i}});
	}
	sort(all(q));
	ll l , r;
	l = r = 0;
	memset(cnt , 0 , sizeof(cnt));
	memset(s , 0 , sizeof(s));
	cm = 0;
	for(ll i = 0 ; i < n ; i++){
		ll lq = q[i].second.first , rq = q[i].first.second , j = q[i].second.second;
		while(l < lq){
			del(l++);
		}
		while(l > lq){
			add(--l);
		}
		while(r < rq){
			add(r++);
		}
		while(r > rq){
			del(--r);
		}
		ans[j] = s[cm];
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}