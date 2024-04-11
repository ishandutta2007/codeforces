#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , a[100001] , c = 1;
	cin>>n;
	for(int i = 2 ; i <= n ; i++){
		a[i] = 0;
	}
	for(int i = 2 ; i <= n ; i++){
		if(a[i] == 0){
			a[i] = c;
			for(int j = i * 2 ; j <= n ; j += i){
				a[j] = c;
			}
			c++;
		}
	}
	for(int i = 2 ; i <= n ; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}