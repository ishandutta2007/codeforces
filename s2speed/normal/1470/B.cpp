#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 1e6 + 20 , md = 1e9 + 7;
 
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

bool gh[1000];
vector<ll> pr;

void prime(){
	gh[0] = false; gh[1] = gh[0];
	for(int i = 2 ; i < 1000 ; i++){
		gh[i] = true;
	}
	for(int i = 2 ; i < 1000 ; i++){
		if(!gh[i]) continue;
		pr.push_back(i * i);
		for(int j = i * i ; j < 1000 ; j += i){
			gh[j] = false;
		}
	}
}

vector<ll> a;
ll n , q , cnt[MAX_N] , m1 , m2;

void solve(){
	ll h = 0;
	a.clear();
	m1 = 1;
	m2 = 1;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		for(auto v : pr){
			while(h % v == 0){
				h /= v;
			}
		}
		cnt[h]++;
		a.push_back(h);
	}
	for(int i = 0 ; i < n ; i++){
		m1 = max(m1 , cnt[a[i]]);
	}
	for(int i = 0 ; i < n ; i++){
		if(cnt[a[i]] % 2 == 0 && a[i] != 1){
			cnt[1] += cnt[a[i]]; cnt[a[i]] = 0;
		}
	}
	for(int i = 0 ; i < n ; i++){
		m2 = max(m2 , cnt[a[i]]);
	}
	m2 = max(m2 , cnt[1]);
	cin>>q;
	for(int i = 0 ; i < q ; i++){
		ll w;
		cin>>w;
		if(w == 0){
			cout<<m1<<'\n';
		}
		if(w > 0){
			cout<<m2<<'\n';
		}
	}
	for(int i = 0 ; i < n ; i++){
		cnt[a[i]] = 0;
	}
	cnt[1] = 0;
	return;
}

/*
1 9
14 14 14 36 44100 392 8 77 693
2 0 1
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	prime();
	memset(cnt , 0 , sizeof(cnt));
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}