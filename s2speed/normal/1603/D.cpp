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

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e12;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

vector<ll> pr[maxn];
bitset<maxn> gh;

void prime(){
	gh.set();
	for(ll i = 2 ; i < maxn ; i++){
		if(!gh[i]) continue;
		for(ll j = i ; j < maxn ; j += i){
			gh[j] = false;
			pr[j].push_back(i);
		}
	}
	return;
}

ll fi[maxn] , ps[maxn] , dp[maxn][18] , cur[18] , x[18] , y[18];
vector<ll> dv[maxn] , sf[maxn];

void add(ll j){
	ll h = lower_bound(all(dv[y[j]]) , x[j]) - dv[y[j]].begin();
	cur[j] += sf[y[j]][h]; y[j]++;
	return;
}

void del(ll j){
	ll h = (y[j] - 1) / x[j];
	cur[j] -= ps[h]; x[j]++;
	return;
}

void dp_build(ll l , ll r , ll opl , ll opr , ll k , ll j){
	if(x[j] >= y[j]){
		x[j] = y[j] = opl + 1;
		cur[j] = 0;
	}
	ll m = (r + l) >> 1 , lm = min(m , opr + 1);
//	if(m == 20 && l == 20){
//		cout<<l<<' '<<r<<' '<<opl<<' '<<opr<<' '<<x[j]<<' '<<y[j]<<' '<<cur[j]<<'\n';
//	}
	while(y[j] <= m) add(j);
	while(x[j] <= opl) del(j);
	ll res = inf , ind = -1;
//	cout<<l<<' '<<r<<' '<<opl<<' '<<opr<<endl;
	for(ll i = opl ; i < lm ; i++){
		if(dp[i][k - 1] + cur[j] <= res){
			res = dp[i][k - 1] + cur[j];
			ind = i;
		}
		if(i != opr) del(j);
	}
//	if(m == 20 && l == 19){
//		cout<<ind<<'\n';
//	}
	dp[m][k] = res;
	if(r - l == 1) return;
	dp_build(l , m , opl , ind , k , j + 1); dp_build(m , r , ind , opr , k , j + 1);
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	prime();
	memset(fi , 0 , sizeof(fi));
	memset(dp , 0 , sizeof(dp));
	ll n = 1e5;
	for(ll i = 2 ; i <= n ; i++){
		ll ps = sze(pr[i]) , lm = (1 << ps);
		for(ll mask = 0 ; mask < lm ; mask++){
			ll cnt = 0;
			ll h = 1;
			for(ll j = 0 ; j < ps ; j++){
				if(!((1 << j) & mask)) continue;
				cnt ^= 1;
				h *= pr[i][j];
			}
			fi[i] += (i / h) * (1 - (cnt << 1));
		}
	}
	ps[0] = 0;
	for(ll i = 1 ; i <= n ; i++) ps[i] = ps[i - 1] + fi[i];
	for(ll i = 1 ; i <= n ; i++){
		for(ll j = i ; j <= n ; j += i){
			dv[j].push_back(i);
		}
	}
	for(ll i = 1 ; i <= n ; i++){
		ll ds = sze(dv[i]);
		sf[i].push_back(0);
		for(ll j = ds - 2 ; j >= 0 ; j--){
			sf[i].push_back(sf[i].back() + fi[i / dv[i][j]]);
		}
		reverse(all(sf[i]));
	}
	for(ll i = 1 ; i <= n ; i++){
		dp[i][1] = 1ll * i * (i - 1) / 2;
	}
	for(ll i = 2 ; i <= 17 ; i++){
		for(ll j = 0 ; j < 18 ; j++){
			cur[j] = 0;
			x[j] = y[j] = 1;
		}
		dp_build(1 , n + 1 , 0 , n + 1 , i , 0);
	}
//	for(ll i = 1 ; i <= 17 ; i++){
//		for(ll j = 2 ; j <= n ; j++){
//			if(dp[j][i] < dp[j - 1][i]){
//				cout<<i<<' '<<j<<'\n';
//				break;
//			}
//		}
//	}
//	for(ll j = 19 ; j < 24 ; j++){
//		cout<<dp[j][2]<<' ';
//	}
//	cout<<'\n';
	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll n , k;
		cin>>n>>k;
		if(k > 17){
			cout<<n<<'\n';
			continue;
		}
		cout<<dp[n][k] + n<<'\n';
	}
	return 0;
}