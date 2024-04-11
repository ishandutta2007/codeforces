#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 3e5 + 20 , md = 1e9 + 7;
 
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

int ds[MAX_N] , dsz[MAX_N];

int dsu(int v){
    return ds[v] = (ds[v] == v ? v : dsu(ds[v]));
}

void unite(int v , int u){
    v = dsu(v); u = dsu(u);
    if(v == u) return;
    if(dsz[u] > dsz[v]) swap(v , u);
    dsz[v] += dsz[u]; dsz[u] = 0;
    ds[u] = v;
    return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
    cin>>n;
    fill(ds , ds + n , -1);
    ds[n] = n; dsz[n] = 1;
    cout<<"1 ";
    for(int i = 0 ; i < n ; i++){
        int h;
        cin>>h; h--;
        ds[h] = h; dsz[h] = 1;
        if(h > 0){
            if(ds[h - 1] != -1){
                unite(h , h - 1);
            }
        }
        if(ds[h + 1] != -1){
            unite(h , h + 1);
        }
        cout<<i - dsz[dsu(n)] + 3<<' ';
    }
    cout<<'\n';
	return 0;
}