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

const ll maxn = 1e3 + 17 , maxd = 1e4 + 17 , md = 1e9 + 17 , inf = 2e16;

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

ll n , k , d , dv = 1;
ll a[maxn] , f[maxn] , pd[maxn][maxd];
pll dp[maxn][maxd];
vector<ll> pr;
vector<ll> tv , v[maxd];
ll z[12];

inline ll v_i(vector<ll> &a){
	ll z = 1 , res = 0;
	for(ll j = 0 ; j < d ; j++){
		res += a[j] * z;
		z *= tv[j] + 1;
	}
	return res;
}

vector<ll> res;

inline vector<ll> i_v(ll o){
	for(ll j = d - 1 ; ~j ; j--){
		res[j] = o / z[j];
		o %= z[j];
	}
	return res;
}

inline ll zarb(ll a , ll b){
	for(ll i = 0 ; i < d ; i++){
		res[i] = min(v[a][i] + v[b][i] , tv[i]);
	}
	return v_i(res);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 63 , sizeof(dp));
	memset(pd , 0 , sizeof(pd));
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	if(k == 1){
		ll mn = inf , ind = -1;
		for(ll i = 0 ; i < n ; i++){
			if(a[i] < mn){
				mn = a[i];
				ind = i;
			}
		}
		cout<<"1\n"<<ind + 1<<'\n';
		return 0;
	}
	for(ll i = 2 ; i <= 1e6 ; i++){
		ll cnt = 0;
		while(k % i == 0){
			k /= i;
			cnt++;
		}
		if(!cnt) continue;
		pr.push_back(i);
		tv.push_back(cnt);
		z[sze(pr) - 1] = dv;
		dv *= cnt + 1;
//		cout<<i<<' '<<cnt<<'\n';
	}
	if(k != 1){
		pr.push_back(k);
		tv.push_back(1);
		z[sze(pr) - 1] = dv;
		dv <<= 1;
	}
	d = sze(pr); res.resize(d);
	for(ll i = 0 ; i < n ; i++){
		ll h = 0 , b = a[i];
		for(ll j = 0 ; j < d ; j++){
			ll cnt = 0;
			while(b % pr[j] == 0){
				b /= pr[j];
				cnt++;
			}
			cnt = min(cnt , tv[j]);
			h += cnt * z[j];
		}
		f[i] = h;
//		cout<<f[i]<<' ';
	}
//	cout<<'\n';
	for(ll i = 0 ; i < dv ; i++){
		v[i] = i_v(i);
	}
	dp[0][f[0]] = {1 , a[0]};
	dp[0][0] = {0 , 0};
	for(ll i = 1 ; i < n ; i++){
		for(ll j = 0 ; j < dv ; j++){
			ll h = zarb(j , f[i]);
			pll v = {dp[i - 1][j].first + 1 , dp[i - 1][j].second + a[i]};
			if(v < dp[i][h]){
				dp[i][h] = v;
				pd[i][h] = j;
			}
			if(dp[i - 1][j] < dp[i][j]){
				dp[i][j] = dp[i - 1][j];
				pd[i][j] = j;
			}
		}
	}
//	cout<<dp[2][5].first<<' '<<dp[2][5].second<<' '<<pd[2][5]<<'\n';
	if(dp[n - 1][dv - 1].first > n){
		cout<<"-1\n";
		return 0;
	}
	cout<<dp[n - 1][dv - 1].first<<'\n';
	ll v = dv - 1;
	for(ll i = n - 1 ; ~i ; i--){
		if(pd[i][v] != v){
			cout<<i + 1<<' ';
		}
		v = pd[i][v];
	}
	cout<<'\n';
	return 0;
}