#include<bits/stdc++.h>
#include<algorithm>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		char h;
		vector<char> v;
		string ans;
		ll n , k;
		cin>>n>>k;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			v.push_back(h);
		}
		sort(v.begin() , v.end());
		ans += v[k - 1];
		if(ans[0] == v[0]){
			if(v[k] == v[n - 1]){
				for(int j = 2 ; j <= (n + k - 1) / k ; j++){
					ans += v[n - 1];
				}
			} else {
				for(int j = k ; j < n ; j++){
					ans += v[j];
				}
			}
		}
		cout<<ans<<endl;
		v.clear();
		ans.clear();
	}
	return 0;
}