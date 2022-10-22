#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t , n , m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if((n * m) % 2 == 0 && i == n - 1 && j >= m - 2 && (j + i) % 2 == 1){
					cout<<"B";
				}
				else if((i + j) % 2 == 0){
					cout<<"B";
				} else {
					cout<<"W";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}