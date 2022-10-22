#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	bool maz[3][100001];
	ll n , q  , a , b , counter = 0 , h;
	cin>>n>>q;
	for(int i = 1 ; i <= n ; i++){
		maz[2][i] = true;
		maz[1][i] = true;
	}
	while(q > 0){
		cin>>a>>b;
		if(a == 2){
			h = 1;
		} else {
			h = 2;
		}
		if(maz[a][b] == true){
			maz[a][b] = false;
			for(int i = b - 1 ; i <= b + 1 ; i++){
				if(i > 0 && i <= n){
					if(maz[h][i] == false){
						counter++;
					}
				}
			}
		}
		else if(maz[a][b] == false){
			maz[a][b] = true;
			for(int i = b - 1 ; i <= b + 1 ; i++){
				if(i > 0 && i <= n){
					if(maz[h][i] == false){
						counter--;
					}
				}
			}
		}
		if(counter == 0){
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
		q--;
	}
	return 0;
}