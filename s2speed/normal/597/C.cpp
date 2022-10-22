#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 1e5 + 20;

struct segtree{
	
	ll size;
	vector<ll> values;
	
	ll NORMAL_ll = 0;
	
	ll single(ll v){
		return v;
	}
	
	ll merge(ll a , ll b){
		return a + b;
	}
	
	void init(ll n){
		size = 1;
		while(size < n) size *= 2;
		values.assign(2 * size - 1 , NORMAL_ll);
	}
	
	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < a.size()) values[x] = single(a[lx]);
			return;
		}
		ll m = (lx + rx) / 2;
		build(a , 2 * x + 1 , lx , m); build(a , 2 * x + 2 , m , rx);
		values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
		return;
	}
	
	void build(vector<ll> &a){
		build(a , 0 , 0 , size);
	}
	
	void set(ll i , ll v , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			values[x] += v;
			return;
		}
		ll m = (rx + lx) / 2;
		if(i < m){
			set(i , v , 2 * x + 1 , lx , m);
		} else {
			set(i , v , 2 * x + 2 , m , rx);
		}
		values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
	}
	
	void set(ll i , ll v){
		set(i , v , 0 , 0 , size);
		return;
	}
	
	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(lx >= r || rx <= l) return NORMAL_ll;
		if(lx >= l && rx <= r){
			return values[x];
		}
		ll m = (lx + rx) / 2;
		ll i1 = cal(l , r , 2 * x + 1 , lx , m) , i2 = cal(l , r , 2 * x + 2 , m , rx);
		return merge(i1 , i2); 
	}
	
	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , size);
	}

	void clear(){
		values.clear();
		size = 0;
	}
	
};

segtree dp[13];
ll a[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , k;
    cin>>n>>k;
    for(int i = 1 ; i <= k + 1 ; i++){
        dp[i].init(n + 1);
    }
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    for(int i = 0 ; i < n ; i++){
        dp[1].set(a[i] , 1);
        for(int j = 2 ; j <= k + 1 ; j++){
            dp[j].set(a[i] , dp[j - 1].cal(1 , a[i]));
        }
    }
    ll ans = dp[k + 1].cal(1 , n + 1);
    cout<<ans<<"\n";
	return 0;
}