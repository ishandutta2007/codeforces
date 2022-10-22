#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 0;

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

void solve(){
    ll n , z = 0 , x = 0 , ans = 0;
	string s;
    cin>>s;
    n = s.size();
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '('){
            z++;
        }
        if(s[i] == '['){
            x++;
        }
        if(s[i] == ')'){
            if(z > 0){
                z--;
                ans++;
            }
        }
        if(s[i] == ']'){
            if(x > 0){
                x--;
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
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