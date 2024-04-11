#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;

const int MAX_N = 3e3 + 20;

int a[MAX_N];

void solve(){
	int n , sum = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		sum += a[i];
	}
	for(int i = n ; i > 0 ; i--){
		int h = 0 , k , x = 0;
		if(sum % i != 0){
			continue;
		}
		k = sum / i;
		for(; x < n ; x++){
			h += a[x];
			if(h > k){
				break;
			}
			if(h == k){
				h = 0;
			}
		}
		if(x == n){
			cout<<n - i<<'\n';
			return;
		}
	}
	return;
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