#include<iostream>

using namespace std;

int tav2(int n){
	int t = 1;
	for(int i = 0 ; i < n ; i++){
		t *= 2;
	}
	return t;
}

int main(){
	int n , a[15] , c = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i < tav2(n) ; i++){
		for(int j = 0 ; j < n ; j++){
			if((i / tav2(j)) % 2 == 0){
				c += a[j];
			}
			else{
				c -= a[j];
			}
		}
		if(c % 360 == 0){
			cout<<"Yes"<<endl;
			break;
		}
		else{
			c = 0;
		}
		if(i == tav2(n) - 1){
			cout<<"No"<<endl;
		}
	}
	return 0;
}