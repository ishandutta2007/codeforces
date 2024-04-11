#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

set<ll> s;
vector<ll> v;
ll n , sum = 0 , ans = 0 , h , d = -1 , p = -1;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	v.push_back(0);
	s.insert(0);
	ll n , sum = 0 , ans = 0 , h , d = -1 , p = -1;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		cin>>h;
		sum += h;
		v.push_back(sum);
		if(s.find(sum) != s.end()){
			ans += (i - p - 1) * (i - p - 2) / 2;
			for( ; d < i ;){
				d++;
				if(v[d] == v[i]){
					ans -= (i - d - 2) * (i - d - 1) / 2;
					p = d;
					break;
				} else {
					s.erase(s.find(v[d]));
				}
			}
		} else{
			s.insert(sum);
		}
	}
	ans += (n - d) * (n - d - 1) / 2;
	cout<<ans<<endl;
	return 0;
}