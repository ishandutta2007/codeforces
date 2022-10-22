#include<iostream>

using namespace std;

int main(){
	int a , n , m;
	for(int i = 1 ; i < 6 ; i++){
		for(int j = 1 ; j < 6 ; j++){
			cin>>a;
			if(a == 1){
				n = i;
				m = j;
			}
		}
	}
	if(n == 4){
		n = 2;
	}
	if(n == 5){
		n = 1;
	}
	if(m == 4){
		m = 2;
	}
	if(m == 5){
		m = 1;
	}
	if(n + m == 2){
		cout<<"4"<<endl;
	}
	else if(n + m == 3){
		cout<<"3"<<endl;
	}
	else if(n + m == 4){
		cout<<"2"<<endl;
	}
	else if(n + m == 5){
		cout<<"1"<<endl;
	}
	else if(n + m == 6){
		cout<<"0"<<endl;
	}
	return 0;
}