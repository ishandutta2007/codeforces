#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e2 + 16 , maxm = 77e3 + 16 , md = 998244353 , inf = 2e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

unordered_map<string , ll> t;
ll last;
vector<ll> adj[maxn + maxm];
bitset<maxn> mark;
ll mt[maxn + maxm] , M = 0;
string s[maxn + maxm];

bool DFS(ll r){
	mark[r] = true;
	for(auto i : adj[r]){
		if(mt[i] == -1){
			mt[i] = r;
			mt[r] = i;
			return true;
		}
		if(mark[mt[i]]) continue;
		if(DFS(mt[i])){
			mt[i] = r;
			mt[r] = i;
			return true;
		}
	}
	return false;
}

string o;

bool shift(){
	ll os = o.size();
	bool ch = false;
	for(ll i = 0 ; i < os ; i++){
		if(o[i] == '0') ch = true;
		if(ch && o[i] == '1'){
			o[i - 1]++; o[i]--;
			return true;
		}
	}
	return false;
}

void add(string &h , ll ind){
	ll hs = h.size() , lm = min(hs , 4ll);
	for(ll e = 1 ; e <= lm ; e++){
		o.clear();
		string u;
		for(ll q = 0 ; q < hs - e ; q++){
			o += '0';
		}
		for(ll q = hs - e ; q < hs ; q++){
			o += '1';
			u += h[q];
		}
		if(!t.count(u)){
			t[u] = last;
			s[last++] = u;
		}
		adj[ind].push_back(t[u]); adj[t[u]].push_back(ind);
		while(shift()){
			u.clear();
			for(ll q = 0 ; q < hs ; q++){
				if(o[q] == '1') u += h[q];
			}
			if(!t.count(u)){
				t[u] = last;
				s[last++] = u;
			}
			adj[ind].push_back(t[u]); adj[t[u]].push_back(ind);
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(mt , -1 , sizeof(mt));
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ll n;
	fin>>n; last = n;
	for(ll i = 0 ; i < n ; i++){
		fin>>s[i];
		add(s[i] , i);
	}
	for(ll i = 0 ; i < n ; i++){
		mark.reset();
		if(DFS(i)) M++;
	}
	if(M < n){
		fout<<"-1\n";
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		fout<<s[mt[i]]<<'\n';
	}
	return 0;
}