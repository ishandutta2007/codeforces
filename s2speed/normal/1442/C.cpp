#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 4e5 + 20 , md = 998244353;

vector< pair<ll , ll> > ad[MAX_N * 10];
vector<ll> adj[MAX_N] , q[MAX_N * 3];
pair<ll , ll> dis[MAX_N];
set< pair< pair<ll , ll> , ll> > s;
bool mark[MAX_N * 10];
ll t[20];
int n , m;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x % md;
	} else {
		return x * x % md * n % md;
	}
}


void Dij1(){
    while(s.size() > 0){
        set< pair< pair<ll , ll> , ll> >::iterator it = s.begin();
        pair< pair<ll , ll> , ll> p;
        p = *it;
        int v = p.second;
        mark[v] = true;
        for(auto u : adj[v]){
            if(!mark[u]){
                s.erase( {dis[u] , u} );
                if(u == v + n || u == v - n){
                    dis[u] = min(dis[u] , {dis[v].first + 1 , dis[v].second});
                    s.insert({dis[u] , u});
                } else {
                    dis[u] = min(dis[u] , {dis[v].first , dis[v].second + 1});
                    s.insert({dis[u] , u});
                }
            }
        }
        s.erase(it);
    }
    return;
}

void Dij2(){
    for(int i = 0 ; i < 3 * MAX_N ; i++){
        for(auto v : q[i]){
            if(v % n == n - 1){
                cout<<i<<"\n";
                return;
            }
            if(mark[v]){
                mark[v] = false;
                for(auto pl : ad[v]){
                    int u = pl.first , w = pl.second;
                    if(mark[u]){
                        int d = i + w;
                        if(d < 3 * MAX_N){
                            q[d].push_back(u);
                        }
                    }
                }
            }
        }
    }
    return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin>>u>>v; u--; v--;
        adj[u].push_back(v);
        adj[v + n].push_back(u + n);
        for(int j = 0 ; j < 20 ; j += 2){
            ad[u + j * n].push_back({v + j * n , 1});
        }
        for(int j = 1 ; j < 20 ; j += 2){
            ad[v + j * n].push_back({u + j * n , 1});
        }
    }
    t[0] = 1;
    for(int j = 1 ; j < 20 ; j++){
        t[j] = t[j - 1] * 2;
    }
    for(int i = 0 ; i < n ; i++){
        adj[i].push_back(i + n);
        adj[i + n].push_back(i);
        mark[i] = false; mark[i + n] = false;
        dis[i] = {1e18 , 1e18}; dis[i + n] = {1e18 , 1e18};
        for(int j = 0 ; j < 19 ; j++){
            ad[i + j * n].push_back({i + (j + 1) * n , t[j]});
        }
    }
    dis[0] = {0 , 0};
    s.insert( {{0 , 0} , 0} );
    Dij1();
    pair<ll , ll> o = min(dis[n - 1] , dis[2 * n - 1]);
    if(o.first >= 20){
        ll ans = tav(2 , o.first) + o.second - 1;
        ans %= md;
        cout<<ans<<"\n";
        return 0;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 20 ; j++){
            mark[i + j * n] = true;
        }
    }
    q[0].push_back(0);
    Dij2();
	return 0;
}