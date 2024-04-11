#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , n , m , p , h , ans[26] , lm[26];
	string s;
	vector<ll> f;
	cin>>t;
	while(t > 0){
		cin>>n>>m>>s;
		for(int i = 0 ; i < 26 ; i++){
			ans[i] = 0;
			lm[i] = 0;
		}
		for(int i = 0 ; i < m ; i++){
			cin>>p;
			f.push_back(p);
		}
		sort(f.begin() , f.end());
		p = 0;
		for(int i = 0 ; i <= m ; i++){
			h = p;
			if(i < m) p = f[i];
			if(i == m) p = n;
			for(int j = 0 ; j < 26 ; j++){
				ans[j] += lm[j];
			}
			for(int j = h ; j < p ; j++){
				ans[s[j] - 97]++;
				lm[s[j] - 97]++;
			}
		}
		for(int i = 0 ; i < 26 ; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		f.clear();
		t--;
	}
}