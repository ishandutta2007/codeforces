#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , n , h , counter , sum;
	cin>>t;
	while(t > 0){
		counter = 0;
		sum = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			sum += h;
			if(h == 0){
				counter++;
				sum++;
			}
		}
		if(sum == 0){
			counter++;
		}
		cout<<counter<<endl;
		t--;
	}
	return 0;
}