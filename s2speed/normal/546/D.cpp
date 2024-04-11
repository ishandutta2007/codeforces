#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;

const ll MAX_N = 5e6 + 20;

ll pd[MAX_N] , dp[MAX_N] , l[MAX_N];
bool gh[MAX_N];
vector<ll> v;

void gh_build(){
	gh[0] = false;
	gh[1] = false;
	for(int i = 2 ; i < MAX_N ; i++){
		gh[i] = true;
	}
	for(int i = 2 ; i < MAX_N ; i++){
		if(gh[i]){
			l[i] = i;
			v.push_back(i);
			for(int j = 2 * i ; j < MAX_N ; j += i){
				gh[j] = false;
				l[j] = i;
			}
		}
	}
}

void pd_build(){
	pd[1] = 0;
	dp[1] = 0;
	for(int i = 2 ; i < MAX_N ; i++){
		pd[i] = pd[i / l[i]] + 1;
		dp[i] = dp[i - 1] + pd[i];
	}
}



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	gh_build();
	pd_build();
	ll t;
	cin>>t;
	while(t--){
		ll a , b;
		cin>>a>>b;
		ll ans = dp[a] - dp[b];
		cout<<ans<<'\n';
	}
	return 0;
}