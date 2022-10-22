#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>

typedef long long int ll;
typedef double db;
typedef float fl;

using namespace std;

int main(){
	bool ch;
	ll t , n , a[2000][2] , x , y;
	cin>>t;
	while(t > 0){
		ch = false;
		x = 0;
		y = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i][0]>>a[i][1];
			if(ch == true){
				continue;
			}
			for(int j = i - 1 ; j >= 0 ; j--){
				if((a[i][0] > a[j][0] && a[i][1] < a[j][1]) || (a[i][1] > a[j][1] && a[i][0] < a[j][0])){
					ch = true;
					break;
				}
			}
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = i - 1 ; j >= 0 ; j--){
				if(a[j + 1][0] < a[j][0] || (a[j + 1][0] == a[j][0] && a[j + 1][1] < a[j][1])){
					swap(a[j + 1][0] , a[j][0]);
					swap(a[j + 1][1] , a[j][1]);
				}
			}
		}
		if(ch == true){
			cout<<"NO"<<endl;
			t--;
			continue;
		}
		cout<<"YES"<<endl;
		for(int i = 0 ; i < n ; i++){
			for( ; x < a[i][0] ; x++){
				cout<<"R";
			}
			for( ; y < a[i][1] ; y++){
				cout<<"U";
			}
		}
		cout<<endl;
		t--;
	}
	return 0;
}