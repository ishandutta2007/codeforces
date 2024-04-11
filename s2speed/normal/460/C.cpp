#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

struct fentree {

    ll sz = 0;
    vector<int> val;

    void init(ll n){
        sz = n;
        val.assign(n , 0);
        return;
    }
    
    void set(ll i , ll v){
        ll ind = i;
        while(ind >= 0){
            val[ind] += v;
            ind &= (ind + 1); ind--;
        }
        return;
    }

    void set(ll l , ll r , ll v){
        r = min(r , sz); l = min(l , sz);
        set(r - 1 , v);
        set(l - 1 , -v);
        return;
    }

    ll cal(ll i){
        ll h = 0 , ind = i;
        while(ind < sz){
            h += val[ind];
            ind |= (ind + 1);
        }
        return h;
    }

    void clear(){
        sz = 0;
        val.clear();
    }

};

ll a[MAX_N] , h[MAX_N] , n , m , w , mn = 1e10 , cnt = 0;
fentree ft;

bool check(ll v){
    ft.init(n);
    cnt = 0;
    for(int i = 0 ; i < n ; i++){
        h[i] =  v - a[i];
    }
    for(int i = 0 ; i < n ; i++){
        ll o = h[i] + ft.cal(i);
        if(o <= 0) continue;
        cnt += o;
        ft.set(i , i + w , -o);
    }
    ft.clear();
    return (cnt <= m);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
    cin>>n>>m>>w;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        mn = min(mn , a[i]);
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i] == mn){
            cnt++;
            i += w - 1;
        }
    }
    ll l = mn , r = mn + m + 1;
    while(l < r - 1){
        ll u = (r + l) / 2;
        if(check(u)){
            l = u;
        } else {
            r = u;
        }
    }
    cout<<l<<'\n';
	return 0;
}