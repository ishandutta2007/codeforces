#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll {ll first , second , third;};
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 5e5 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

ll ds[MAXN] , dsl[MAXN] , dsr[MAXN];

ll dsu(ll v){
	return ds[v] = (ds[v] == v ? v : dsu(ds[v]));
}

void unite(ll v , ll u){
	v = dsu(v); u = dsu(u);
	if(v == u) return;
	dsl[v] = min(dsl[v] , dsl[u]);
	dsr[v] = max(dsr[v] , dsr[u]);
	ds[u] = v;
	return;
};

ll n , q , x;
ll pr[MAXN];
string s , c;
vector<ll> v;
bitset<MAXN> dead;

void left(){
	while(x > 0){
		x--;
		if(dead[x]) x = dsl[dsu(x)];
		if(!dead[x]) break;
	}
	x = dsr[dsu(x)];
	x += dead[x];
	return;
}

void right(){
	while(x < n - 1){
		x++;
		if(dead[x]) x = dsr[dsu(x)];
		if(!dead[x]) break;
	}
	x = dsl[dsu(x)];
	x -= dead[x];
	return;
}

void del(){
	ll o = pr[x] , h = x;
	if(o > h) swap(o , h);
	if(o > 0){
		if(dead[o - 1]) unite(o - 1 , o);
	}
	for(ll i = o ; i < h ; ){
		dead[i] = true;
		unite(i , i + 1);
		i = dsr[dsu(i)];
	}
	dead[h] = true;
	if(h < n - 1){
		if(dead[h + 1]) unite(h , h + 1);
	}
	x = dsr[dsu(h)]; x++;
	if(x == n){
		x--;
		x = dsl[ds[h]];
		x--;
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>q>>x;
	iota(ds , ds + n , 0);
	memcpy(dsl , ds , sizeof(ds));
	memcpy(dsr , ds , sizeof(ds));
	x--;
	cin>>s>>c;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == '('){
			v.push_back(i);
		} else {
			ll u = v.back();
			pr[u] = i;
			pr[i] = u;
			v.pop_back();
		}
	}
	for(ll i = 0 ; i < q ; i++){
		if(c[i] == 'L') left();
		if(c[i] == 'R') right();
		if(c[i] == 'D') del();
	}
	for(ll i = 0 ; i < n ; i++){
		if(!dead[i]) cout<<s[i];
	}
	cout<<'\n';
	return 0;
}

/*
10 6 4
((((()))))
DLDLRD
*/