#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>

typedef long long int ll;
typedef double db;
typedef float fl;

using namespace std;

int main(){
	ll t , n;
	vector<ll> v;
	cin>>t;
	while(t > 0){
		cin>>n;
		ll s = sqrt(n);
		for(int i = 2 ; i <= s && v.size() != 3 ; i++){
			if(n % i == 0){
				v.push_back(i);
				n /= i;
			}
			if(v.size() == 2){
				if(n != v[0] && v[1] != n){
					v.push_back(n);
				}
				else {
					v.clear();
					break;
				}
			}
		}
		if(v.size() == 3){
			cout<<"YES"<<endl;
			cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		v.clear();
		t--;
	}
	return 0;
}