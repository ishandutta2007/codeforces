#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 2e5;

set<ll> s;
ll a[MAX_N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , ans = 0 , sum = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i < n ; i++){
		ll inp;
		inp = a[i];
		sum += inp;
		if(s.count(sum) == 1 || sum == 0){
			ans++;
			s.clear();
			sum = 0;
			i--;
		} else {
			s.insert(sum);
		}
	}
	cout<<ans<<"\n";
	return 0;
}