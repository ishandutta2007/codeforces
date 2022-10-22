#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , n , s , k , a , helper[1001];
	cin>>t;
	for(int i = 0 ; i < 1001 ; i++){
		helper[i] = 0;
	}
	while(t > 0){
		cin>>n>>s>>k;
		helper[0] = 1;
		for(int i = 1 ; i < 1001 && i <= n ; i++){
			helper[i] = 0;
			if(s - i > 0){
				helper[i]++;
			}
			if(s + i <= n){
				helper[i]++;
			}
		}
		for(int i = 0 ; i < k ; i++){
			cin>>a;
			if(a > s){
				if(a - s <= 1000){
					helper[a - s]--;
				}
			} else {
				if(s - a <= 1000){
					helper[s - a]--;
				}
			}
		}
		for(int i = 0 ; i < 1001 ; i++){
			if(helper[i] > 0){
				cout<<i<<endl;
				break;
			}
		}
		t--;
	}
	return 0;
}