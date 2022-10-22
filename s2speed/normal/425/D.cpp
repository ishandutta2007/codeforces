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

const ll MAXN = 1e5 + 20 , md = 2000000357 , inf = 2e9 + 1;
// check problem statement

unordered_set<ll> s;
vector<ll> vx[MAXN] , vy[MAXN];
ll cnx[MAXN] , cny[MAXN] , fy[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnx , 0 , sizeof(cnx));
	memset(cny , 0 , sizeof(cny));
	memset(fy , 0 , sizeof(fy));
	ll n , ans = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll x , y;
		cin>>x>>y;
		vx[x].push_back(y); vy[y].push_back(x);
		cnx[x]++; cny[y]++;
		s.insert(1ll * MAXN * x + y);
	}
	for(ll i = 0 ; i <= 1e5 ; i++){
		sort(all(vx[i])); sort(all(vy[i]));
	}
	for(ll x = 0 ; x <= 1e5 ; x++){
		ll vs = vx[x].size();
		for(ll i = 0 ; i < vs ; i++){
			ll y = vx[x][i];
			if(cny[y] >= cnx[x]){
				for(int j = i + 1 ; j < vs ; j++){
					ll y2 = vx[x][j] , x2 = x + y2 - y;
					bool ch = true;
					ch &= s.count(1ll * x2 * MAXN + y2);
					ch &= s.count(1ll * x2 * MAXN + y);
					ans += ch;
				}
			} else {
				ll ys = vy[y].size();
				for(ll j = fy[y] + 1 ; j < ys ; j++){
					ll x2 = vy[y][j] , y2 = y + x2 - x;
					bool ch = true;
					ch &= s.count(1ll * x * MAXN + y2);
					ch &= s.count(1ll * x2 * MAXN + y2);
					ans += ch;
				}
			}
			cnx[x]--; cny[y]--;
			fy[y]++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/