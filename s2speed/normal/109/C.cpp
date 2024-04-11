#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 1e5 + 20 , md = 1e9 + 7;
 
int tav(ll n , ll k){
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

vector<int> dsu[MAX_N];
int ds[MAX_N];

bool is_lucky(string s){
	int n = s.size();
	for(int i = 0 ; i < n ; i++){
		if(s[i] != '4' && s[i] != '7'){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ds[i] = i;
		dsu[i].push_back(i);
	}
	for(int i = 1 ; i < n ; i++){
		int v , u;
		string s;
		cin>>v>>u>>s; v--; u--;
		if(!is_lucky(s)){
			if(dsu[ds[u]].size() > dsu[ds[v]].size()){
				swap(u , v);
			}
			int k = ds[u] , l = dsu[k].size();
			for(int j = 0 ; j < l ; j++){
				dsu[ds[v]].push_back(dsu[k][j]);
				ds[dsu[k][j]] = ds[v];
			}
		}
	}
	ll ans = 0;
	for(int i = 0 ; i < n ; i++){
		ll h = dsu[ds[i]].size();
		h = n - h;
		h *= h - 1;
		ans += h;
	}
	cout<<ans<<'\n';
	return 0;
}