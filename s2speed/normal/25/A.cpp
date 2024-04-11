#include<iostream>

using namespace std;

int main(){
	int a , d[100] , answer = 0;
	cin>>a;
	for(int i = 0 ; i < a ; i++){
		cin>>d[i];
	}
	if(d[0] % 2 == d[1] % 2){
		for(int i = 2 ; i < a ; i++){
			if(d[0] % 2 != d[i] % 2){
				cout<<i + 1<<endl;
				break;
			}
		}
	}
	else{
		if(d[0] % 2 == d[2] % 2){
			cout<<"2"<<endl;
		}
		else{
			cout<<"1"<<endl;
		}
	}
	return 0;
}