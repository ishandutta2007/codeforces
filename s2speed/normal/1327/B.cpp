#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll T , n , k , a;
	cin>>T;
	while(T > 0){
		bool t = false;
		set<ll> s , z;
		vector<ll> v;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			z.insert(i + 1);
		}
		for(int i = 0 ; i < n ; i++){
			cin>>k;
			t = false;
			for(int j = 0 ; j < k ; j++){
				cin>>a;
				if(t == false){
					if(s.find(a) == s.end()){
						t = true;
						z.erase(z.find(a));
						s.insert(a);
					}
				}
			}
			if(t == false){
				v.push_back(i + 1);
			}
		}
		if(v.size() == 0){
			cout<<"OPTIMAL"<<endl;
		} else {
			cout<<"IMPROVE"<<endl;
			cout<<v[0]<<" ";
			for(int i = 0 ; i < n ; i++){
				if(s.find(i + 1) == s.end()){
					cout<<i + 1<<endl;
					break;
				}
			}
		}
		v.clear();
		z.clear();
		s.clear();
		T--;
	}
	return 0;
}