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

const ll MAXN = 2e5 + 15 , MAXA = 25e5 + 15 , md = 1e9 + 7 , inf = 1e10;

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

vector<pll> v;
set<ll> s;
ll o[MAXA] , cnt[2 * MAXA] , cn[MAXA] , a[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(o , -1 , sizeof(o));
	memset(cnt , 0 , sizeof(cnt));
	memset(cn , 0 , sizeof(cn));
	ll n , f = -1;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		cn[a[i]]++;
		v.push_back({a[i] , i});
	}
	sort(all(v));
	for(ll i = 0 ; i < n - 1 ; i++){
		ll h = v[i + 1].first - v[i].first;
		if(o[h] != -1){
			if(o[h] == i - 1) continue;
			cout<<"YES\n";
			cout<<v[o[h]].second<<' '<<v[i + 1].second<<' '<<v[o[h] + 1].second<<' '<<v[i].second<<'\n';
			return 0;
		} else {
			o[h] = i;
		}
	}
	for(ll i = 1 ; i < n ; i++){
		for(ll j = i + 1 ; j <= n ; j++){
			cnt[a[i] + a[j]]++;
		}
	}
	for(ll i = 1 ; i < n ; i++){
		for(ll j = i + 1 ; j <= n ; j++){
			ll help;
			if(cn[a[i]] == 1){
				help = cn[a[j]];
			} else {
				help = cn[a[i]];
			}
			if(a[i] == a[j]){
				if(cn[a[i]] >= 4){
					help = 0;
				} else {
					help = cn[a[i]] * (cn[a[i]] - 1) / 2;
				}
			}
			if(cnt[a[i] + a[j]] > help){
				cout<<"YES\n"<<i<<' '<<j<<' ';
				for(ll q = 1 ; q < n ; q++){
					if(q == i || q == j) continue;
					for(ll e = q + 1 ; e <= n ; e++){
						if(e == j || e == i) continue;
						if(a[q] + a[e] == a[j] + a[i]){
							cout<<q<<' '<<e<<'\n';
							return 0;
						}
					}
				}
			}
		}
	}
	cout<<"NO\n";
	return 0;
}

/*

*/