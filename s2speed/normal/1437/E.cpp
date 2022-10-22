#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 5e5 + 20;

struct segtree{
	
	ll size;
	vector<ll> values;
	
	ll NORMAL_ll = 0;
	
	ll single(ll v){
		return v;
	}
	
	ll merge(ll a , ll b){
		return max(a , b);
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
			values[x] = single(v);
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
	
	ll calc(ll l , ll r , ll x , ll lx , ll rx){
		if(lx >= r || rx <= l) return NORMAL_ll;
		if(lx >= l && rx <= r){
			return values[x];
		}
		ll m = (lx + rx) / 2;
		ll i1 = calc(l , r , 2 * x + 1 , lx , m) , i2 = calc(l , r , 2 * x + 2 , m , rx);
		return merge(i1 , i2); 
	}
	
	ll calc(ll l , ll r){
		return calc(l , r , 0 , 0 , size);
	}

    void clear(){
        values.clear();
        size = 0;
    }
	
};

ll a[MAX_N];
vector<ll> v , b , p , dp;
vector< pair<ll , ll> > y , s;
segtree st;

ll bs(ll i){
    pair<ll , ll> h;
    h = y[i];
    ll l = 0 , r = v.size();
    while(l < r - 1){
        ll m = (l + r) / 2;
        if(s[m] == h){
            return m;
        }
        if(s[m] < h){
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

ll LIS(ll l , ll r){
    s.clear();
    v.clear();
    p.clear();
    dp.clear();
    st.clear();
    y.clear();
    ll q = a[r] - (r - l);
    if(q < a[l]){
        return -1;
    }
    for(ll i = l ; i <= r ; i++){
        ll o = a[i] - (i - l);
        if(o >= a[l] && o <= q){
            s.push_back( {o , i} );
            v.push_back(o);
            y.push_back( {o , i} );
        }
    }
    ll vs = v.size();
    p.resize(vs);
    dp.assign(vs , 0);
    st.init(vs);
    sort(s.begin() , s.end());
    for(ll i = 0 ; i < vs ; i++){
        p[i] = bs(i);
    }
    ll m = 1;
    dp[0] = 1;
    st.set(0 , 1);
    for(ll i = 1 ; i < vs ; i++){
        dp[i] = st.calc(0 , p[i]) + 1;
        m = max(dp[i] , m);
        st.set(p[i] , dp[i]);
    }
    return m;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
    ll n , k,  ans = 0;
    cin>>n>>k;
    a[0] = -1e18;
    for(ll i = 1 ; i <= n ; i++){
        cin>>a[i];
    }
    a[n + 1] = 1e18;
    b.resize(k + 2);
    b[0] = 0;
    for(ll i = 1 ; i <= k ; i++){
        cin>>b[i];
    }
    b[k + 1] = n + 1;
    for(ll i = 0 ; i <= k ; i++){
        ll z = LIS(b[i] , b[i + 1]);
        if(z == -1){
            cout<<"-1\n";
            return 0;
        }
        ans += b[i + 1] - b[i] + 1 - z;
    }
    cout<<ans<<"\n";
	return 0;
}