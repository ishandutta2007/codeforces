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

const ll MAXN = 1 << 19 , md = 1e9 + 7 , inf = 2e9 + 1;
// check problem statement

ll tr[19 * MAXN][2] , last = 0;

bitset<MAXN> mark;
vector<ll> v;

void insert(bitset<19> s){
	ll i = 18 , v = 0;
	while(i >= 0){
		if(tr[v][s[i]] == -1){
			tr[v][s[i]] = ++last;
		}
		v = tr[v][s[i]];
		i--;
	}
	return;
}

ll mex(bitset<19> s){
	ll i = 18 , v = 0 , h = 1 << 18 , res = 0;
	while(i >= 0){
		if(tr[v][s[i]] != -1){
			v = tr[v][s[i]];
		} else {
			v = tr[v][!s[i]];
			res += h;
		}
		h /= 2;
		i--;
	}
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(tr , -1 , sizeof(tr));
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		mark[h] = true;
	}
	for(ll i = 0 ; i < MAXN ; i++){
		if(mark[i]) continue;
		v.push_back(i);
	}
	bitset<19> h;
	for(auto i : v){
		h = i;
		insert(h);
	}
	h.reset();
	for(ll i = 0 ; i < m ; i++){
		ll x;
		cin>>x;
		h ^= x;
		cout<<mex(h)<<'\n';
	}
	return 0;
}

/*

*/