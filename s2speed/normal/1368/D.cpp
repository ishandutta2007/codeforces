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

const ll z = 0;
ll a[200000] , ans[200000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , counter , h , sum = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		ans[i] = 0;
	}
	for(int i = 0 ; i < 20 ; i++){
		counter = 0;
		h = tav(2 , i);
		for(int j = 0 ; j < n ; j++){
			if((a[j] / h % 2) == 1){
				counter++;
			}
		}
		for(int j = 0 ; j < counter ; j++){
			ans[j] += h;
		}
	}
	for(int i = 0 ; i < n ; i++){
		sum += ans[i] * ans[i];
	}
	cout<<sum<<endl;
	return 0;
}