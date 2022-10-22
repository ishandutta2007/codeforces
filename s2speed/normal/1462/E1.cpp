#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

const ll MAX_N = 2e5 + 20;

ll cnt[MAX_N] , ps[MAX_N];

void solve(){
	ll n , m = 3 , k = 2;
	ll ans = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cnt[i] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		int h;
		cin>>h; h--;
		cnt[h]++;
	}
	ps[0] = cnt[0];
	for(int i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + cnt[i];
	}
	int x = 0 , y = -k - 1;
	while(x < n){
		ll h = ps[x] , q;
		if(y >= 0){
			h -= ps[y];
		}
		q = h - cnt[x];
		h *= 1ll * (h - 1) * (h - 2); h /= 6;
		q *= 1ll * (q - 1) * (q - 2); q /= 6;
		h -= q;
		ans += h;
		x++; y++;
	}
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}