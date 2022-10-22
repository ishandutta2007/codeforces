#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e3 + 20 , md = 1e9 + 7 , inf = 2e9 + 1;
// check problem statement

ll d[MAXN];
string s[MAXN];
vector<ll> adj[MAXN] , path , cy;
set<ll> st;
vector<pll> v;
bitset<MAXN> mark;
bool f;

void DFS(ll r){
	mark[r] = true;
	st.insert(r);
	path.push_back(r);
	for(auto i : adj[r]){
		if(st.count(i)){
			cy.push_back(i);
			while(path.back() != i){
				cy.push_back(path.back());
				path.pop_back();
			}
			f = true;
			return;
		}
		if(mark[i]) continue;
		DFS(i);
		if(f) return;
	}
	st.erase(r);
	path.pop_back();
	return;
}

void solve(){
	st.clear(); cy.clear(); path.clear(); f = false;
	ll n , m;
	cin>>n>>m;
	fill(d , d + n , 0);
	for(ll i = 0 ; i < n ; i++){
		cin>>s[i];
		mark[i] = false;
		adj[i].clear();
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i + 1 ; j < n ; j++){
			if(s[i][j] == s[j][i]){
				cout<<"YES\n";
				for(ll q = 0 ; q <= m ; q++){
					cout<<(q % 2 ? i : j) + 1<<' ';
				}
				cout<<'\n';
				return;
			}
		}
	}
	if(m % 2 == 1){
		cout<<"YES\n";
		for(ll i = 0 ; i <= m ; i++){
			cout<<i % 2 + 1<<' ';
		}
		cout<<'\n';
		return;
	}
	if(n == 2){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i + 1 ; j < n ; j++){
			if(s[i][j] == 'a'){
				d[i]++;
				adj[i].push_back(j);
			} else {
				d[j]++;
				adj[j].push_back(i);
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		DFS(i);
		if(f) break;
	}
	if(f){
		ll x = cy.size();
		for(ll i = 0 ; i <= m ; i++){
			cout<<cy[i % x] + 1<<' ';
		}
		cout<<'\n';
		return;
	}
	v.clear();
	for(ll i = 0 ; i < 3 ; i++){
		v.push_back({d[i] , i});
	}
	sort(all(v));
	ll a = v[0].second + 1 , b = v[1].second + 1 , c = v[2].second + 1;
	if(m % 4 == 0){
		cout<<b<<' ';
		ll q = m / 2;
		for(ll i = 0 ; i < q ; i++){
			cout<<(i % 2 == 0 ? c : b)<<' ';
		}
		for(ll i = 0 ; i < q ; i++){
			cout<<(i % 2 == 0 ? a : b)<<' ';
		}
		cout<<'\n';
		return;
	}
	cout<<a<<' ';
	ll q = m / 2;
	for(ll i = 0 ; i < q ; i++){
		cout<<(i % 2 == 0 ? b : a)<<' ';
	}
	for(ll i = 0 ; i < q ; i++){
		cout<<(i % 2 == 0 ? c : b)<<' ';
	}
	cout<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*
1
3 6
*ab
b*a
ab*
*/