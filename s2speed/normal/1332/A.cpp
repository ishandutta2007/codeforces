#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , a , b , c , d , x , y , x1 , x2 , y1 , y2 , xx , yy;
	cin>>t;
	while(t > 0){
		cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
		xx = x - a + b;
		yy = y - c + d;
		if(x >= x1 && x <= x2 && xx >= x1 && xx <= x2 && y >= y1 && y <= y2 && yy >= y1 && yy <= y2){
			if((x1 == x2 && a > 0) || (y1 == y2 && c > 0)){
				cout<<"NO"<<endl;
			} else {
				cout<<"YES"<<endl;
			}
		} else{
			cout<<"NO"<<endl;
		}
		t--;
	}
	return 0;
}