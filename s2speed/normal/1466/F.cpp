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

const ll MAX_N = 5e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

int ds[MAX_N] , dsz[MAX_N];

int dsu(int v){
	return ds[v] = (ds[v] == v ? v : dsu(ds[v]));
}

void unite(int v , int u){
	if(dsz[u] > dsz[v]) swap(v , u);
	ds[u] = v;
	dsz[v] += dsz[u]; dsz[u] = 0;
	return;
}

vector<int> v;
int cnt = 0;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m;
	cin>>n>>m;
	iota(ds , ds + m + 1 , 0);
	fill(dsz , dsz + m + 1 , 1);
	for(int i = 1 ; i <= n ; i++){
		int k , a , b = 0;
		cin>>k>>a;
		if(k == 2){
			cin>>b;
		}
		if(dsu(a) != dsu(b)){
			unite(ds[a] , ds[b]);
			v.push_back(i);
		}
	}
	for(int i = 0 ; i <= m ; i++){
		if(ds[i] == i) cnt++;
	}
	ll t = tav(2 , m + 1 - cnt);
	cout<<t<<' '<<m + 1 - cnt<<'\n';
	for(auto i : v){
		cout<<i<<' ';
	}
	cout<<'\n';
	return 0;
}