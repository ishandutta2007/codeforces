#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	bool check;
	ll counter;
	int t , n , a[100000];
	cin>>t;
	while(t > 0){
		check = false;
		counter = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
		}
		for(int i = 0 ; i < n - 1 ; i++){
			counter += a[i];
			if(counter <= 0){
				cout<<"NO"<<endl;
				check = true;
				break;
			}
		}
		if(check == true){
			t--;
			continue;
		}
		counter = 0;
		for(int i = n - 1 ; i > 0 ; i--){
			counter += a[i];
			if(counter <= 0){
				cout<<"NO"<<endl;
				check = true;
				break;
			}
		}
		if(check == true){
			t--;
			continue;
		}
		cout<<"YES"<<endl;
		t--;
	}
	return 0;
}