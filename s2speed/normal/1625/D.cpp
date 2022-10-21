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

const ll maxn = 4e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll tr[maxn][2] , sz = 1 , in[maxn];

void add(ll k , ll i){
	ll v = 0;
	for(ll j = 29 ; ~j ; j--){
		bool c = k & (1 << j);
		if(tr[v][c] == -1){
			tr[v][c] = sz++;
		}
		v = tr[v][c];
	}
	in[v] = i;
	return;
}

pll cal(ll k){
	ll v = 0 , res = 0;
	for(ll j = 29 ; ~j && ~v ; j--){
		bool c = k & (1 << j);
		if(tr[v][!c] == -1){
			v = tr[v][c];
		} else {
			res += (1 << j);
			v = tr[v][!c];
		}
	}
	return {res , in[v]};
}

void del(){
	for(ll i = 0 ; i < sz ; i++) tr[i][0] = tr[i][1] = in[i] = -1;
	sz = 1;
	return;
}

ll a[maxn];
vector<plll> v;
vector<ll> u;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(tr , -1 , sizeof(tr));
	memset(in , -1 , sizeof(in));
	ll n , k , l , t = 0;
	cin>>n>>k;
	if(k == 0){
		cout<<n<<'\n';
		for(ll i = 1 ; i <= n ; i++) cout<<i<<' ';
		cout<<'\n';
		return 0;
	}
	for(ll j = 29 ; ~j ; j--){
		if(k & (1 << j)){
			l = j;
			break;
		}
		t += (1 << j);
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back({{a[i] & t , a[i] & (1 << l)} , i});
	}
	ll pr = -1;
	sort(all(v));
	ll ans = -1 , ind = -1 , in0 = -1;
	for(ll i = 0 ; i < n ; i++){
		ll at = v[i].first.first , al = v[i].first.second , j = v[i].second , r = a[j];
//		cout<<at<<' '<<al<<' '<<j<<' '<<r<<'\n';
		if(pr != at){
			ans += 1 + (ind != -1);
			u.push_back(in0);
			if(ind != -1) u.push_back(ind);
			ind = -1;
			in0 = j;
			del();
			pr = at;
		}
		if(al == 0){
			add(r , j);
		} else {
			pll p = cal(r);
			if(p.first >= k){
				ind = j;
				in0 = p.second;
			}
		}
	}
	ans += 1 + (ind != -1);
	u.push_back(in0);
	if(ind != -1) u.push_back(ind);
	if(ans < 2){
		cout<<"-1\n";
		return 0;
	}
	cout<<ans<<'\n';
	for(auto i : u){
		if(i == -1) continue;
		cout<<i + 1<<' ';
	}
	cout<<'\n';
	return 0;
}