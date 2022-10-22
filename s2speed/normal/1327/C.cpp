#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , m , k , x[2][200] , a;
	cin>>m>>n>>k;
	for(int i = 0 ; i < k ; i++){
		cin>>x[0][i]>>x[1][i];
	}
	for(int i = 0 ; i < 2 * k ; i++){
		cin>>a;
	}
	cout<<m * n + m + n - 3<<endl;
	for(int i = 0 ; i < n - 1 ; i++){
		cout<<"L";
	}
	for(int i = 0 ; i < m - 1 ; i++){
		cout<<"U";
	}
	for(int i = 0 ; i < n ; i++){
		if(i % 2 == 0){
			for(int j = 0 ; j < m - 1; j++){
				cout<<"D";
			}
		} else{
			for(int j = 0 ; j < m - 1 ; j++){
				cout<<"U";
			}
		}
		if(i < n - 1) cout<<"R";
	}
	cout<<endl;
	return 0;
}