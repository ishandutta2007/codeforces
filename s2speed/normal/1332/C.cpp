#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

bool p;

void change(){
	if(p == true){
		p = false;
	} else {
		p = true;
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	vector<ll> v;
	for(int i = 0 ; i < 26 ; i++){
		v.push_back(0);
	}
	set<ll> se;
	ll t , n , k , sum = 0 , counter = 0;
	string s;
	cin>>t;
	while(t > 0){
		cin>>n>>k>>s;
		for(int i = 0 ; i < n ; i++){
			se.insert(i);
		}
		for(int i = n - 1 ; i >= 0 ; i--){
			if(se.find(i) == se.end()){
				continue;
			}
			p = true;
			for(int j = i ; se.find(j) != se.end() ; ){
				counter++;
				v[s[j] - 97]++;
				se.erase(se.find(j));
				if(j < n - k){
					j += k;
				} else {
					j = n - 1 - j;
				}
			}
			sort(v.begin() , v.end());
			sum += counter - v[25];
			for(int j = 0 ; j < 26 ; j++){
				v[j] = 0;
			}
			counter = 0;
		}
		cout<<sum<<endl;
		sum = 0;
		se.clear();
		t--;
	}
	return 0;
}