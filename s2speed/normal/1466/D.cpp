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

vector<ll> v;
ll a[MAX_N] , d[MAX_N];

void solve(){
	ll n , sum = 0;
    cin>>n;
    v.clear();
    for(int i = 0 ; i < n ; i++){
        d[i] = 0;
    }
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        sum += a[i];
    }
    for(int i = 1 ; i < n ; i++){
        ll v , u;
        cin>>v>>u; v--; u--;
        d[v]++; d[u]++;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j < d[i] ; j++){
            v.push_back(a[i]);
        }
    }
    sort(v.begin() , v.end() , greater<ll>());
    for(int i = 0 ; i < n - 2 ; i++){
        cout<<sum<<' ';
        sum += v[i];
    }
    cout<<sum<<'\n';
    return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}