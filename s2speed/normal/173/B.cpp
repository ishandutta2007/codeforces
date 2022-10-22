#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const ll MAX_N = 1e6 + 20 , md = 1e9 + 7;
 
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

vector<int> adj[MAX_N] , v;
string s[MAX_N];
int x , dis[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n , m;
	cin>>n>>m;
	int l = n * m;
	for(int i = 0 ; i < l ; i++){
		dis[i] = 1e8;
	}
	for(int i = 0 ; i < n ; i++){
		cin>>s[i];
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(s[i][j] == '#'){
				adj[i].push_back(j + n); adj[j + n].push_back(i);
			}
		}
	}
	dis[n - 1] = 0;
	v.push_back(n - 1);
	while(x < v.size()){
		int r = v[x];
		for(auto i : adj[r]){
			if(dis[i] > dis[r] + 1){
				dis[i] = dis[r] + 1;
				v.push_back(i);
			}
		}
		x++;
	}
	if(dis[0] == 1e8){
		cout<<"-1\n";
	} else {
		cout<<dis[0]<<' ';
	}
	return 0;
}