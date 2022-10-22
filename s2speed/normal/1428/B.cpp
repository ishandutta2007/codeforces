#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 3e5;

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

bool ans[MAX_N];

void solve(){
	bool clo = false , cocl = false;
	ll n , cnt = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ans[i] = false;
	}
	string s;
	cin>>s;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '-'){
			ans[i] = true;
			ans[(i + 1) % n] = true;
		} else if(s[i] == '>'){
			clo = true;
		} else {
			cocl = true;
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(ans[i] == true){
			cnt++;
		} else {
			if((s[i] == '>' && cocl == false) || (s[i] == '<' && clo == false)){
				cnt++;
			}
		}
	}
	cout<<cnt<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}