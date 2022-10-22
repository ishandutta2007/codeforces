#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

vector< pair<ll , ll> > ans;
set<ll> s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , h = 1 , q , k , o;
	cin>>n;
	for(int i = 0 ; i < 15 ; i++){
		s.insert(h);
		h *= 2;
	}
	h = 1;
	for(int i = 0 ; i < 15 ; i++){
		h *= 2;
		if(h > n){
			q = i;
			h /= 2;
			break;
		}
	}
	k = 1;
	for(int i = 0 ; i < q ; i++){
		for(int j = 0 ; j < h ; j++){
			if((j / k) % 2 == 0){
				ans.push_back( make_pair(j + 1, j + k + 1) );
			}
		}
		k *= 2;
	}
	o = h;
	if(o == n){
		ll as = ans.size();
		cout<<as<<"\n";
		for(int i = 0 ; i < as ; i++){
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}
		return 0;
	}
	while(s.count(n - o) == 0){
		ans.push_back( make_pair(o , n - (h - o)) );
		o--;
	}
	k = 1;
	for(int i = 0 ; i < 15 ; i++){
		if(n - o == k){
			q = i;
			break;
		}
		k *= 2;
	}
	k = 1;
	for(int i = 0 ; i < q ; i++){
		for(int j = o + 1 ; j <= n ; j++){
			if(((j - o - 1) / k) % 2 == 0){
				ans.push_back( make_pair(j, j + k) );
			}
		}
		k *= 2;
	}
	ll as = ans.size();
	cout<<as<<"\n";
	for(int i = 0 ; i < as ; i++){
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
	return 0;
}