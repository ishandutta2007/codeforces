#include<iostream>

using namespace std;

int main(){
	int a;
	cin>>a;
	for(int i = 0 ; i < a ; i++){
		if(i != 0){
			cout<<"that ";
		}
		if(i % 2 == 0){
			cout<<"I hate ";
		}
		else{
			cout<<"I love ";
		}
	}
	cout<<"it"<<endl;
	return 0;
}