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

vector<char> v;
string a , b , h;
ll n;

void solve(int r){
	int vs = v.size();
	for(int i = 0 ; i < vs ; i++){
		if(v[i] == b[r]){
			string o , q;
			for(int j = vs - 1 ; j >= 0 ; j--){
				if(j == i) continue;
				o += v[j];
			}
			q = b.substr(r + 1 , 100);
			if(o <= q){
				h += v[i];
				v.erase(v.begin() + i);
				solve(r + 1);
				return;
			}
		}
		if(v[i] < b[r]){
			h += v[i];
			for(int j = 0 ; j < vs ; j++){
				if(i == j) continue;
				h += v[j];
			}
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>a>>b;
	n = a.size();
	for(int i = 0 ; i < n ; i++){
		v.push_back(a[i]);
	}
	sort(v.begin() , v.end() , greater<char>());
	if(b.size() > n){
		for(int i = 0 ; i < n ; i++){
			cout<<v[i];
		}
		cout<<'\n';
		return 0;
	}
	solve(0);
	cout<<h<<'\n';
	return 0;
}