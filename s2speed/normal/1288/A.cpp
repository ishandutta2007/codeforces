#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , n , d , x;
	cin>>t;
	while(t > 0){
		cin>>n>>d;
		if(n == 1 && d == 1){
			cout<<"YES"<<endl;
			t--;
			continue;
		} else if(n == 1 && d > 1){
			cout<<"NO"<<endl;
			t--;
			continue;
		}
		x = d / n - 1;
		if(x == -1){
			x++;
		} else if(x > n){
			x = n;
		}
		for(int i = x ; i <= n ; i++){
			if((d + i) / (i + 1) + i <= n){
				cout<<"YES"<<endl;
				break;
			}
			if(i == n){
				cout<<"NO"<<endl;
				break;
			}
		}
		t--;
	}
	return 0;
}