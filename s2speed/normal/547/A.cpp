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
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e6 + 15 , md = 1e9 + 7 , inf = 1e18;

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

ll cnt[MAXN] , d[2] , p[] = {-1 , -1};
bitset<MAXN> mark;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , -1 , sizeof(cnt));
	ll m , h[2] , x[2] , y[2] , a[2];
	cin>>m>>h[0]>>a[0]>>x[0]>>y[0]>>h[1]>>a[1]>>x[1]>>y[1];
	ll tm = 0;
	while(true){
		if(cnt[h[0]] != -1){
			d[0] = (cnt[h[0]] <= cnt[a[0]] ? tm - cnt[h[0]] : -1);
			break;
		}
		if(h[0] == a[0]){
			p[0] = tm;
		}
		cnt[h[0]] = tm++;
		h[0] *= x[0];
		h[0] += y[0];
		h[0] %= m;
	}
	memset(cnt , -1 , sizeof(cnt));
	tm = 0;
	while(true){
		if(cnt[h[1]] != -1){
			d[1] = (cnt[h[1]] <= cnt[a[1]] ? tm - cnt[h[1]] : -1);
			break;
		}
		if(h[1] == a[1]){
			p[1] = tm;
		}
		cnt[h[1]] = tm++;
		h[1] *= x[1];
		h[1] += y[1];
		h[1] %= m;
	}
	if(p[0] == -1 || p[1] == -1){
		cout<<"-1\n";
		return 0;
	}
	if(d[0] == -1 && d[1] == -1){
		if(p[0] == p[1]){
			cout<<p[0]<<'\n';
		} else {
			cout<<"-1\n";
		}
		return 0;
	}
	if(d[0] == -1){
		if(p[0] % d[1] == p[1] % d[1] && p[0] >= p[1]){
			cout<<p[0]<<'\n';
		} else {
			cout<<"-1\n";
		}
		return 0;
	}
	if(d[1] == -1){
		if(p[1] % d[0] == p[0] % d[0] && p[1] >= p[0]){
			cout<<p[1]<<'\n';
		} else {
			cout<<"-1\n";
		}
		return 0;
	}
	while(p[0] < p[1]){
		p[0] += d[0];
	}
	ll g = p[0] % d[1] , o = p[1] % d[1];
	while(true){
		if(g == o){
			cout<<p[0]<<'\n';
			return 0;
		}
		if(mark[g]) break;
		mark[g] = true;
		p[0] += d[0];
		g += d[0]; g %= d[1];
	}
	cout<<"-1\n";
	return 0;
}

/*

*/