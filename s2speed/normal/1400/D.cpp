#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 3e3;

ll a[MAX_N] , cal[2][MAX_N] , d[MAX_N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){		
		ll n , ans = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			d[i] = 0;
		}
		for(int i = 0 ; i < n ; i++){
			cin>>a[i]; a[i]--;
			d[a[i]]++;
		}
		for(int i = 0 ; i < n - 3 ; i++){
			ll counter = 0;
			d[a[i]]--;
			for(int j = 0 ; j < n ; j++){
				cal[0][j] = d[j];
				cal[1][j] = 0;
			}
			for(int j = i + 1 ; j < n - 1 ; j++){
				cal[0][a[j]]--;
				counter -= cal[1][a[j]];
				if(a[i] == a[j]){
					ans += counter;
				}
				cal[1][a[j]]++;
				counter += (cal[1][a[j]] - 1) + (cal[0][a[j]] * cal[1][a[j]] - (cal[0][a[j]] + 1) * (cal[1][a[j]] - 1));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}