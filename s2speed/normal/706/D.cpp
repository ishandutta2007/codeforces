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

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

ll cnt[MAXN * 30] , tr[MAXN * 30][2] , last = 0;

void insert(bitset<30> b){
	ll v = 0;
	for(ll i = 29 ; i >= 0 ; i--){
		if(tr[v][b[i]] == -1){
			tr[v][b[i]] = ++last;
		}
		v = tr[v][b[i]];
		cnt[v]++;
	}
	return;
}

void del(bitset<30> b){
	ll v = 0;
	for(ll i = 29 ; i >= 0 ; i--){
		v = tr[v][b[i]];
		cnt[v]--;
	}
	return;
}

ll cal(bitset<30> b){
	ll v = 0 , res = 0 , h = 1 << 29;
	for(ll i = 29 ; i >= 0 ; i--){
		ll o = tr[v][!b[i]];
		if((o == -1 ? true : cnt[o] == 0)){
			v = tr[v][b[i]];
			h >>= 1;
			continue;
		}
		res += h;
		v = o;
		h >>= 1;
	}
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(tr , -1 , sizeof(tr));
	memset(cnt , 0 , sizeof(cnt));
	cnt[0] = inf;
	ll q;
	cin>>q;
	bitset<30> h;
	insert(h);
	while(q--){
		char c;
		ll a;
		cin>>c>>a;
		h = a;
		if(c == '+'){
			insert(h);
		}
		if(c == '-'){
			del(h);
		}
		if(c == '?'){
			cout<<cal(h)<<'\n';
		}
	}
	return 0;
}

/*

*/