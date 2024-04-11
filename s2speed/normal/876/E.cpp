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

bool bomb[MAX_N] , explosion = false , mark[MAX_N];
vector<int> adj[MAX_N] , o , a , b , t;

void DFS(int r){
	mark[r] = true;
	o.push_back(r);
	if(bomb[r]){
		explosion = true;
		return;
	}
	for(auto i : adj[r]){
		if(mark[i]) continue;
		DFS(i);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , m , k;
	cin>>n>>m>>k;
	fill(bomb , bomb + n , false);
	fill(mark , mark + n , false);
	a.resize(k);
	for(int i = 0 ; i < k ; i++){
		cin>>a[i]; a[i]--;
	}
	for(int i = 1 ; i < n ; i++){
		cin>>k;
		b.resize(k);
		int lm = a.size() , dif = -1; lm = min(lm , k);
		for(int j = 0 ; j < k ; j++){
			cin>>b[j]; b[j]--;
		}
		for(int j = 0 ; j < lm ; j++){
			if(a[j] != b[j]){
				dif = j;
				break;
			}
		}
		if(dif == -1 && a.size() > k){
			cout<<"No\n";
			return 0;
		}
		if(dif == -1){
			a.clear();
			a = b;
			b.clear();
			continue;
		}
		if(a[dif] > b[dif]){
			t.push_back(a[dif]);
			bomb[b[dif]] = true;
		} else {
			adj[b[dif]].push_back(a[dif]);
		}
		a.clear();
		a = b;
		b.clear();
	}
	for(auto i : t){
		if(mark[i]) continue;
		DFS(i);
	}
	if(explosion){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	cout<<o.size()<<'\n';
	sort(all(o));
	for(auto i : o){
		cout<<i + 1<<' ';
	}
	return 0;
}