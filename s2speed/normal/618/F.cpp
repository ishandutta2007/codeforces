#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e6 + 16 , maxq = 5e4 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

ll a[maxn] , b[maxn] , s[maxn] , f[maxn] , ind[maxn];
vector<ll> pa , pb;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(ind , -1 , sizeof(ind));
	ll n;
	cin>>n;
	pa.resize(n + 1); pb.resize(n + 1);
	pa[0] = pb[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		pa[i] = pa[i - 1] + a[i];
	}
	for(ll i = 1 ; i <= n ; i++){
		cin>>b[i];
		pb[i] = pb[i - 1] + b[i];
	}
	bool q = false;
	if(pa[n] > pb[n]){
		swap(a , b);
		swap(pa , pb);
		q = true;
	}
	for(ll i = 1 ; i <= n ; i++){
		ll j = upper_bound(all(pb) , pa[i]) - pb.begin() - 1;
		if(pb[j] == pa[i]){
			if(!q){
				cout<<i<<'\n';
				for(ll c = 1 ; c <= i ; c++){
					cout<<c<<' ';
				}
				cout<<'\n';
				cout<<j<<'\n';
				for(ll c = 1 ; c <= j ; c++){
					cout<<c<<' ';
				}
				cout<<'\n';
			} else {
				cout<<j<<'\n';
				for(ll c = 1 ; c <= j ; c++){
					cout<<c<<' ';
				}
				cout<<'\n';
				cout<<i<<'\n';
				for(ll c = 1 ; c <= i ; c++){
					cout<<c<<' ';
				}
				cout<<'\n';
			}
			return 0;
		}
		f[i] = j;
		s[i] = pa[i] - pb[j];
		if(ind[s[i]] == -1){
			ind[s[i]] = i;
			continue;
		}
		if(!q){
			cout<<i - ind[s[i]]<<'\n';
			for(ll c = ind[s[i]] + 1 ; c <= i ; c++){
				cout<<c<<' ';
			}
			cout<<'\n';
			cout<<j - f[ind[s[i]]]<<'\n';
			for(ll c = f[ind[s[i]]] + 1 ; c <= j ; c++){
				cout<<c<<' ';
			}
			cout<<'\n';
		} else {
			cout<<j - f[ind[s[i]]]<<'\n';
			for(ll c = f[ind[s[i]]] + 1 ; c <= j ; c++){
				cout<<c<<' ';
			}
			cout<<'\n';
			cout<<i - ind[s[i]]<<'\n';
			for(ll c = ind[s[i]] + 1 ; c <= i ; c++){
				cout<<c<<' ';
			}
			cout<<'\n';
		}
		return 0;
	}
	return 0;
}