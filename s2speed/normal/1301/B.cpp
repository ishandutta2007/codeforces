#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t;
	cin>>t;
	while(t > 0){
		ll n , a[100000] , m = 0 , ans , av[2];
		av[0] = 0;
		av[1] = 0;
		vector<ll> v;
		cin>>n>>a[0];
		if(a[0] != -1){
			av[1]++;
			av[0] += a[0];
		}
		for(int i = 1 ; i < n ; i++){
			cin>>a[i];
			if(a[i] != -1){
				av[1]++;
				av[0] += a[i];
			}
			if(a[i] != -1 && a[i - 1] != -1){
				m = max(m  , max(a[i] , a[i - 1]) - min(a[i] , a[i - 1]));
			} else if(a[i] == -1){
				if(a[i - 1] != -1){
					v.push_back(a[i - 1]);
				}
			} else if(a[i] != -1 && a[i - 1] == -1){
				v.push_back(a[i]);
			}
		}
		sort(v.begin() , v.end());
		if(v.size() == 0){
			if(av[1] == 0){
				av[1]++;
			}
			cout<<m<<" "<<av[0] / av[1]<<endl;
			t--;
			continue;
		}
		m = max(m , (v[v.size() - 1] - v[0] + 1) / 2);
		ans = (v[v.size() - 1] - v[0] + 1) / 2 + v[0];
		cout<<m<<" "<<ans<<endl;
		v.clear();
		t--;
	}
	return 0;
}