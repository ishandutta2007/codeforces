#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

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

ll ans[10000];
bool mark[10000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , p = 1;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		mark[i] = false;
	}
	for(int i = 2 ; i <= n ; i++){
		ll d1 , d2;
		cout<<"? "<<p<<" "<<i<<"\n";
		cout.flush();
		cin>>d1;
		cout<<"? "<<i<<" "<<p<<"\n";
		cout.flush();
		cin>>d2;
		if(d1 > d2){
			ans[p - 1] = d1;
			mark[d1 - 1] = true;
			p = i;
		} else {
			ans[i - 1] = d2;
			mark[d2 - 1] = true;
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(mark[i] == false){
			ans[p - 1] = i + 1;
			break;
		}
	}
	cout<<"! ";
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}