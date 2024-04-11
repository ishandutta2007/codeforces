#include<iostream>

using namespace std;

int main(){
	int n , x[1000] , y[1000];
	int s;
	cin>>s>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>x[i]>>y[i];
	}
	for(int j = 0 ; j < n ; j++){
		for(int i = 0 ; i < n ; i++){
			if(x[i] < s && x[i] != 0){
				x[i] = 0;
				s += y[i];
			}
			if(s > 10000){
				cout<<"YES"<<endl;
				x[0] = -1;
				break;
			}
		}
		if(s > 10000){
			break;
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(x[i] != 0){
			break;
		}
		if(i == n - 1){
			cout<<"YES"<<endl;
			x[0] = -1;
		}
	}
	if(x[0] != -1){
		cout<<"NO"<<endl;
	}
	return 0;
}