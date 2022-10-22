#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 2e6 + 20;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

bool gh[MAX_N];

void prime(){
	gh[0] = false;
	gh[1] = false;
	for(int i = 2 ; i < MAX_N ; i++){
		gh[i] = true;
	}
	for(int i = 2 ; i < MAX_N ; i++){
		if(gh[i]){
			for(int j = 2 * i ; j < MAX_N ; j += i){
				gh[j] = false;
			}
		}
	}
}
ll a[1020];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	prime();
	bool bp = false;
	ll n , ans = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		ans += (a[i] == 1);
		if(a[i] != 1 && gh[a[i] + 1]){
			bp = true;
		}
	}
	ans += bp;
	if(ans >= 2){
		cout<<ans<<'\n';
		for(int i = 0 ; i < n ; i++){
			if(a[i] == 1){
				cout<<"1 ";
			}
			else if(bp && gh[a[i] + 1]){
				cout<<a[i]<<' ';
				bp = false;
			}
		}
		cout<<'\n';
		return 0;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			if(gh[a[i] + a[j]]){
				cout<<"2\n";
				cout<<a[i]<<' '<<a[j]<<'\n';
				return 0;
			}
		}
	}
	cout<<"1\n";
	cout<<a[0]<<'\n';
	return 0;
}