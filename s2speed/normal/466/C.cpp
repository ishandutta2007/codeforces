#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 5e5;

ll a[MAX_N] , cal[MAX_N];
vector<ll> f[2];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , sum = 0 , ans = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i]; sum += a[i];
	}
	if(sum % 3 != 0){
		cout<<0<<"\n";
		return 0;
	}
	if(sum == 0){
		ll counter = 0;
		for(int i = 0 ; i < n - 1 ; i++){
			sum += a[i];
			if(sum == 0){
				counter++;
			}
		}
		cout<<counter * (counter - 1) / 2<<"\n";
		return 0;
	}
	ll hs = 0;
	for(int i = 0 ; i < n ; i++){
		hs += a[i];
		if(hs == sum / 3){
			f[0].push_back(i);
		} else if(hs == (sum / 3) * 2){
			f[1].push_back(i);
		}
	}
	ll f0s = f[0].size() , f1s = f[1].size() , y = f1s;
	for(int i = f0s - 1 ; i >= 0 ; i--){
		while(y > 0){
			if(f[1][y - 1] > f[0][i]){
				y--;
			} else {
				break;
			}
		}
		cal[i] = f1s - y;
		ans += cal[i];
	}
	cout<<ans<<"\n";
	return 0;
}