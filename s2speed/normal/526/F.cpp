#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 5e5 + 20 , md = 1e9 + 7;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

ll a[MAX_N] , ans = 0 , mn[MAX_N] , mx[MAX_N] , cnt[MAX_N] , n;

void solve(int l , int r){
	if(l >= r - 1){
		if(l == r - 1) ans++;
		return;
	}
	int m = (r + l) / 2;
	solve(l , m); solve(m , r);
	mn[m - 1] = a[m - 1]; mx[m - 1] = a[m - 1];
	for(int i = m - 2 ; i >= l ; i--){
		mn[i] = min(mn[i + 1] , a[i]);
		mx[i] = max(mx[i + 1] , a[i]);
	}
	mn[m] = a[m]; mx[m] = a[m];
	for(int i = m + 1 ; i < r ; i++){
		mn[i] = min(mn[i - 1] , a[i]);
		mx[i] = max(mx[i - 1] , a[i]);
	}
	for(int i = l ; i < m ; i++){
		ll h = mx[i] - mn[i];
		if(i + h >= m && i + h < r){
			if(mn[i + h] > mn[i] && mx[i + h] < mx[i]) ans++;
		}
	}
	for(int i = m ; i < r ; i++){
		ll h = mx[i] - mn[i];
		if(i - h < m && i - h >= l){
			if(mn[i] < mn[i - h] && mx[i] > mx[i - h]) ans++;
		}
	}
	ll x = m , y = m;
	for(int i = m - 1 ; i >= l ; i--){
		while(mn[x] > mn[i] && x < r){
			if(x >= y){
				cnt[mx[x] - (x - m + 1)]++;
			}
			x++;
		}
		while(mx[y] < mx[i] && y < r){
			if(y < x){
				cnt[mx[y] - (y - m + 1)]--;
			}
			y++;
		}
		ans += cnt[mn[i] + m - i - 1];
	}
	while(y < x){
		cnt[mx[y] - (y - m + 1)]--;
		y++;
	}
	x = m - 1; y = m - 1;
	for(int i = m ; i < r ; i++){
		while(x >= l){
			if(mn[x] > mn[i]){
				if(x <= y){
					cnt[mx[x] - m + x]++;
				}
				x--;
			} else {
				break;
			}
		}
		while(y >= l){
			if(mx[y] < mx[i]){
				if(y > x){
					cnt[mx[y] - m + y]--;
				}
				y--;
			} else {
				break;
			}
		}
		ans += cnt[mn[i] + i - m];
	}
	while(y > x){
		cnt[mx[y] - m + y]--;
		y--;
	}
	return;
}

/*
4
1 4 2 3 3 2 4 1
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	fill(cnt , cnt + n , 0);
	for(int i = 0 ; i < n ; i++){
		int v , u;
		cin>>v>>u; v--;
		a[v] = u;
	}
	solve(0 , n);
	cout<<ans<<'\n';
	return 0;
}