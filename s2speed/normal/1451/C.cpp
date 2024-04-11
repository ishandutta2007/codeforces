#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 1e6 + 20;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

ll cnt[26][2] , o[2];

void solve(){
    bool ans = true;
	ll n , k;
    string a , b;
    cin>>n>>k>>a>>b;
    for(int i = 0 ; i < 26 ; i++){
        cnt[i][0] = 0;
        cnt[i][1] = 0;
    }
    for(int i = 0 ; i < k ; i++){
        o[0] = 0;
        o[1] = 0;
    }
    for(int i = 0 ; i < n ; i++){
        cnt[a[i] - 'a'][0]++;
    }
    for(int i = 0 ; i < n ; i++){
        cnt[b[i] - 'a'][1]++;
    }
    for(int i = 25 ; i >= 0 ; i--){
        if(cnt[i][0] % k != cnt[i][1] % k){
            ans = false;
            break;
        }
        ll m = cnt[i][0] % k;
        o[0] += cnt[i][0];
        o[1] += cnt[i][1];
        if(o[0] > o[1]){
            ans = false;
        }
    }
    if(ans){
        cout<<"Yes\n";
    } else {
        cout<<"No\n";
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}