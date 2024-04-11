#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll f[maxn] , pf[maxn] , fz;
ll a[maxn];
priority_queue<pll> pq;

void solve(){
	while(!pq.empty()) pq.pop();
	ll n , sum = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		pq.push({a[i] , i});
		sum += a[i];
	}
	ll t;
	for(t = 0 ; t < fz ; t++){
		if(pf[t] == sum) break;
		if(pf[t] > sum){
			cout<<"NO\n";
			return;
		}
	}
	ll pr = -1;
	while(t >= 0){
		if(pq.empty()){
			cout<<"NO\n";
			return;
		}
		pll p = pq.top(); pq.pop();
		ll i = p.second;
		if(a[i] < f[t]){
			cout<<"NO\n";
			return;
		}
		a[i] -= f[t];
		if(pr != -1){
			pq.push({a[pr] , pr});
		}
		pr = i;
		t--;
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	f[0] = f[1] = 1;
	for(fz = 2 ; fz < maxn ; fz++){
		f[fz] = f[fz - 1] + f[fz - 2];
		if(f[fz] > 1e11) break;
	}
	pf[0] = 1;
	for(ll i = 1 ; i < fz ; i++){
		pf[i] = pf[i - 1] + f[i];
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}