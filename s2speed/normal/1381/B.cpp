#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 4e3 + 1;

set<ll> s;
vector<ll> v , p;
bool dp[MAX_N];

void solve(){
	ll n , counter = 1 , m;
	cin>>n>>m;
	for(int i = 1 ; i < 2 * n ; i++){
		ll inp;
		cin>>inp;
		if(inp > m){
			v.push_back(counter);
			counter = 1;
			m = inp;
		} else {
			counter++;
		}
	}
	v.push_back(counter);
	for(int i = 0 ; i <= 2 * n ; i++){
		dp[i] = false;
	}
	dp[0] = true;
	ll vs = v.size();
	s.insert(0);
	p.push_back(0);
	for(int i = 0 ; i < vs ; i++){
//		cout<<v[i]<<"\n";
		ll ps = p.size();
		for(int j = 0 ; j < ps ; j++){
			if(s.count(p[j] + v[i]) == 0){
//				cout<<p[j] + v[i]<<"\n";
				s.insert(p[j] + v[i]);
				dp[p[j] + v[i]] = true;
				p.push_back(p[j] + v[i]);
			}
		}
	}
	p.clear();
	s.clear();
	v.clear();
	if(dp[n]){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}