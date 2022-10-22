#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

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
	ll n , s1 , s2 , t1 , t2 , ans1 , ans2;
	cin>>n>>s1>>s2>>t1>>t2;
	ans1 = s1 * n + 2 * t1; ans2 = s2 * n + 2 * t2;
	if(ans1 < ans2){
		cout<<"First\n";
	} else if(ans1 > ans2){
		cout<<"Second\n";
	} else {
		cout<<"Friendship\n";
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}